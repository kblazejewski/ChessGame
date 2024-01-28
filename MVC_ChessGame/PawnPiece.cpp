#include "PawnPiece.h"

PawnPiece::PawnPiece(Position position, Player player, PieceType pieceType):ChessPiece(position, player, pieceType), enPassantVurnelable(false)
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
			else if (abs(yDiference) == 2 && !this->firstMoveTaken())
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
				//jeœli bicie w przelocie
				//wyszukanie pól obok piona
				for (auto piece : chessPieces)
				{
					if (abs(piece->getPosition().x - this->getPosition().x) == 1 && piece->getPosition().y == this->getPosition().y)
					{
						if (piece->getPieceType() == PieceType::Pawn)
						{
							PawnPiece* nearestPawn = dynamic_cast<PawnPiece*> (piece);
							if (nearestPawn->enPassantVurnelable)
							{
								canMove = true;
							}
						}
					}
				}
			}
			
		}
	}
	
	return canMove;
	
}

ChessPiece* PawnPiece::deepCopy() 
{
	ChessPiece* copiedPiece = new PawnPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
	if (this->firstMoveTaken())
	{
		copiedPiece->setFirstMoveTaken();
		if (this->enPassantVurnelable)
		{
			PawnPiece* pawn = dynamic_cast<PawnPiece*> (copiedPiece);
			pawn->setEnPassantVurnelable();
		}
	}
	return copiedPiece;
}

void PawnPiece::setEnPassantVurnelable()
{
	this->enPassantVurnelable = true;
}

void PawnPiece::resetEnPassantVurnelable()
{
	this->enPassantVurnelable = false;
}
