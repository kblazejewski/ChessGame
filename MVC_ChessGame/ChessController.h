#pragma once
#include "ChessGame.h"
#include "ChessBoardWidget.h"

class ChessController
{
public:
	ChessController();
	ChessBoardWidget* getChessBoardWidget();
private:
	ChessGame* chessGame;
	ChessBoardWidget* chessBoardWidget;
};

