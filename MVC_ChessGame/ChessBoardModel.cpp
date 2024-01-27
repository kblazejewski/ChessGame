#include "ChessBoardModel.h"
#include "Constants.h"
#include "Position.h"
#include "ChessPiece.h"
#include "RookPiece.h";
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"
#include "PawnPiece.h"


void ChessBoardModel::initializePieces()
{
	for (int row = 0; row < Constants::numberOfRowsCols; row++)
	{
		if (row > 1 && row < 6)
		{
			continue;
		}
		Player player = (row < 2 ) ? Player::Black : Player::White;
		for (int column = 0; column < Constants::numberOfRowsCols; column++)
		{
			PieceType type;

			switch (column)
			{
			case 0:
				type = PieceType::Rook;
				break;
			case 7:
				type = PieceType:: Rook;
				break;
			case 1:
				type = PieceType::Knight;
				break;
			case 6:
				type = PieceType::Knight;
				break;
			case 2:
				type = PieceType::Bishop;
				break;
			case 5:
				type = PieceType::Bishop;
				break;
			case 3:
				type = PieceType::Queen;
				break;
			case 4:
				type = PieceType::King;
				break;
			}

			if (row == 1 || row == 6)
			{
				type = PieceType::Pawn;
			}
			ChessPiece* piece = nullptr;
			Position position = { column, row };
			if (type == PieceType::Rook)
			{
				piece = new RookPiece(position, player, type);
			}
			else if (type == PieceType::Knight)
			{
				piece = new KnightPiece(position, player, type);
			}
			else if (type == PieceType::Bishop)
			{
				piece = new BishopPiece(position, player, type);
			}
			else if (type == PieceType::Queen)
			{
				piece = new QueenPiece(position, player, type);
			}
			else if (type == PieceType::King)
			{
				piece = new KingPiece(position, player, type);
			}
			else if (type == PieceType::Pawn)
			{
				piece = new PawnPiece(position, player, type);
			}

			this->pieces.append(piece);
		}
	}
}


ChessPiece* ChessBoardModel::getPieceAt(Position position)
{
	for (auto piece : this->pieces)
	{
		if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
		{
			return piece;
		}
	}
	return nullptr;
}

void ChessBoardModel::removePieceAt(Position position)
{
	for (auto piece : this->pieces)
	{
		if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
		{
			this->pieces.removeOne(piece);
			delete piece;
		}
	}
}

void ChessBoardModel::movePieceTo(ChessPiece* piece, Position position)
{
	// tutaj pewnie trzeba bedzie coœ dodaæ
	if (piece)
	{
		piece->setPosition(position);
	}
}

ChessBoardModel::ChessBoardModel()
{
	initializePieces();
	this->whosTurn = Player::White;
	calculatePossibleMoves();
}

QList<ChessPiece*> ChessBoardModel::getPieces()
{
	return this->pieces;
}

const Player ChessBoardModel::getWhosTurn()
{
	return this->whosTurn;
}

void ChessBoardModel::switchTurn()
{
	if (this->whosTurn == Player::White)
	{
		this->whosTurn = Player::Black;
	}
	else
	{
		this->whosTurn = Player::White;
	}
}

void ChessBoardModel::calculatePossibleMoves()
{
	for (auto piece : this->pieces)
	{
		QList<Position> possibleMoves;
		possibleMoves.clear();
		for (int y = 0; y < Constants::numberOfRowsCols; y++)
		{
			for (int x = 0; x < Constants::numberOfRowsCols; x++)
			{
				Position positionToMove = { x, y };
				if (piece->validateMove(positionToMove, this->pieces))
				{
					possibleMoves.append(positionToMove);
				}
			}
			piece->setPossibleMoves(possibleMoves);
		}
	}
}
