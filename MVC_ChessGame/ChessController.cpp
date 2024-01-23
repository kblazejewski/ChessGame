#include "ChessController.h"

ChessController::ChessController()
{
	this->chessGame = new ChessGame();
	this->chessBoardWidget = new ChessBoardWidget();
}

ChessBoardWidget* ChessController::getChessBoardWidget()
{
	return this->chessBoardWidget;
}
