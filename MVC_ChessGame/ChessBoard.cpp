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
	if (!chessPieces.isEmpty())
	{
		for (auto piece : chessPieces)
		{
			QString imagePath = getImagePath(piece);
			ChessPieceBox* pieceBox = new ChessPieceBox(piece->getPosition(), imagePath, this);

			//int pieceXPosition = Constants::startXPosition + piece->getPosition().x * Constants::defaultWidhHeight;
			//int pieceYPosition = Constants::startYPosition + piece->getPosition().y * Constants::defaultWidhHeight;

			int pieceXPosition = piece->getPosition().x * Constants::defaultWidhHeight;
			int pieceYPosition = piece->getPosition().y * Constants::defaultWidhHeight;

			pieceBox->setRect(0, 0, Constants::defaultWidhHeight, Constants::defaultWidhHeight);
			pieceBox->setPos(pieceXPosition, pieceYPosition);

			this->chessPieceBoxes.append(pieceBox);
			chessBoardGroup->addToGroup(pieceBox);
		}
	}
}

ChessBoard::ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent)
    : QGraphicsRectItem(parent), scene(sceneIn)
{
    int size = Constants::numberOfRowsCols * Constants::defaultWidhHeight;
    setRect(0, 0, size, size);

    // Utwórz grupê dla pionków na szachownicy
    chessBoardGroup = new QGraphicsItemGroup(this);
    scene->addItem(chessBoardGroup);

    this->chessBoxes.clear();

    draw();
}

void ChessBoard::setPosition(qreal x, qreal y)
{
    this->setPos(x, y);
    chessBoardGroup->setPos(x, y);
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
            box->setRect(boxXPosition, boxYPosition, Constants::defaultWidhHeight, Constants::defaultWidhHeight);

            this->chessBoxes.append(box);
            // Dodaj pole do grupy
            chessBoardGroup->addToGroup(box);
        }
    }
}