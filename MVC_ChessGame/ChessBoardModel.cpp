#include "ChessBoardModel.h"
#include "Constants.h"
#include "Position.h"
#include "ChessPiece.h"
#include "RookPiece.h";
#include "KnightPiece.h"
#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"
#include "PawnPiece.h"


void ChessBoardModel::initializePieces()
{
	for (int row = 0; row < Constants::numberOfRowsCols; row++)
	{
		if (row > 1 && row < 6)
		{
			continue;
		}
		Player player = (row < 2 ) ? Player::Black : Player::White;
		for (int column = 0; column < Constants::numberOfRowsCols; column++)
		{
			PieceType type;

			switch (column)
			{
			case 0:
				type = PieceType::Rook;
				break;
			case 7:
				type = PieceType:: Rook;
				break;
			case 1:
				type = PieceType::Knight;
				break;
			case 6:
				type = PieceType::Knight;
				break;
			case 2:
				type = PieceType::Bishop;
				break;
			case 5:
				type = PieceType::Bishop;
				break;
			case 3:
				type = PieceType::Queen;
				break;
			case 4:
				type = PieceType::King;
				break;
			}

			if (row == 1 || row == 6)
			{
				type = PieceType::Pawn;
			}
			ChessPiece* piece = nullptr;
			Position position = { column, row };
			if (type == PieceType::Rook)
			{
				piece = new RookPiece(position, player, type);
			}
			else if (type == PieceType::Knight)
			{
				piece = new KnightPiece(position, player, type);
			}
			else if (type == PieceType::Bishop)
			{
				piece = new BishopPiece(position, player, type);
			}
			else if (type == PieceType::Queen)
			{
				piece = new QueenPiece(position, player, type);
			}
			else if (type == PieceType::King)
			{
				piece = new KingPiece(position, player, type);
			}
			else if (type == PieceType::Pawn)
			{
				piece = new PawnPiece(position, player, type);
			}

			this->pieces.append(piece);
		}
	}
}


void ChessBoardModel::setEnPassantCapturePosition(Position postion)
{
	this->enPassantCapturePosition = postion;
}

const Position ChessBoardModel::getEnPassantCapturePositon() const
{
	return this->enPassantCapturePosition;
}

void ChessBoardModel::setEnPassantMovePosition(Position position)
{
	this->enPassantMovePosition = position;
}

const Position ChessBoardModel::getEnPassantMovePosition() const
{
	return this->enPassantMovePosition;
}

void ChessBoardModel::clearEnPassantData()
{
	//set the pos to -1 , -1 
	this->enPassantCapturePosition = { -1, -1 };
	this->enPassantMovePosition = { -1,-1 };
	restoreAllPawnsVulnerablnes();
}

ChessPiece* ChessBoardModel::getPieceAt(Position position)
{
	for (auto piece : this->pieces)
	{
		if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
		{
			return piece;
		}
	}
	return nullptr;
}

ChessPiece* ChessBoardModel::getPieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces)
{
	if (!chessPieces.isEmpty())
	{
		for (auto piece : chessPieces)
		{
			if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
			{
				return piece;
			}
		}	
	}
	return nullptr;
}

void ChessBoardModel::removePieceAt(Position position)
{
	for (auto piece : this->pieces)
	{
		if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
		{
			this->pieces.removeOne(piece);
			delete piece;
		}
	}
}

void ChessBoardModel::removePieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces)
{
	if (!chessPieces.isEmpty())
	{
		for (auto piece : chessPieces)
		{
			if (piece->getPosition().x == position.x && piece->getPosition().y == position.y)
			{
				chessPieces.removeOne(piece);
				delete piece;
				return;
			}
		}
	}
}

void ChessBoardModel::movePieceTo(ChessPiece* piece, Position position)
{
	// tutaj pewnie trzeba bedzie coœ dodaæ
	if (piece)
	{
		piece->setPosition(position);
	}
}

