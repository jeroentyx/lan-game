#include "Bishop.h"

jBishop::jBishop(Colour _color, Vec2 _pos)
{
	m_Type = "B";
	m_Color = _color;
	m_Position = _pos;
}

jBishop::~jBishop()
{
}

bool jBishop::isMoveValid(Vec2 toPosition)
{
	return true;
}
