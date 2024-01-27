#pragma once
#include "ChessPiece.h"
class BishopPiece :
    public ChessPiece
{
public:
	BishopPiece(Position position, Player player, PieceType pieceType);
	virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
	virtual ChessPiece* deepCopy() const override;
};

