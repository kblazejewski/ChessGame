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
	ChessPiece* getPieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces);
	void removePieceAt(Position position);
	void removePieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces);
	void movePieceTo(ChessPiece* piece, Position position);
	ChessBoardModel();
	QList<ChessPiece*> getPieces();
	const Player getWhosTurn();
	void switchTurn();
	void calculatePossibleMoves();
	void calculatePossibleMovesForGivenPosition(QList<ChessPiece*> chessPieces);
	QList<ChessPiece*> getCopyOfCurrentPosition(); // deep copy of actual position
	void restorePosition(QList<ChessPiece*> chessPieces);
	const bool isKingInCheckInGivenPosition(Player player, QList<ChessPiece*> chessPieces) const;
	const bool isCheckMate(Player player) const;
	const bool isPromotionAvailable()const;
	void promotePawn(PieceType pieceType);
	void performCastle(Player player, bool isShortCastle);
};

