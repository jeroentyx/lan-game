#include "King.h"
#pragma once

jKing::jKing(Colour _color, Vec2 _pos)
{
	m_Type = "K";
	m_Color = _color;
	m_Position = _pos;
}

jKing::~jKing()
{
}

bool jKing::isMoveValid(Vec2 toPosition)
{
	return true;
}
