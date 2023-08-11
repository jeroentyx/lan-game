#pragma once

#include "IChessPiece.hpp"

class Square
{
public:
	Square();

	virtual ~Square();
	IChessPiece* GetSelectedPiece();
	void SetChessPiece(IChessPiece* _piece);
	void ClearSquare();
private:
	IChessPiece* m_Chess;
};
