#pragma once
#include <QAbstractGraphicsShapeItem>
#include <QColor>
#include <QFont>

class Utils
{
public:
	static void setBacgroundColor(QColor color, QAbstractGraphicsShapeItem* item);
	static QGraphicsTextItem* createTextItem(QString title, int fontSize, QColor textColor, QGraphicsItem* parent = nullptr);
};

