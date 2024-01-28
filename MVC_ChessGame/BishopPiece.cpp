#include "BishopPiece.h"

BishopPiece::BishopPiece(Position position, Player player, PieceType pieceType) :ChessPiece(position, player, pieceType)
{
}

bool BishopPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    return validateDiagonalMove(positionToMove, chessPieces)
        && validateAnotherPieceIntersection(positionToMove, chessPieces);
}

ChessPiece* BishopPiece::deepCopy()
{
    ChessPiece* copiedPiece = new BishopPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
    if (this->firstMoveTaken())
    {
        copiedPiece->setFirstMoveTaken();
    }
    return copiedPiece;
}
