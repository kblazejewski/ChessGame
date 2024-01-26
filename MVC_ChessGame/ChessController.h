#pragma once
#include "ChessGame.h"
#include "ChessBoardWidget.h"
#include <qobject.h>
#include "Position.h"

class ChessBoardWidget;

class ChessController : public QObject
{
	Q_OBJECT
public:
	ChessController();
	ChessBoardWidget* getChessBoardWidget();
	void handleBoxClicked(Position position);
	void cancelMove();

private:
	Position positionFrom;
	bool positionFromActive;
	Position positionTo;
	bool positionToActive;
	ChessGame* chessGame;
	ChessBoardWidget* chessBoardWidget;
};

