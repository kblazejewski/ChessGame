#pragma once
#include "ChessPiece.h"
class KingPiece :
    public ChessPiece
{
public:
    KingPiece(Position position, Player player, PieceType pieceType);
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
    virtual ChessPiece* deepCopy() const override;
};

