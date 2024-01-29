#include "ChessController.h"

ChessController::ChessController()
{
	this->chessBoardWidget = new ChessBoardWidget(this);
	this->chessGame = new ChessGame();
	this->positionFromActive = false;
	this->positionToActive = false;
	connect(this->chessBoardWidget, SIGNAL(gameStarted()), this->chessGame, SLOT(startGame()));
	connect(this->chessGame, SIGNAL(updateBoard(const QList<ChessPiece*>&)), this->chessBoardWidget, SLOT(updateBoard(const QList<ChessPiece*>&)));
	connect(this->chessGame, &ChessGame::gameOver, this->chessBoardWidget, &ChessBoardWidget::showWinnerPanel);
	connect(this->chessBoardWidget, &ChessBoardWidget::undoRequest, this->chessGame, &ChessGame::undoMove);
	connect(this->chessGame, &ChessGame::promotionActive, this->chessBoardWidget, &ChessBoardWidget::showPromotionButtons);
	connect(this->chessBoardWidget, &ChessBoardWidget::promoteToQueen, this, &ChessController::handlePromoteToQueen);
	connect(this->chessBoardWidget, &ChessBoardWidget::promoteToBishop, this, &ChessController::handlePromoteToBishop);
	connect(this->chessBoardWidget, &ChessBoardWidget::promoteToRook, this, &ChessController::handlePromoteToRook);
	connect(this->chessBoardWidget, &ChessBoardWidget::promoteToKnight, this, &ChessController::handlePromoteToKnight);
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
	this->positionFromActive = false;
	this->positionToActive = false;
}

void ChessController::handlePromoteToQueen()
{
	this->chessGame->promotePawn(PieceType::Queen);
	this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToBishop()
{
	this->chessGame->promotePawn(PieceType::Bishop);
	this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToRook()
{
	this->chessGame->promotePawn(PieceType::Rook);
	this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToKnight()
{
	this->chessGame->promotePawn(PieceType::Knight);
	this->chessBoardWidget->hidePromotionButtons();
}

