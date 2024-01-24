#pragma once
#include <qlist.h>
#include "ChessPiece.h"
#include "Position.h"
class ChessBoardModel
{
private:
	QList<ChessPiece*> pieces;

	void initializePieces();
public:
	ChessBoardModel();
	QList<ChessPiece*> getPieces();
};

