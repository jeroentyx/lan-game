#ifndef NEW_GAME_H
#define NEW_GAME_H
#include "LanBoard.h"
#include "Helper/Board.hpp"
#include "Player.h"
#include "Wrappers.h"
#include "Helper/vec2.hpp"

class NewGame
{
public:
	NewGame(Player white_player, Player black_player);
	NewGame();

	NewGame& operator=(const NewGame& game);

	bool CheckPlayer(SOCKET s) const;
	void PrintBoard() const;
	void PrintBoard(SOCKET s) const;
	void PrintjBoard();
	void PrintBoardSpec(SOCKET s) const;
	void MakeMove(const Move& move);
	void MakeMove(Vec2 fromPosition,Vec2 toPosition);


	bool CheckSpectators(SOCKET s) const;
	void AddSpectators(SOCKET s);
	void DeleteSpectators(SOCKET s);
	size_t SpecSize() const;

	SOCKET GetOpponentSocket(Player p);
	bool operator==(const NewGame& game) const;

	Colour turn;
	std::vector<SOCKET> spec;
	Player white;
	Player black;
private:

	LanBoard board;
	ChessBoard jBoard;

};

#endif
