#include "RookPiece.h"

RookPiece::RookPiece(Position position, Player player, PieceType pieceType) :ChessPiece(position, player, pieceType)
{
}

bool RookPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    return validateVerticalOrHorizontalMove(positionToMove, chessPieces) 
        && validateAnotherPieceIntersection(positionToMove, chessPieces);
}
