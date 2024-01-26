#pragma once
#include "ChessPiece.h"
#include "Position.h"
class QueenPiece :
    public ChessPiece
{
public:
    QueenPiece(Position position, Player player, PieceType pieceType);
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
};

