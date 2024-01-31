#pragma once
#include "ChessPiece.h"
class RookBishopPiece :
    public ChessPiece
{
public:

    RookBishopPiece(Position position, Player player, PieceType pieceType);

    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    virtual ChessPiece* deepCopy() override;
};

