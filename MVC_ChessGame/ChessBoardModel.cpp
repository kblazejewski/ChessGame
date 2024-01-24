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

ChessBoardModel::ChessBoardModel()
{
	initializePieces();
}

QList<ChessPiece*> ChessBoardModel::getPieces()
{
	return this->pieces;
}
