#include "KnightPiece.h"

KnightPiece::KnightPiece(Position position, Player player, PieceType pieceType):ChessPiece(position, player, pieceType)
{
}

bool KnightPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
	ChessPiece* pieceOnPositionToMove = nullptr;
	for (auto piece : chessPieces)
	{
		if (piece->getPosition().x == positionToMove.x && piece->getPosition().y == positionToMove.y)
		{
			pieceOnPositionToMove = piece;
		}
	}

	// if on this position is a piece with the same color return false
	if (pieceOnPositionToMove && pieceOnPositionToMove->getPlayer() == this->getPlayer())
	{
		return false;
	}

	int xDifference = abs(positionToMove.x - this->getPosition().x);
	int yDifference = abs(positionToMove.y - this->getPosition().y);

	// Knights can move in an L-shape pattern: 2 squares in one direction and 1 square perpendicular.
	if ((xDifference == 2 && yDifference == 1) || (xDifference == 1 && yDifference == 2))
	{
		return true;
	}

	return false;
}

ChessPiece* KnightPiece::deepCopy() const
{
	ChessPiece* copiedPiece = new KnightPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
	if (this->firstMoveTaken())
	{
		copiedPiece->setFirstMoveTaken();
	}
	return copiedPiece;
}
