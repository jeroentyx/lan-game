#pragma once

#include "Square.h"
#include "vec2.hpp"
#include <cctype>
#include <iostream>


class ChessBoard
{
public:
	ChessBoard();

	virtual ~ChessBoard();

	void Render();
	std::string GetBoard();
	bool MoveChess(Vec2 _fromPosition,Vec2 _toPosition);
	IChessPiece* GetChess(Vec2 _ChessPosition);

private:
	Square m_Board[8][8];

	void Init();
	bool isWithinBoard(Vec2 _pos);
};
