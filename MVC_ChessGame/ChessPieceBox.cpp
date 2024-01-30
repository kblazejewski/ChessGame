#include "ChessPieceBox.h"
#include <QGraphicsProxyWidget>
#include <QPen>
#include "Constants.h"
#include "Utils.h"


ChessPieceBox::ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent)
    : QGraphicsRectItem(parent), position(position)
{
    setRect(0, 0, Constants::defaultWidhHeight, Constants::defaultWidhHeight);
    QGraphicsProxyWidget* myProxy = new QGraphicsProxyWidget(this);
    QLabel* imageLabel = new QLabel();
    QPixmap image(imagePath);
    imageLabel->setPixmap(image);
    imageLabel->setAttribute(Qt::WA_TranslucentBackground);

    myProxy->setWidget(imageLabel);
    myProxy->setPos(0, 0);
}