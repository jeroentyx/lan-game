#include "ChessHelper.h"

namespace Chess
{

	Vec2 ConvertChessToCartesian(std::string _move, Colour _color)
	{
		Vec2 moveToPosition;

		if (_color == Colour::WHITE)
		{

			moveToPosition.m_X = (int)_move[0] - 97;
			moveToPosition.m_Y = atoi(&_move[1]) - 1;

		}
		else
		{
			//Doing manual inputs because i don't know the algorithm
			//TODO: look up the algorithm to compute for black's moves
			moveToPosition.m_X = (int)_move[0] - 97;
			moveToPosition.m_Y = atoi(&_move[1]) - 1;

			switch (moveToPosition.m_X)
			{
			case 0:
				moveToPosition.m_X = 7;
				break;
			case 1:
				moveToPosition.m_X = 6;
				break;
			case 2:
				moveToPosition.m_X = 5;
				break;
			case 3:
				moveToPosition.m_X = 4;
				break;
			case 4:
				moveToPosition.m_X = 3;
				break;
			case 5:
				moveToPosition.m_X = 2;
				break;
			case 6:
				moveToPosition.m_X = 1;
				break;
			case 7:
				moveToPosition.m_X = 0;
				break;
			}

			switch (moveToPosition.m_Y)
			{
			case 0:
				moveToPosition.m_Y = 7;
				break;
			case 1:
				moveToPosition.m_Y = 6;
				break;
			case 2:
				moveToPosition.m_Y = 5;
				break;
			case 3:
				moveToPosition.m_Y = 4;
				break;
			case 4:
				moveToPosition.m_Y = 3;
				break;
			case 5:
				moveToPosition.m_Y = 2;
				break;
			case 6:
				moveToPosition.m_Y = 1;
				break;
			case 7:
				moveToPosition.m_Y = 0;
				break;
			}
		}

		return moveToPosition;
	}

	bool isMoveValid(std::string _input1, std::string _input2, Colour _color)
	{
		Vec2 fromPosition = ConvertChessToCartesian(_input1, _color);
		Vec2 toPosition = ConvertChessToCartesian(_input2, _color);

		if (fromPosition.m_X < 0 || fromPosition.m_X > 7 || fromPosition.m_Y < 0 || fromPosition.m_Y > 7)
		{
			//out of bound
		}
		else if (toPosition.m_X < 0 || toPosition.m_X > 7 || toPosition.m_Y < 0 || toPosition.m_Y > 7)
		{
			//out of bound
		}
		else
		{
			return true;
		}
		return false;
	}
}