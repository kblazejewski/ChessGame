#include "ChessPieceBox.h"
#include <QGraphicsProxyWidget>
#include <QPen>
#include "Constants.h"
#include "Utils.h"

//ChessPieceBox::ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent)
//{
//	this->position = position;
//	//Utils::setBacgroundColor(Qt::red, this);
//	imageLabel = new QLabel();
//	image = QPixmap(imagePath);
//	QGraphicsProxyWidget* myProxy = new QGraphicsProxyWidget(this);
//
//	imageLabel->setPixmap(image);
//	imageLabel->setAttribute(Qt::WA_TranslucentBackground);
//	//this->setPen(QPen(Qt::NoPen)); // Removes the border
//	myProxy->setWidget(imageLabel);
//}
ChessPieceBox::ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent)
    : QGraphicsRectItem(parent), position(position)
{
    /*qreal boxXPosition = position.x * Constants::defaultWidhHeight;
    qreal boxYPosition = position.y * Constants::defaultWidhHeight;*/

    setRect(0, 0, Constants::defaultWidhHeight, Constants::defaultWidhHeight);
    Utils::setBacgroundColor(Qt::red, this);
    QGraphicsProxyWidget* myProxy = new QGraphicsProxyWidget(this);
    QLabel* imageLabel = new QLabel();
    QPixmap image(imagePath);
    imageLabel->setPixmap(image);
    imageLabel->setAttribute(Qt::WA_TranslucentBackground);

    myProxy->setWidget(imageLabel);
    myProxy->setPos(0, 0);  // Pozycja wzglêdem rodzica, w tym przypadku ChessPieceBox
}