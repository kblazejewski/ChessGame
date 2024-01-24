#include "ChessPiece.h"

ChessPiece::ChessPiece(Position position, Player player, PieceType pieceType)
{
	this->type = pieceType;
	this->position = position;
	this->player = player;
	this->didTakeFirstMove = false;
}

const QList<Position> ChessPiece::getPossibleMoves()
{
	return this->possibleMoves;
}

void ChessPiece::setPossibleMoves(QList<Position> legalMoves)
{
	this->possibleMoves.clear();
	this->possibleMoves = legalMoves;
}

const PieceType ChessPiece::getPieceType()
{
	if (this->type)
	{
		return this->type;
	}
	return this->type;
}

const Player ChessPiece::getPlayer()
{
	return this->player;
}

const Position ChessPiece::getPosition()
{
	return this->position;
}


