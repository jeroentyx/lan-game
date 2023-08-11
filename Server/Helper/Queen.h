#pragma once

#include "IChessPiece.hpp"

class jQueen : public IChessPiece
{
public:
	jQueen(Colour _color, Vec2 _pos);
	virtual ~jQueen();

	bool isMoveValid(Vec2 toPosition);

};