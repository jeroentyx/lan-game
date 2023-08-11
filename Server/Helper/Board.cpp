
#include "Board.hpp"
#include "IChessPiece.hpp"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"


ChessBoard::ChessBoard()
{
	Init(); //Function to init all the chess pieces (in the starting)
}

ChessBoard::~ChessBoard()
{
	//for (int i = 0; i < 8; i++)
	//{
	//	for (int j = 0; j < 8; j++)
	//	{
	//		Vec2 Pos = Vec2{ i, j };
	//		m_Board[Pos.m_Y][Pos.m_X].ClearSquare();
	//	}
	//}
}

//Function Render: To be called when client type "Print board"
void ChessBoard::Render()
{
	int endOfRowNumber = 1;
	std::cout << "   ";
	for (int col = 7; col >= 0; col--)
	{
		char lowerCase = (char)(col + 97);
		char upperCase = (char)(toupper(lowerCase));
		std::cout << "  " << upperCase << "  ";
	}
	std::cout << std::endl;
	for (int row = 7; row >= 0; row--)
	{
		std::cout << "   ";
		for (int col = 0; col < 8; col++)
		{
			std::cout << "-----";
		}
		std::cout << "-" << std::endl;


		std::cout << row + 1 << "  ";
		for (int col = 0; col < 8; col++)
		{
			std::cout << "| ";
			//Check if curr chess piece is not a nullptr, draw it
			IChessPiece* curr = m_Board[row][col].GetSelectedPiece();
			if (curr != nullptr)
			{
				curr->Render();
			}
			else
			{
				std::cout << "  ";
			}
			std::cout << " ";
		}
		std::cout << "|"; //draw divider for end-of-row
		std::cout << " " << endOfRowNumber << std::endl;;
		endOfRowNumber += 1;
	}
	std::cout << "   ";
	for (int col = 0; col < 8; col++)
	{
		std::cout << "-----";
	}
	std::cout << "-" << std::endl;

	std::cout << "   ";
	for (int col = 0; col < 8; col++)
	{

		std::cout << "  " << (char)(col + 97) << "  ";
	}
	std::cout << std::endl << std::endl;
}

std::string ChessBoard::GetBoard()
{
	std::stringstream ss;
	int endOfRowNumber = 1;
	ss << "   ";
	for (int col = 7; col >= 0; col--)
	{
		char lowerCase = (char)(col + 97);
		char upperCase = (char)(toupper(lowerCase));
		ss << "  " << upperCase << "  ";
	}
	ss << std::endl;
	for (int row = 7; row >= 0; row--)
	{
		ss << "   ";
		for (int col = 0; col < 8; col++)
		{
			ss << "-----";
		}
		ss << "-" << std::endl;


		ss << row + 1 << "  ";
		for (int col = 0; col < 8; col++)
		{
			ss << "| ";
			//Check if curr chess piece is not a nullptr, draw it
			IChessPiece* curr = m_Board[row][col].GetSelectedPiece();
			if (curr != nullptr)
			{
				ss << curr->GetString();
			}
			else
			{
				ss << "  ";
			}
			ss << " ";
		}
		ss << "|"; //draw divider for end-of-row
		ss << " " << endOfRowNumber << std::endl;;
		endOfRowNumber += 1;
	}
	ss << "   ";
	for (int col = 0; col < 8; col++)
	{
		ss << "-----";
	}
	ss << "-" << std::endl;

	ss << "   ";
	for (int col = 0; col < 8; col++)
	{

		ss << "  " << (char)(col + 97) << "  ";
	}
	ss << std::endl << std::endl;
	return ss.str();
}

bool ChessBoard::MoveChess(Vec2 _fromPosition, Vec2 _toPosition)
{
	bool isMoveCompleted = false;

	IChessPiece* fromPiece = m_Board[_fromPosition.m_Y][_fromPosition.m_X].GetSelectedPiece();



	if (fromPiece != nullptr && fromPiece->isMoveValid(_toPosition) && isWithinBoard(_toPosition))
	{
		fromPiece->SetPosition(_toPosition);
		m_Board[_toPosition.m_Y][_toPosition.m_X].SetChessPiece(fromPiece);

		Vec2 chessPiecePos = Vec2{ _toPosition.m_X,_toPosition.m_Y };

		if (fromPiece->m_Type == "N" || fromPiece->m_Type == "n")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jKnight(fromPiece->GetColor(), chessPiecePos));
		}
		else if (fromPiece->m_Type == "R" || fromPiece->m_Type == "r")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jRook(fromPiece->GetColor(), chessPiecePos));
		}
		else if (fromPiece->m_Type == "B" || fromPiece->m_Type == "b")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jBishop(fromPiece->GetColor(), chessPiecePos));
		}
		else if (fromPiece->m_Type == "Q" || fromPiece->m_Type == "q")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jQueen(fromPiece->GetColor(), chessPiecePos));
		}
		else if (fromPiece->m_Type == "K" || fromPiece->m_Type == "k")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jKing(fromPiece->GetColor(), chessPiecePos));
		}
		else if (fromPiece->m_Type == "P" || fromPiece->m_Type == "p")
		{
			m_Board[chessPiecePos.m_Y][chessPiecePos.m_X].SetChessPiece(new jPawn(fromPiece->GetColor(), chessPiecePos));
		}

		m_Board[_fromPosition.m_Y][_fromPosition.m_X].ClearSquare();
		isMoveCompleted = true;
	}
	return isMoveCompleted;
}

