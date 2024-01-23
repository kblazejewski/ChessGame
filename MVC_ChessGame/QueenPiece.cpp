#include "QueenPiece.h"

QueenPiece::QueenPiece(Position position, Player player) :ChessPiece(position, player)
{
	this->type = PieceType::Queen;
}
