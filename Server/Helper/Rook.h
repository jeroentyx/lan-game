#pragma once

#include "IChessPiece.hpp"

class jRook : public IChessPiece
{
public:
	jRook(Colour _color, Vec2 _pos);
	virtual ~jRook();

	bool isMoveValid(Vec2 toPosition);
};