IChessPiece* ChessBoard::GetChess(Vec2 _ChessPosition)
{
	return m_Board[_ChessPosition.m_Y][_ChessPosition.m_X].GetSelectedPiece();
}

void ChessBoard::Init()
{
	//Set Pawns
	for (int col = 0; col < 8; col++)
	{
		Vec2 bPawnPos = Vec2{ col, 6 }; //need check if data is send over
		m_Board[bPawnPos.m_Y][bPawnPos.m_X].SetChessPiece(new jPawn(Colour::BLACK, bPawnPos));

		Vec2 wPawnPos = Vec2{ col, 1 }; //need check if data is send over
		m_Board[wPawnPos.m_Y][wPawnPos.m_X].SetChessPiece(new jPawn(Colour::WHITE, wPawnPos));
	}

	//Set Rooks
	Vec2 whiteRookPos = Vec2{ 0,0 };
	m_Board[whiteRookPos.m_Y][whiteRookPos.m_X].SetChessPiece(new jRook(Colour::WHITE, whiteRookPos));
	Vec2 whiteRookPos2 = Vec2{ 7,0 };
	m_Board[whiteRookPos2.m_Y][whiteRookPos2.m_X].SetChessPiece(new jRook(Colour::WHITE, whiteRookPos2));
	Vec2 blackRookPos = Vec2{ 0,7 };
	m_Board[blackRookPos.m_Y][blackRookPos.m_X].SetChessPiece(new jRook(Colour::BLACK, blackRookPos));
	Vec2 blackRookPos2 = Vec2{ 7,7 };
	m_Board[blackRookPos2.m_Y][blackRookPos2.m_X].SetChessPiece(new jRook(Colour::BLACK, blackRookPos2));

	//Set Knights
	Vec2 whiteKnightPos = Vec2{ 1,0 };
	m_Board[whiteKnightPos.m_Y][whiteKnightPos.m_X].SetChessPiece(new jKnight(Colour::WHITE, whiteKnightPos));
	Vec2 whiteKnightPos2 = Vec2{ 6,0 };
	m_Board[whiteKnightPos2.m_Y][whiteKnightPos2.m_X].SetChessPiece(new jKnight(Colour::WHITE, whiteKnightPos2));
	Vec2 blackKnightPos = Vec2{ 1,7 };
	m_Board[blackKnightPos.m_Y][blackKnightPos.m_X].SetChessPiece(new jKnight(Colour::BLACK, blackKnightPos));
	Vec2 blackKnightPos2 = Vec2{ 6,7 };
	m_Board[blackKnightPos2.m_Y][blackKnightPos2.m_X].SetChessPiece(new jKnight(Colour::BLACK, blackKnightPos2));

	//Set Bishops
	Vec2 whiteBishopPos = Vec2{ 2,0 };
	m_Board[whiteBishopPos.m_Y][whiteBishopPos.m_X].SetChessPiece(new jBishop(Colour::WHITE, whiteBishopPos));
	Vec2 whiteBishopPos2 = Vec2{ 5,0 };
	m_Board[whiteBishopPos2.m_Y][whiteBishopPos2.m_X].SetChessPiece(new jBishop(Colour::WHITE, whiteBishopPos2));
	Vec2 blackBishopPos = Vec2{ 2,7 };
	m_Board[blackBishopPos.m_Y][blackBishopPos.m_X].SetChessPiece(new jBishop(Colour::BLACK, blackBishopPos));
	Vec2 blackBishopPos2 = Vec2{ 5,7 };
	m_Board[blackBishopPos2.m_Y][blackBishopPos2.m_X].SetChessPiece(new jBishop(Colour::BLACK, blackBishopPos2));

	Vec2 whiteKingPos = Vec2{ 4,0 };
	m_Board[whiteKingPos.m_Y][whiteKingPos.m_X].SetChessPiece(new jKing(Colour::WHITE, whiteKingPos));
	Vec2 blackKingPos = Vec2{ 4,7 };
	m_Board[blackKingPos.m_Y][blackKingPos.m_X].SetChessPiece(new jKing(Colour::BLACK, blackKingPos));

	Vec2 WhiteQueenPos = Vec2{ 3,0 };
	m_Board[WhiteQueenPos.m_Y][WhiteQueenPos.m_X].SetChessPiece(new jQueen(Colour::WHITE, WhiteQueenPos));
	Vec2 BlackQueenPos = Vec2{ 3,7 };
	m_Board[BlackQueenPos.m_Y][BlackQueenPos.m_X].SetChessPiece(new jQueen(Colour::BLACK, BlackQueenPos));

}

bool ChessBoard::isWithinBoard(Vec2 _pos)
{
	if ((0 <= _pos.m_X && _pos.m_X <= 7) && (0 <= _pos.m_Y && _pos.m_Y <= 7))
	{
		return true;
	}
	return false;
}
