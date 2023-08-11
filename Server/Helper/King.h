#pragma once

#include "IChessPiece.hpp"
class jKing : public IChessPiece
{
public:
	jKing(Colour _color, Vec2 _pos);

	virtual ~jKing();

	bool isMoveValid(Vec2 toPosition);
};
