#include "ChessPiece.h"


const bool ChessPiece::validateDiagonalMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
	ChessPiece* pieceOnPositionToMove = nullptr;
	for (auto piece: chessPieces)
	{
		if (piece->getPosition().x == positionToMove.x && piece->getPosition().y == positionToMove.y)
		{
			pieceOnPositionToMove = piece;
		}
	}
	// if on this position is a piece with the same color return false

	if (pieceOnPositionToMove && pieceOnPositionToMove->getPlayer() == this->player)
	{
		return false;
	}
	
	int xDiference = positionToMove.x - this->position.x;
	int yDiference = positionToMove.y - this->position.y;

	if (abs(xDiference) != abs(yDiference))
	{
		return false;
	}
	else
	{
		return true;
	}

}

const bool ChessPiece::validateVerticalOrHorizontalMove(Position positionToMove, QList<ChessPiece*> chessPieces)
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
	if (pieceOnPositionToMove && pieceOnPositionToMove->getPlayer() == this->player)
	{
		return false;
	}

	if (!(positionToMove.x == this->position.x || positionToMove.y == this->position.y))
	{
		return false;
	}
	else
	{
		return true;
	}
}

const bool ChessPiece::validateOneFieldMove(Position positionToMove, QList<ChessPiece*> chessPieces)
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
	if (pieceOnPositionToMove && pieceOnPositionToMove->getPlayer() == this->player)
	{
		return false;
	}
	else
	{
		int xDiference = positionToMove.x - this->position.x;
		int yDiference = positionToMove.y - this->position.y;

		int numberOfFieldsToMove = std::max(abs(xDiference), abs(yDiference));

		return (numberOfFieldsToMove == 1);
	}
}

const bool ChessPiece::validateAnotherPieceIntersection(Position positionToMove, QList<ChessPiece*> chessPieces)
{
	int xDiference = positionToMove.x - this->position.x;
	int yDiference = positionToMove.y - this->position.y;
	int numberOfFieldsToCheck = std::max(abs(xDiference), abs(yDiference));
	

	if (numberOfFieldsToCheck == 1)
	{
		return true;
	}

	for (int i = 0; i < numberOfFieldsToCheck; i++)
	{
		Position positionToCheck;

		if (xDiference < 0)
		{
			if (yDiference == 0)
			{
				positionToCheck = { this->position.x + (xDiference + i), this->position.y };
			}
			else if (yDiference < 0)
			{
				positionToCheck = { this->position.x + (xDiference + i), this->position.y + (yDiference + i) };
			}
			else
			{
				positionToCheck = { this->position.x + (xDiference + i), this->position.y + (yDiference - i) };
			}
		}
		else if (yDiference < 0)
		{
			if (xDiference == 0)
			{
				positionToCheck = { this->position.x, this->position.y + (yDiference + i) };
			}
			else
			{
				positionToCheck = { this->position.x + (xDiference - i), this->position.y + (yDiference + i) };
			}
		}
		else
		{
			if (xDiference == 0)
			{
				positionToCheck = { this->position.x, this->position.y + (yDiference - i) };
			}
			else if (yDiference == 0)
			{
				positionToCheck = { this->position.x + (xDiference - i), this->position.y };
			}
			else
			{
				positionToCheck = { this->position.x + (xDiference - i), this->position.y + (yDiference - i) };
			}
		}

		ChessPiece* pieceToCheck = nullptr;
		for (auto piece : chessPieces)
		{
			if (piece->getPosition().x == positionToCheck.x && piece->getPosition().y == positionToCheck.y)
			{
				pieceToCheck = piece;
			}
		}

		//if (positionToCheck.x == positionToMove.x && positionToCheck.y == positionToMove.y)
		//{
		//	if (pieceToCheck && (pieceToCheck->getPlayer() != this->getPlayer()))
		//	{
		//		return true;
		//	}
		//}
		if (pieceToCheck)
		{
			if (positionToCheck.x == positionToMove.x && positionToCheck.y == positionToMove.y)
				{
					continue;
				}
			else
			{
				return false;
			}
		}
	}


	return true;
}

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

void ChessPiece::setPosition(Position position)
{
	this->position = position;
}

const bool ChessPiece::madeFirstMove()
{
	return this->didTakeFirstMove;
}

void ChessPiece::takeFirsMove()
{
	this->didTakeFirstMove = true;
}


