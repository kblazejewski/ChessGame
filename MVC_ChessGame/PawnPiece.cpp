#include "PawnPiece.h"

PawnPiece::PawnPiece(Position position, Player player, PieceType pieceType):ChessPiece(position, player, pieceType)
{
}

bool PawnPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
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

	int xDiference = positionToMove.x - this->getPosition().x;
	int yDiference = positionToMove.y - this->getPosition().y;

	int numberOfFieldsToMove = std::max(abs(xDiference), abs(yDiference));
	bool wantsToMoveByOneField = (numberOfFieldsToMove == 1);

	bool wantsToMoveInGoodDirection = false;
	if (this->getPlayer() == Player::Black)
	{
		wantsToMoveInGoodDirection = yDiference > 0;
	}
	else if (this->getPlayer() == Player::White)
	{
		wantsToMoveInGoodDirection = yDiference < 0;
	}

	bool canMove = false;
	if (wantsToMoveInGoodDirection)
	{
		//ruch w linii prostej
		if (xDiference == 0)
		{
			// o jedno pole
			if (abs(yDiference) == 1)
			{
				// nie mo¿e byæ figury
				if (!pieceOnPositionToMove)
				{
					canMove = true;
				}
			}
			// o dwa pola
			else if (abs(yDiference) == 2 && !this->madeFirstMove())
			{
				// nie mo¿e byæ figury
				if (!pieceOnPositionToMove)
				{
					canMove = true;
				}
			}
		}
		// jeœli ruch po skosie
		else if (abs(xDiference) == 1)
		{
			// jeœli ruch po skosie
			if (abs(yDiference) == 1)
			{
				// sprawdŸ czy na skoœnym polu jest figura i czy jest przeciwnego gracza
				if (pieceOnPositionToMove && (pieceOnPositionToMove->getPlayer() != this->getPlayer()))
				{
					canMove = true;
				}
			}
		}
	}
	
	return canMove;
	
}
