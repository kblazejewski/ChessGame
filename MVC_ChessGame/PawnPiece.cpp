#include "PawnPiece.h"

PawnPiece::PawnPiece(Position position, Player player):ChessPiece(position, player)
{
	this->type = PieceType::Pawn;
}
