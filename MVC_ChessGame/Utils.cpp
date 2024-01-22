#include "Utils.h"
#include <qbrush.h>

void Utils::setBacgroundColor(QColor color, QAbstractGraphicsShapeItem* item)
{
	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(color);
	item->setBrush(brush);
}

QGraphicsTextItem* Utils::createTextItem(QString title, int fontSize, QColor textColor, QGraphicsItem* parent)
{
	QGraphicsTextItem* textItem = new QGraphicsTextItem(title, parent);
	QFont titleFont("avenir", fontSize);
	textItem->setDefaultTextColor(textColor);
	textItem->setFont(titleFont);

	return textItem;
}