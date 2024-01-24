#pragma once
#include "ChessPiece.h"
class KingPiece :
    public ChessPiece
{
public:
    KingPiece(Position position, Player player, PieceType pieceType);
};

