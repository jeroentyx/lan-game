

Open Client.Sln
Set Project as Client to compile Client.cpp
and Set Project as Server to compile Server.cpp

Go to x64 DEBUG and Run Server.exe
Insert Port number

Open the Client.exe in the x64 directory
And Copy the IP address and Port number from the Server.exe

Run the test

handshaking

To Establish connection

Server will display the port number and the ip address

User will see the displayed port number and ip address

Then type in the client console,
Client will verify the port and ip address by sending a request
to server

Once verified with the server, server will send with a ACK

Once Received, Client will send username
with [/x01] of 1 byte and 1 of 4 bytes and user length of 4 byte , then the string

Both the client and server is non blocking
and the client put std::cin into another thread, so it can receive and send message at the same time

[I ask in class during 2/24/2023] we don't have to strictly follow the protocol because 
(e) the client don't hold the game id

for my inviting, show users and move piece, I didn't follow strictly the protocol

