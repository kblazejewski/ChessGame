#include "RookPiece.h"

RookPiece::RookPiece(Position position, Player player) :ChessPiece(position, player)
{
	this->type = PieceType::Rook;
}
