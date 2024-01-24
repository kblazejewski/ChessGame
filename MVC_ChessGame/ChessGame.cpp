#include "ChessGame.h"
#include <qdebug.h>

ChessGame::ChessGame()
{
	this->chessBoardModel = ChessBoardModel();
	this->gameStarted = false;
}

void ChessGame::startGame()
{
	qDebug() << "Gra wystartowala";
	this->gameStarted = true;
	emit updateBoard(chessBoardModel.getPieces());
}
