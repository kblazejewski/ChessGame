#pragma once
#include <qgraphicsitem.h>
#include <qlabel.h>
#include "Position.h"
class ChessPieceBox :
    public QGraphicsRectItem
{
private:
	Position position; ///< The position of the chess piece on the chessboard.
	QLabel* imageLabel; ///< The label displaying the chess piece's image.
	QPixmap image; ///< The image representing the chess piece.
public:
	ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent = nullptr);
	const Position getPosition();
	void setPosition(Position position);
	void setImage(QString imgPath);
};