ChessBoardModel::ChessBoardModel()
{
	initializePieces();
	this->whosTurn = Player::White;
	calculatePossibleMoves();
}

QList<ChessPiece*> ChessBoardModel::getPieces()
{
	return this->pieces;
}

const Player ChessBoardModel::getWhosTurn()
{
	return this->whosTurn;
}

void ChessBoardModel::switchTurn()
{
	if (this->whosTurn == Player::White)
	{
		this->whosTurn = Player::Black;
	}
	else
	{
		this->whosTurn = Player::White;
	}
}

void ChessBoardModel::calculatePossibleMoves()
{
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces)
		{
			QList<Position> possibleMoves;
			possibleMoves.clear();

			for (int y = 0; y < Constants::numberOfRowsCols; y++)
			{
				for (int x = 0; x < Constants::numberOfRowsCols; x++)
				{
					// copy of the current position
					QList<ChessPiece*> copiedCurrentPosition = getCopyOfCurrentPosition();

					ChessPiece* pieceToCheck = getPieceAtGivenPosition(piece->getPosition(), copiedCurrentPosition);


					Position positionToMove = { x, y };
					if (pieceToCheck->validateMove(positionToMove, copiedCurrentPosition))
					{
						//make move
						if (this->getPieceAtGivenPosition(positionToMove,copiedCurrentPosition))
						{
							/*this->removePieceAtGivenPosition(positionToMove, copiedCurrentPosition);*/
							for (auto pieceToRemove : copiedCurrentPosition)
							{
								if (pieceToRemove->getPosition().x == positionToMove.x && pieceToRemove->getPosition().y == positionToMove.y)
								{
									copiedCurrentPosition.removeOne(pieceToRemove);
									delete pieceToRemove;
								}
							}
						}
						this->movePieceTo(pieceToCheck, positionToMove);
	

						//recalculate
						this->calculatePossibleMovesForGivenPosition(copiedCurrentPosition);

						//check if king is not in check -> move valid
						if (!this->isKingInCheckInGivenPosition(pieceToCheck->getPlayer(), copiedCurrentPosition))
						{
							possibleMoves.append(positionToMove);
						}
					}

					// deleting current position
					while (!copiedCurrentPosition.isEmpty())
					{
						ChessPiece* copied = copiedCurrentPosition.takeFirst();
						delete copied;
					}
					copiedCurrentPosition.clear();
				}
			}
			piece->setPossibleMoves(possibleMoves);
		}
	}
}

void ChessBoardModel::calculatePossibleMovesForGivenPosition(QList<ChessPiece*> chessPieces)
{
	for (auto piece : chessPieces)
	{
		if (piece)
		{
			QList<Position> possibleMoves;
			possibleMoves.clear();
			for (int y = 0; y < Constants::numberOfRowsCols; y++)
			{
				for (int x = 0; x < Constants::numberOfRowsCols; x++)
				{
					Position positionToMove = { x, y };
					if (piece->validateMove(positionToMove, chessPieces))
					{
						possibleMoves.append(positionToMove);
					}
				}
				piece->setPossibleMoves(possibleMoves);
			}
		}
	}
}

QList<ChessPiece*> ChessBoardModel::getCopyOfCurrentPosition()
{
	QList<ChessPiece*> copyOfPieces;
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces) 
		{
			copyOfPieces.append(piece->deepCopy());
		}
	}
	return copyOfPieces;
}



void ChessBoardModel::restorePosition(QList<ChessPiece*> chessPieces)
{
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces)
		{
			delete piece;
		}
	}
	this->pieces.clear();

	this->pieces = chessPieces;
}

