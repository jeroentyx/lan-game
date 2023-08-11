
#include "Knight.h"

jKnight::jKnight(Colour _color, Vec2 _pos)
{
	m_Type = "N";
	m_Color = _color;
	m_Position = _pos;
}

jKnight::~jKnight()
{
}

bool jKnight::isMoveValid(Vec2 toPosition)
{
	return true;
}
