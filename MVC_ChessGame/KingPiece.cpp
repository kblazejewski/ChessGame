#include "KingPiece.h"

KingPiece::KingPiece(Position position, Player player):ChessPiece(position, player)
{
	this->type = PieceType::King;
}
