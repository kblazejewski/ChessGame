// W pliku ChessBoard.cpp
#include "ChessBoard.h"
#include "Constants.h"
#include "ChessBox.h"

QString ChessBoard::getImagePath(ChessPiece* piece)
{
	QString imageFileName;
	if (piece->getPieceType() == PieceType::Pawn)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "pawn_white.svg";
		}
		else
		{
			imageFileName = "pawn_black.svg";
		}
	}
	else if (piece->getPieceType() == PieceType::Rook)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "rook_white.svg";
		}
		else
		{
			imageFileName = "rook_black.svg";
		}
	}
	else if (piece->getPieceType() == PieceType::Knight)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "knight_white.svg";
		}
		else
		{
			imageFileName = "knight_black.svg";
		}
	}
	else if (piece->getPieceType() == PieceType::Bishop)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "bishop_white.svg";
		}
		else
		{
			imageFileName = "bishop_black.svg";
		}
	}
	else if (piece->getPieceType() == PieceType::Queen)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "queen_white.svg";
		}
		else
		{
			imageFileName = "queen_black.svg";
		}
	}
	else if (piece->getPieceType() == PieceType::King)
	{
		if (piece->getPlayer() == Player::White)
		{
			imageFileName = "king_white.svg";
		}
		else
		{
			imageFileName = "king_black.svg";
		}
	}

	return "images/" + imageFileName;
}

void ChessBoard::deletePieceBoxes()
{
	if (!this->chessPieceBoxes.isEmpty())
	{
		for (auto pieceBox : this->chessPieceBoxes)
		{
			removeFromGroup(pieceBox);
			scene->removeItem(pieceBox);
			delete pieceBox;
		}
		this->chessPieceBoxes.clear();
	}
	else
	{
		return;
	}
}

void ChessBoard::updateBoard(const QList<ChessPiece*> chessPieces)
{
	deletePieceBoxes();
	if (!chessPieces.isEmpty())
	{
		for (auto piece : chessPieces)
		{
			QString imagePath = getImagePath(piece);
			ChessPieceBox* pieceBox = new ChessPieceBox(piece->getPosition(), imagePath, this);

			qreal boxXPosition = piece->getPosition().x * Constants::defaultWidhHeight;
			qreal boxYPosition = piece->getPosition().y * Constants::defaultWidhHeight;

			pieceBox->setPos(boxXPosition, boxYPosition);

			this->chessPieceBoxes.append(pieceBox);
			addToGroup(pieceBox);
		}
	}
}

ChessBoard::ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent)
    : QGraphicsItemGroup(parent), scene(sceneIn)
{
	scene->addItem(this);
    this->chessBoxes.clear();

    draw();
}

void ChessBoard::changeColorUnderAttack(ChessPiece* piece)
{
	restoreDefaultColor();
	if (piece)
	{
		for (auto pos : piece->getPossibleMoves())
		{
			ChessBox* box = getBoxAtPosition(pos);
			box->changeColorUnderAttack();
		}
	}
}

void ChessBoard::restoreDefaultColor()
{
	for (auto box : this->chessBoxes)
	{
		box->restoreDefaultColor();
	}
}

ChessBox* ChessBoard::getBoxAtPosition(Position position)
{
	for (auto box: this->chessBoxes)
	{
		if (box->getPosition().x == position.x && box->getPosition().y == position.y)
		{
			return box;
		}
	}
	return nullptr;
}


void ChessBoard::draw()
{
    for (int x = 0; x < Constants::numberOfRowsCols; x++)
    {
        for (int y = 0; y < Constants::numberOfRowsCols; y++)
        {
            QColor squareColor = ((x + y) % 2 == 0) ? Constants::lightBoxColor : Constants::darkBoxColor;
            ChessBox* box = new ChessBox(squareColor, { x, y }, this);
            qreal boxXPosition = x * Constants::defaultWidhHeight;
            qreal boxYPosition = y * Constants::defaultWidhHeight;
			box->setPos(boxXPosition, boxYPosition);
			
			connect(box, &ChessBox::boxClicked, this, &ChessBoard::boxClicked);

            this->chessBoxes.append(box);
			scene->addItem(box);
            // Dodaj pole do grupy
            addToGroup(box);
			box->setFlag(QGraphicsItem::ItemIsSelectable); //This line set flag which allows select elements
			box->setFlag(QGraphicsItem::ItemIsFocusable);   //This flag allow get into element in case of click
        }
    }
}

void ChessBoard::boxClicked(const Position& position)
{
	emit signalBoxClicked(position);
}