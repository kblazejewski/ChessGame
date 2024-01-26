#include "BishopPiece.h"

BishopPiece::BishopPiece(Position position, Player player, PieceType pieceType) :ChessPiece(position, player, pieceType)
{
}

bool BishopPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    return validateDiagonalMove(positionToMove, chessPieces)
        && validateAnotherPieceIntersection(positionToMove, chessPieces);
}
