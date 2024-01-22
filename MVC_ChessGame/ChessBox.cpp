#include "ChessBox.h"
#include "Utils.h"

ChessBox::ChessBox(QColor backgroundColor, Position position, QGraphicsItem* parent)
{
	this->defaultColor = backgroundColor;
	this->position = position;
	Utils::setBacgroundColor(backgroundColor, this);
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
