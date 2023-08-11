#include "Rook.h"

jRook::jRook(Colour _color, Vec2 _pos)
{
	m_Type = "R";
	m_Color = _color;
	m_Position = _pos;
}

jRook::~jRook()
{
}

bool jRook::isMoveValid(Vec2 toPosition)
{
	return true;
}
