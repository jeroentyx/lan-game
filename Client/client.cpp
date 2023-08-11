#include "../Server/CNetwork.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <sstream>

std::atomic<bool> networkshutdown(false);
std::mutex sMutex;

bool firstIteration = true;
bool secondIteration = true;

struct InputThread
{
	InputThread(CSocket& s_) : s(s_) {}
	CSocket& s;
	std::string username;

	void operator()()
	{
		std::string msg;
		while (!networkshutdown.load() && std::getline(std::cin, msg))
		{
			if (msg == "quit")
			{
				std::unique_lock<std::mutex>(sMutex);
				char command = 0;
				s.Send(&command, sizeof(command));
				networkshutdown.store(true);
			}
			else
			{
				if (secondIteration)
				{
					//pack it into protocol for registering users
					char command = 1;
					int len = (int)msg.size();
					char* buffer = new char[len + (size_t)9];
					buffer[0] = 1;
					u_long numOfParams = 1;
					*(int*)(buffer + 1) = htonl((u_long)numOfParams); //no of parameter
					*(int*)(buffer + 5) = htonl((u_long)len); //user length
					memcpy(buffer + 9, msg.c_str(), len); //username

					username = std::string(msg.c_str()); //save username

					s.Send(buffer, (int)(9 + len));

					delete[] buffer;
				}
				else
				{
					std::string list = std::string("list users");
					std::string play = std::string("play");
					size_t foundList = msg.find(list);
					size_t foundPlay = msg.find(play);
					if (foundList != std::string::npos)
					{
						char command = 2;
						s.Send(&command, sizeof(command));
					}
					else
					{
						s.Send(msg.c_str(), msg.length() + 1);
					}
				}
			}
		}
	}
};

void InitializeFDSets(fd_set& read, fd_set& except, InputThread& it)
{
	FD_ZERO(&read);
	FD_ZERO(&except);

	if (it.s.m_socket != INVALID_SOCKET)
	{
		FD_SET(it.s.m_socket, &read);
		FD_SET(it.s.m_socket, &except);
	}

}
int main()
{
	std::string port_string;
	std::cout << "Please enter port: ";
	std::getline(std::cin, port_string);

	std::string ip_addr;
	std::cout << "Please enter ip: ";
	std::getline(std::cin, ip_addr);

	CWSAData wsaData;
	wsaData.Init();

	CAddrInfo hints;
	hints.Setup(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	CAddrInfo info;
	hints.GetAddressInfo(ip_addr.c_str(), port_string.c_str(), info);

	CSocket connectSocket(info);
	connectSocket.ConnectSocket(info);
	u_long nNoBlock = 1;
	if (ioctlsocket(connectSocket.m_socket, FIONBIO, &nNoBlock))
	{
		int err = WSAGetLastError();
		std::cout << "ioctlsocket() error " << err;
		system("Pause");
	}
	std::cout << "Connected!\n";
	InputThread connection(connectSocket);

	// Create a worker thread just to wait for cin
	std::thread worker(connection);

	for (;;)
	{
		{
			std::unique_lock<std::mutex>(sMutex);
			if (networkshutdown.load())
				break;
		}
		char buff[BUFSIZ];
		int bytes_read;
		SecureZeroMemory(buff, BUFSIZ);
		std::string s;
		std::string msg;

		fd_set read, WriteFDs, except;
		FD_ZERO(&WriteFDs);
		InitializeFDSets(read, except, connection);

		int result = select(0, &read, &except, &WriteFDs, nullptr);

		if (result == SOCKET_ERROR)
		{
			std::cout << "ERROR IN SELECT: " << WSAGetLastError();
			system("Pause");
		}

		if (result > 0)
		{
			if (FD_ISSET(connectSocket.m_socket, &read))
			{
				bytes_read = connectSocket.Receive(buff, BUFSIZ);
				if (!firstIteration)
				{
					secondIteration = false;
				}
				//after checking for duplicate player name 
				//server will send back, so it is no longer first iteration
				firstIteration = false;

				if (bytes_read == 0 || bytes_read == SOCKET_ERROR)
					break; // Server closed

				s.append(buff, bytes_read - 1);
				std::cout << s;
				FD_CLR(connectSocket.m_socket, &read);
			}
		}
	}
	networkshutdown.store(true);
	worker.join();
	return 0;
}
