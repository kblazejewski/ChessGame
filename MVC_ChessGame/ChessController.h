#pragma once
#include "ChessGame.h"
#include "ChessBoardWidget.h"
#include <qobject.h>

class ChessBoardWidget;

class ChessController : public QObject
{
	Q_OBJECT
public:
	ChessController();
	ChessBoardWidget* getChessBoardWidget();
private:
	ChessGame* chessGame;
	ChessBoardWidget* chessBoardWidget;
};

