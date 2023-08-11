#pragma once

#include "Board.hpp"
#include "IChessPiece.hpp"
#include <iostream>

namespace Chess
{
	Vec2 ConvertChessToCartesian(std::string _move, Colour _color);
	bool isMoveValid(std::string _input1, std::string _input2, Colour _color);
}