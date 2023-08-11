#pragma once

#include "IChessPiece.hpp"
#include <iostream>

class jPawn : public IChessPiece
{
public:
	jPawn(Colour _color, Vec2 _pos);
	virtual ~jPawn();

	bool isMoveValid(Vec2 toPosition);
private:
	bool m_IsDoubleJumpValid;
};
