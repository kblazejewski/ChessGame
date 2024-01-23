#include "ChessBoardModel.h"
#include "Constants.h"
#include "Position.h"
#include "ChessPiece.h"
#include "RookPiece.h";
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"


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
			case 7:
				type = PieceType:: Rook;
			case 1:
				type = PieceType::Knight;
			case 6:
				type = PieceType::Knight;
			case 2:
				type = PieceType::Bishop;
			case 5:
				type = PieceType::Bishop;
			case 3:
				type = PieceType::Queen;
			case 4:
				type = PieceType::King;
			}

			if (row == 1 || row == 6)
			{
				type = PieceType::Pawn;
			}
			ChessPiece* piece = nullptr;
			Position position = { column, row };
			if (type == PieceType::Rook)
			{
				piece = new RookPiece(position, player);
			}
			else if (type == PieceType::Knight)
			{
				piece = new KnightPiece(position, player);
			}
			else if (type == PieceType::Bishop)
			{
				piece = new BishopPiece(position, player);
			}
			else if (type == PieceType::Queen)
			{
				piece = new QueenPiece(position, player);
			}
			else if (type == PieceType::King)
			{
				piece = new KingPiece(position, player);
			}


			if (player == Player::White)
			{
				this->whitePieces.append(piece);
			}
			else
			{
				this->blackPieces.append(piece);
			}
		}
	}
}

ChessBoardModel::ChessBoardModel()
{
	initializePieces();
}
