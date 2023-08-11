#pragma once

#include "IChessPiece.hpp"

class jBishop : public IChessPiece
{
public:
	jBishop(Colour _color, Vec2 _pos);
	virtual ~jBishop();

	bool isMoveValid(Vec2 toPosition);
};