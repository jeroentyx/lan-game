#pragma once

#include <string>
#include "vec2.hpp"
#include <cctype>
#include <iostream>
#include <algorithm>
#include "../Position.h"
class ChessBoard;


class IChessPiece
{
public:
	IChessPiece();
	virtual ~IChessPiece();

	void Render();
	std::string GetString();
	void SetPosition(Vec2 _toPosition);
	Vec2 GetPosition();
	Colour GetColor();
	virtual bool isMoveValid(Vec2 toPosition) = 0;

	std::string m_Type;
	Colour m_Color;
	Vec2 m_Position;
};