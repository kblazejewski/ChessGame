#include "QueenPiece.h"

QueenPiece::QueenPiece(Position position, Player player, PieceType pieceType) :ChessPiece(position, player, pieceType)
{
}

bool QueenPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    return validateAnotherPieceIntersection(positionToMove, chessPieces)
        && ((validateDiagonalMove(positionToMove, chessPieces)
            || validateVerticalOrHorizontalMove(positionToMove, chessPieces)));
}
