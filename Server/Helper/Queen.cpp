#include "Queen.h"

jQueen::jQueen(Colour _color, Vec2 _pos)
{
	m_Type = "Q";
	m_Color = _color;
	m_Position = _pos;
}

jQueen::~jQueen()
{
}

bool jQueen::isMoveValid(Vec2 toPosition)
{
	return true;
}
