#include "IChessPiece.hpp"

IChessPiece::IChessPiece() : m_Type(""), m_Color(Colour::BLACK)
{
}

IChessPiece::~IChessPiece()
{
}

void IChessPiece::Render()
{
	if (m_Color == Colour::BLACK)
	{

		//Check if it is black, if true, print it in Upper Case
		std::cout << " ";
		std::cout << m_Type;
	}
	else
	{
		//Check if it is White, if true, print it in lower Case
		std::cout << " ";
		std::transform(m_Type.begin(), m_Type.end(), m_Type.begin(), [](unsigned char c) {return std::tolower(c); });
		std::cout << m_Type;

	}
}

std::string IChessPiece::GetString()
{
	std::stringstream ss;
	if (m_Color == Colour::BLACK)
	{

		//Check if it is black, if true, print it in Upper Case
		ss << " ";
		ss << m_Type;
	}
	else
	{
		//Check if it is White, if true, print it in lower Case
		ss << " ";
		std::transform(m_Type.begin(), m_Type.end(), m_Type.begin(), [](unsigned char c) {return std::tolower(c); });
		ss << m_Type;

	}

	return ss.str();
}

void IChessPiece::SetPosition(Vec2 _toPosition)
{
	m_Position = _toPosition;
}

Vec2 IChessPiece::GetPosition()
{
	return m_Position;
}

Colour IChessPiece::GetColor()
{
	return m_Color;
}
