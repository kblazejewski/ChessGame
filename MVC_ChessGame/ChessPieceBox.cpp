#include "ChessPieceBox.h"
#include <QGraphicsProxyWidget>
#include <QPen>

ChessPieceBox::ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent)
{
	this->position = position;
	imageLabel = new QLabel();
	image = QPixmap(imagePath);
	QGraphicsProxyWidget* myProxy = new QGraphicsProxyWidget(this);

	imageLabel->setPixmap(image);
	imageLabel->setAttribute(Qt::WA_TranslucentBackground);
	this->setPen(QPen(Qt::NoPen)); // Removes the border
	myProxy->setWidget(imageLabel);
}
