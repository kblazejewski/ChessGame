#pragma once
#include <qstring.h>
#include "Position.h"
#include <qlist.h>

enum PieceType
{
	Pawn, Rook, Bishop, Knight, Queen, King
};

enum Player
{
	Black, White
};

class ChessPiece
{
private:
	Position position;
	bool didTakeFirstMove;
	Player player;
	QList<Position> possibleMoves;
	PieceType type;
public:
	ChessPiece(Position position, Player player, PieceType pieceType);
	virtual ~ChessPiece() = default;
	const QList<Position> getPossibleMoves();
	void setPossibleMoves(QList<Position> legalMoves);
	const PieceType getPieceType();
	const Player getPlayer();
	const Position getPosition();
	void setPosition(Position position);
	// przekazanie ca³ej listy pionów, by obliczyæ mo¿liwe pozycje (nawet i w przypadku bicia w przelocie)
	virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) = 0;

};

