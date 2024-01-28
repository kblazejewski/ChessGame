#pragma once
#include "ChessPiece.h"
#include "Position.h"

class RookPiece :
    public ChessPiece
{
public:
	RookPiece(Position position, Player player, PieceType pieceType);
	virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
	virtual ChessPiece* deepCopy() override;
};

