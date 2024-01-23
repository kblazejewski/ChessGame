#include "KnightPiece.h"

KnightPiece::KnightPiece(Position position, Player player):ChessPiece(position, player)
{
	this->type = PieceType::Knight;
}
