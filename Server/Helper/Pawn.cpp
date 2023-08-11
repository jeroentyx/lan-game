#include "Pawn.h"
#include "Board.hpp"

extern ChessBoard g_Board;

jPawn::jPawn(Colour _color, Vec2 _pos)
{
	m_Type = "P";
	m_Color = _color;
	m_Position = _pos;
	m_IsDoubleJumpValid = true;
}

jPawn::~jPawn()
{
}

bool jPawn::isMoveValid(Vec2 toPosition)
{
	return true;
}