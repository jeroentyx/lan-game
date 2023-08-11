#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include <map>
#include <utility>
#include <memory>
#include "Position.h"

class LanBoard;

enum class PieceChar : char
{
  WHITE_PAWN = 'P',
  WHITE_KNIGHT = 'N',
  WHITE_BISHOP = 'B',
  WHITE_ROOK = 'R',
  WHITE_QUEEN = 'Q',
  WHITE_KING = 'K',

  BLACK_PAWN = 'p',
  BLACK_KNIGHT = 'n',
  BLACK_BISHOP = 'b',
  BLACK_ROOK = 'r',
  BLACK_QUEEN = 'q',
  BLACK_KING = 'k',
  EMPTY = 'e',
};

class Piece
{
public:
  Piece(Colour c, const Position& pos);
  virtual ~Piece();
  
  virtual void    GenMoves(const LanBoard& board, std::vector<Move>& moves) const = 0;
  virtual Piece*  Create(const Position& pos) const = 0;
  virtual Piece*  Clone() const = 0;
  Colour          colour() const;
  void            position(const Position& pos);
  const Position& position() const;
  static Piece*  Factory(PieceChar piece, const Position& pos);

protected:
  Colour m_colour;
  Position m_pos;

  void BishopRookMoves(const LanBoard& board, std::vector<Move>& moves, int* case_1, int* case_2, int* case_3, int* case_4) const;
  void KnightKingMoves(const LanBoard& board, std::vector<Move>& moves, Position* movements) const;
};

class Pawn : public Piece
{
public:
  Pawn(Colour c, const Position& pos);

  void  GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  Pawn* Create(const Position& pos) const;
  Pawn* Clone() const;
};

class Knight : public Piece
{
public:
  Knight(Colour c, const Position& pos);

  void    GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  Knight* Create(const Position& pos) const;
  Knight* Clone() const;
};

class Bishop : public virtual Piece
{
public:
  Bishop(Colour c, const Position& pos);

  void    GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  Bishop* Create(const Position& pos) const;
  Bishop* Clone() const;
};

class Rook : public virtual Piece
{
public:
  Rook(Colour c, const Position& pos);

  void  GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  Rook* Create(const Position& pos) const;
  Rook* Clone() const;
};

class King : public Piece
{
public:
  King(Colour c, const Position& pos);

  void  GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  King* Create(const Position& pos) const override;
  King* Clone() const;
};

#ifdef _WIN32
class Queen : public virtual Piece, public Bishop, public Rook
#else
class Queen : public Bishop, public Rook
#endif
{
public:
  Queen(Colour c, const Position& pos);

  void   GenMoves(const LanBoard& board, std::vector<Move>& moves) const;
  Queen* Create(const Position& pos) const;
  Queen* Clone() const;
};
#endif

