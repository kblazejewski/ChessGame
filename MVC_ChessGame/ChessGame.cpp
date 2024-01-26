#include "ChessGame.h"
#include <qdebug.h>

ChessGame::ChessGame()
{
	this->chessBoardModel = ChessBoardModel();
	this->gameStarted = false;
}

void ChessGame::makeMove(Position posFrom, Position posTo)
{
	
	if (this->chessBoardModel.getPieceAt(posTo))
	{
		this->chessBoardModel.removePieceAt(posTo);
	}
	this->chessBoardModel.movePieceTo(getPieceAtPositionActivePlayer(posFrom), posTo);
	this->chessBoardModel.switchTurn();
	emit updateBoard(chessBoardModel.getPieces());
}

ChessPiece* ChessGame::getPieceAtPositionActivePlayer(Position position)
{
	ChessPiece* piece = chessBoardModel.getPieceAt(position);
	if (piece)
	{
		if (piece->getPlayer() == this->chessBoardModel.getWhosTurn())
		{
			return piece;
		}
	}
	return nullptr;
}

void ChessGame::startGame()
{
	qDebug() << "Gra wystartowala";
	this->gameStarted = true;
	emit updateBoard(chessBoardModel.getPieces());
}
