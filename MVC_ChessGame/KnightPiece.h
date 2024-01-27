#pragma once
#include "ChessPiece.h"
class KnightPiece :
    public ChessPiece
{
public:
    KnightPiece(Position position, Player player, PieceType pieceType);
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
};

