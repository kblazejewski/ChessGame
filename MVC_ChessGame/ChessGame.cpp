#include "ChessGame.h"
#include <qdebug.h>
#include "PawnPiece.h"

ChessGame::ChessGame()
{
	//this->chessBoardModel = ChessBoardModel();
	this->winner = Player::None;
	this->gameStarted = false;
}

void ChessGame::makeMove(Position posFrom, Position posTo)
{
	ChessPiece* pieceToMove = getPieceAtPositionActivePlayer(posFrom);
	if (pieceToMove)
	{
		for (auto position : pieceToMove->getPossibleMoves())
		{
			// jeœli to jest ruch dozwolony
			if (position.x == posTo.x && position.y == posTo.y)
			{
				// enpassant
				//check if pawn make a double move
				if (pieceToMove->getPieceType() == PieceType::Pawn)
				{
					if (posTo.x == this->chessBoardModel.getEnPassantMovePosition().x && posTo.y == this->chessBoardModel.getEnPassantMovePosition().y)
					{
						this->chessBoardModel.removePieceAt(this->chessBoardModel.getEnPassantCapturePositon());
						this->chessBoardModel.clearEnPassantData();
					}
					else
					{
						this->chessBoardModel.clearEnPassantData();
					}
					if (abs(posFrom.y - posTo.y) == 2)
					{
						qDebug() << "Double move";
						PawnPiece* pawn = dynamic_cast<PawnPiece*> (pieceToMove);
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
						emit gameOver(this->winner);
					}
					else
					{
						this->winner = Player::White;
						emit gameOver(this->winner);
					}
				}
				if (this->chessBoardModel.isPromotionAvailable())
				{
					qDebug() << "Promocja dostepna";
					this->chessBoardModel.promotePawn(PieceType::Queen);
				}
				emit updateBoard(chessBoardModel.getPieces());
			}
		}
	}
	
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
	this->chessBoardModel = ChessBoardModel();
	this->gameStarted = true;
	this->winner = Player::None;
	emit updateBoard(chessBoardModel.getPieces());
}
