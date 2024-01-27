#include "KingPiece.h"

KingPiece::KingPiece(Position position, Player player, PieceType pieceType):ChessPiece(position, player, pieceType)
{
}

bool KingPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    return validateOneFieldMove(positionToMove, chessPieces);
}

ChessPiece* KingPiece::deepCopy() const
{
    ChessPiece* copiedPiece = new KingPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
    if (this->firstMoveTaken())
    {
        copiedPiece->setFirstMoveTaken();
    }
    return copiedPiece;
}
