#pragma once

#include "IChessPiece.hpp"

class jKnight : public IChessPiece
{
public:
	jKnight(Colour _color, Vec2 _pos);
	virtual ~jKnight();

	bool isMoveValid(Vec2 toPosition);
};
