#pragma once
#include "ChessPiece.h"
class PawnPiece :
    public ChessPiece
{
public:
	PawnPiece(Position position, Player player, PieceType pieceType);
	virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;
	virtual ChessPiece* deepCopy() override;
	void setEnPassantVurnelable();
	void resetEnPassantVurnelable();

private:
	bool enPassantVurnelable;
};

