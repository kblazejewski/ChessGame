#include "ChessController.h"

ChessController::ChessController()
{
	this->chessBoardWidget = new ChessBoardWidget(this);
	this->chessGame = new ChessGame();
	this->positionFromActive = false;
	this->positionToActive = false;
	connect(this->chessBoardWidget, SIGNAL(gameStarted()), this->chessGame, SLOT(startGame()));
	connect(this->chessGame, SIGNAL(updateBoard(const QList<ChessPiece*>&)), this->chessBoardWidget, SLOT(updateBoard(const QList<ChessPiece*>&)));
}

ChessBoardWidget* ChessController::getChessBoardWidget()
{
	return this->chessBoardWidget;
}

void ChessController::handleBoxClicked(Position position)
{
	if (this->chessGame->getPieceAtPositionActivePlayer(position))
	{
		this->positionFrom = this->chessGame->getPieceAtPositionActivePlayer(position)->getPosition();
		this->positionFromActive = true;
		// do widgetu by podœwietli³o mo¿liwe pola
		this->chessBoardWidget->markPossibleMoves(this->chessGame->getPieceAtPositionActivePlayer(position));
		qDebug() << "Wybrano figure: " << this->chessGame->getPieceAtPositionActivePlayer(position)->getPieceType() << "gracza: " << this->chessGame->getPieceAtPositionActivePlayer(position)->getPlayer();
		return;
	}
	//jesli ju¿ pozycja Z zosta³a ustalona to wykonaj ruch
	if (positionFromActive)
	{
		this->positionTo = position;
		this->positionToActive = true;
		this->chessGame->makeMove(positionFrom, positionTo);


		// wyzerowanie flag
		this->positionFromActive = false;
		this->positionToActive = false;
	}

}

void ChessController::cancelMove()
{
	qDebug() << "Ruch anulowany";
	this->positionFromActive = false;
	this->positionToActive = false;
}

