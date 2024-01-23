#include "BishopPiece.h"

BishopPiece::BishopPiece(Position position, Player player) :ChessPiece(position, player)
{
	this->type = PieceType::Bishop;
}
