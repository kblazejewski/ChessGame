#include "ChessGame.h"
#include <qdebug.h>
#include "PawnPiece.h"

ChessGame::ChessGame()
{
	this->winner = Player::None;
	this->gameStarted = false;
	this->gamePaused = false;
	saveRound();
}

void ChessGame::makeMove(Position posFrom, Position posTo)
{
	ChessPiece* pieceToMove = getPieceAtPositionActivePlayer(posFrom);
	if (pieceToMove)
	{
		for (auto position : pieceToMove->getPossibleMoves())
		{
			// if move is possible
			if (position.x == posTo.x && position.y == posTo.y)
			{
				// enpassant
				//check if pawn make a double move
				if (pieceToMove->getPieceType() == PieceType::Pawn)
				{
					if (posTo.x == this->chessBoardModel.getEnPassantMovePosition().x && posTo.y == this->chessBoardModel.getEnPassantMovePosition().y)
					{
						this->chessBoardModel.removePieceAt(this->chessBoardModel.getEnPassantCapturePositon());
					}
					if (abs(posFrom.y - posTo.y) == 2)
					{
						qDebug() << "Double move";
						PawnPiece* pawn = dynamic_cast<PawnPiece*> (pieceToMove);
						this->chessBoardModel.clearEnPassantData();
						pawn->setEnPassantVurnelable();
						this->chessBoardModel.setEnPassantCapturePosition(position);
						this->chessBoardModel.setEnPassantMovePosition({ pieceToMove->getPosition().x, (posFrom.y + posTo.y) / 2 });
					}
				}
				// castling
				if (pieceToMove->getPieceType() == PieceType::King && qAbs(posTo.x - posFrom.x) == 2)
				{
					bool isShortCastle = (posTo.x > posFrom.x);
					chessBoardModel.performCastle(chessBoardModel.getWhosTurn(), isShortCastle);

					this->chessBoardModel.switchTurn();
					this->chessBoardModel.calculatePossibleMoves();
					saveRound();
					emit updateBoard(chessBoardModel.getPieces());
					return;
				}


				if (this->chessBoardModel.getPieceAt(posTo))
				{
					this->chessBoardModel.removePieceAt(posTo);
				}
				pieceToMove->setFirstMoveTaken(); // set that piece take a firs move
				this->chessBoardModel.movePieceTo(pieceToMove, posTo);
				this->chessBoardModel.switchTurn();
				this->chessBoardModel.calculatePossibleMoves();
				if (this->chessBoardModel.isCheckMate(this->chessBoardModel.getWhosTurn()))
				{
					qDebug() << "MAT";
					if (this->chessBoardModel.getWhosTurn() == Player::White)
					{
						this->winner = Player::Black;
						saveRound();
						emit gameOver(this->winner);
					}
					else
					{
						this->winner = Player::White;
						saveRound();
						emit gameOver(this->winner);
					}
				}
				if (this->chessBoardModel.isPromotionAvailable())
				{
					this->gamePaused = true;
					qDebug() << "Promocja dostepna";
					emit promotionActive();
					return;
				}
				saveRound();
				emit updateBoard(chessBoardModel.getPieces());
			}
		}
	}
	
}

ChessPiece* ChessGame::getPieceAtPositionActivePlayer(Position position)
{
	if (this->gamePaused)
	{
		return nullptr;
	}
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

void ChessGame::saveRound()
{
	this->gameHistory.append(this->chessBoardModel.getCopyOfCurrentPosition());
}

void ChessGame::promotePawn(PieceType type)
{
	this->chessBoardModel.promotePawn(type);
	this->chessBoardModel.calculatePossibleMoves();
	saveRound();
	this->gamePaused = false;
	emit updateBoard(chessBoardModel.getPieces());
	
}

void ChessGame::startGame()
{
	qDebug() << "Gra wystartowala";
	this->chessBoardModel = ChessBoardModel();
	this->gameStarted = true;
	this->winner = Player::None;
	clearGameHistory();
	saveRound();
	emit updateBoard(chessBoardModel.getPieces());
}

void ChessGame::undoMove()
{

	if (gameHistory.size() >= 2)
	{
		QList<ChessPiece*> previousGameState = gameHistory.at(gameHistory.size()-2);
		chessBoardModel.restorePosition(previousGameState);
		QList<ChessPiece*> lastGameState = gameHistory.takeLast();
		while (!lastGameState.isEmpty())
		{
			delete lastGameState.takeFirst();
		}
		gameHistory.removeLast();

		chessBoardModel.switchTurn();
		chessBoardModel.calculatePossibleMoves();
		saveRound();
		emit updateBoard(chessBoardModel.getPieces());
	}
}


void ChessGame::clearGameHistory()
{
	for (const QList<ChessPiece*>& round : gameHistory) {
		for (ChessPiece* piece : round) {
			delete piece;
		}
	}
	gameHistory.clear();
}