#include "ChessController.h"

ChessController::ChessController()
{
	this->chessBoardWidget = new ChessBoardWidget(this);
	this->chessGame = new ChessGame();
	connect(this->chessBoardWidget, SIGNAL(gameStarted()), this->chessGame, SLOT(startGame()));
	connect(this->chessGame, SIGNAL(updateBoard(const QList<ChessPiece*>&)), this->chessBoardWidget, SLOT(updateBoard(const QList<ChessPiece*>&)));
}

ChessBoardWidget* ChessController::getChessBoardWidget()
{
	return this->chessBoardWidget;
}
