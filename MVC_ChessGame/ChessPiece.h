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
	Black, White, None
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
	const QList<Position> getPossibleMoves() const;
	void setPossibleMoves(QList<Position> legalMoves);
	const PieceType getPieceType() const;
	const Player getPlayer() const;
	const Position getPosition() const;
	void setPosition(Position position);
	// przekazanie ca³ej listy pionów, by obliczyæ mo¿liwe pozycje (nawet i w przypadku bicia w przelocie)
	virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) = 0;
	void setFirstMoveTaken();
	const bool firstMoveTaken() const;
	virtual ChessPiece* deepCopy() const = 0;


protected:
	const bool validateDiagonalMove(Position positionToMove, QList<ChessPiece*> chessPieces);
	const bool validateVerticalOrHorizontalMove(Position positionToMove, QList<ChessPiece*> chessPieces);
	const bool validateOneFieldMove(Position positionToMove, QList<ChessPiece*> chessPieces);
	const bool validateAnotherPieceIntersection(Position positionToMove, QList<ChessPiece*> chessPieces);
};

