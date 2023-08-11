#include "Square.h"

Square::Square(): m_Chess(nullptr)
{

}

Square::~Square()
{
}

IChessPiece* Square::GetSelectedPiece()
{
	return m_Chess;
}

void Square::SetChessPiece(IChessPiece* _piece)
{
	m_Chess = _piece;
}

void Square::ClearSquare()
{
	delete m_Chess;
	m_Chess = nullptr;
}
