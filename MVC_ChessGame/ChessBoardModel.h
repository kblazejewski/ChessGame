#pragma once
#include <qlist.h>
#include "ChessPiece.h"
#include "Position.h"
class ChessBoardModel
{
private:
	QList<ChessPiece*> whitePieces;
	QList<ChessPiece*> blackPieces;

	void initializePieces();
public:
	ChessBoardModel();

};

