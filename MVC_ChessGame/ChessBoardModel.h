#pragma once
#include <qlist.h>
#include "ChessPiece.h"
#include "Position.h"
class ChessBoardModel
{
private:
	QList<ChessPiece*> pieces;
	void initializePieces();
	Player whosTurn;

public:
	ChessPiece* getPieceAt(Position position);
	void removePieceAt(Position position);
	void movePieceTo(ChessPiece* piece, Position position);
	ChessBoardModel();
	QList<ChessPiece*> getPieces();
	const Player getWhosTurn();
	void switchTurn();
	void calculatePossibleMoves();
	QList<ChessPiece*> getCurrentPosition(); // deep copy of actual position
	void restorePosition(QList<ChessPiece*> chessPieces);
};

