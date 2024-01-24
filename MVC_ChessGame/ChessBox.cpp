#include "ChessBox.h"
#include "Utils.h"
#include "Constants.h"

ChessBox::ChessBox(QColor backgroundColor, Position position, QGraphicsItem* parent) : QGraphicsRectItem(parent), defaultColor(backgroundColor), position(position)
{
	Utils::setBacgroundColor(backgroundColor, this);
	setRect(0, 0, Constants::defaultWidhHeight, Constants::defaultWidhHeight);
	setAcceptHoverEvents(true);
}

void ChessBox::setPosition(Position position)
{
	this->position = position;
}

const Position ChessBox::getPosition()
{
	return this->position;
}

void ChessBox::changeColorUnderAttack()
{
	QColor color = Qt::red;
	Utils::setBacgroundColor(color, this);
}

void ChessBox::restoreDefaultColor()
{
	QColor color = this->defaultColor;
	Utils::setBacgroundColor(color, this);
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qDebug() << "clicked";
	emit boxClicked(this->position);
}