const bool ChessBoardModel::isKingInCheckInGivenPosition(Player player, QList<ChessPiece*> chessPieces) const
{
	ChessPiece* king = nullptr;
	if (!chessPieces.isEmpty())
	{
		for (auto piece : chessPieces)
		{
			if (player == Player::White && piece->getPieceType() == PieceType::King && piece->getPlayer() == Player::White)
			{
				//get white king
				king = piece;
				break;
			}
			else if (player == Player::Black && piece->getPieceType() == PieceType::King && piece->getPlayer() == Player::Black)
			{
				//get black king
				king = piece;
				break;
			}
		}
	}

	if (king)
	{
		for (auto piece : chessPieces)
		{
			// if in possible moves is king position, king is in check
			for (auto possibleMove : piece->getPossibleMoves())
			{
				if (possibleMove.x == king->getPosition().x && possibleMove.y == king->getPosition().y)
				{
					return true;
				}
			}
		}
	}
	return false;
}

const bool ChessBoardModel::isCheckMate(Player player) const
{
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces)
		{
			if (piece->getPlayer() == player)
			{
				if (piece->getPossibleMoves().length()>0)
				{
					return false;
				}
			}
		}
		return true;
	}
}

const bool ChessBoardModel::isPromotionAvailable() const
{
	if (!this->pieces.isEmpty())
	{
		for (auto piece: this->pieces)
		{
			if (piece->getPieceType() == PieceType::Pawn)
			{
				if (piece->getPlayer() == Player::White)
				{
					if (piece->getPosition().y == 0)
					{
						return true;
					}
				}
				else
				{
					if (piece->getPosition().y == 7)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void ChessBoardModel::promotePawn(PieceType pieceType)
{
	ChessPiece* pawnToPromote = nullptr;
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces)
		{
			if (piece->getPieceType() == PieceType::Pawn)
			{
				if (piece->getPlayer() == Player::White)
				{
					if (piece->getPosition().y == 0)
					{
						pawnToPromote = piece;
						break;
					}
				}
				else
				{
					if (piece->getPosition().y == 7)
					{
						pawnToPromote = piece;
						break;
					}
				}
			}
		}
	}
	if (pawnToPromote)
	{
		Position pos = pawnToPromote->getPosition();
		Player player = pawnToPromote->getPlayer();

		//deleting pawn 
		this->pieces.removeOne(pawnToPromote);
		delete pawnToPromote;

		ChessPiece* newPiece = nullptr;
		if (pieceType == PieceType::Queen)
		{
			newPiece = new QueenPiece(pos, player, pieceType);
			this->pieces.append(newPiece);
		}
		else if (pieceType == PieceType::Knight)
		{
			newPiece = new KnightPiece(pos, player, pieceType);
			this->pieces.append(newPiece);
		}
		else if (pieceType == PieceType::Rook)
		{
			newPiece = new RookPiece(pos, player, pieceType);
			this->pieces.append(newPiece);
		}
		else if (pieceType == PieceType::Bishop)
		{
			newPiece = new BishopPiece(pos, player, pieceType);
			this->pieces.append(newPiece);
		}
	}
}

void ChessBoardModel::performCastle(Player player, bool isShortCastle)
{
	int kingStartColumn = 4;
	int kingTargetColumn = (isShortCastle) ? 6 : 2;
	int rookStartColumn = (isShortCastle) ? 7 : 0;
	int rookTargetColumn = (isShortCastle) ? 5 : 3;

	int row = (player == Player::White) ? 7 : 0;

	ChessPiece* king = getPieceAt({ kingStartColumn, row });
	ChessPiece* rook = getPieceAt({ rookStartColumn, row });

	if (king && rook && king->getPieceType() == PieceType::King && rook->getPieceType() == PieceType::Rook)
	{
			movePieceTo(king, { kingTargetColumn, row });
			movePieceTo(rook, { rookTargetColumn, row });
	}
}

void ChessBoardModel::restoreAllPawnsVulnerablnes()
{
	if (!this->pieces.isEmpty())
	{
		for (auto piece : this->pieces)
		{
			if (piece->getPieceType() == PieceType::Pawn)
			{
				PawnPiece* pawn = dynamic_cast<PawnPiece*> (piece);
				pawn->resetEnPassantVurnelable();
			}
		}
	}
}

