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
		// move in straight line
		if (xDiference == 0)
		{
			// by one field
			if (abs(yDiference) == 1)
			{
				// no piece
				if (!pieceOnPositionToMove)
				{
					canMove = true;
				}
			}
			// by two fields
			else if (abs(yDiference) == 2 && !this->firstMoveTaken())
			{
				// no piece
				if (!pieceOnPositionToMove)
				{
					canMove = true;
				}
			}
		}
		// diagonal move
		else if (abs(xDiference) == 1)
		{
			if (abs(yDiference) == 1)
			{
				// check if on diagonal field is piece and if is oponnent player
				if (pieceOnPositionToMove && (pieceOnPositionToMove->getPlayer() != this->getPlayer()))
				{
					canMove = true;
				}
				// if enpassant
				for (auto piece : chessPieces)
				{
					if (abs(piece->getPosition().x - this->getPosition().x) == 1 && piece->getPosition().y == this->getPosition().y)
					{
						if (piece->getPieceType() == PieceType::Pawn)
						{
							PawnPiece* nearestPawn = dynamic_cast<PawnPiece*> (piece);
							if (nearestPawn->enPassantVurnelable && nearestPawn->getPosition().x == positionToMove.x)
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
