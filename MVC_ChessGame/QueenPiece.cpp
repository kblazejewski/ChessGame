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

ChessPiece* QueenPiece::deepCopy()
{
    ChessPiece* copiedPiece = new QueenPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
    if (this->firstMoveTaken())
    {
        copiedPiece->setFirstMoveTaken();
    }
    return copiedPiece;
}
