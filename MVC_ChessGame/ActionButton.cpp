#include "ActionButton.h"
#include "Utils.h"
#include <QColor>

ActionButton::ActionButton(QString title)
{
	setRect(0, 0, 200, 50);

	QColor backgroundColor = QColor(150, 120, 100);
	Utils::setBacgroundColor(backgroundColor, this);

	QColor textColor = QColor(40, 40, 50);
	QGraphicsTextItem* text = Utils::createTextItem(title, 20, textColor, this);
	double xPosition = rect().width() / 2 - text->boundingRect().width() / 2;
	double yPosition = rect().height() / 2 - text->boundingRect().height() / 2;
	text->setPos(xPosition, yPosition);

	// Enabled responding to hover events
	setAcceptHoverEvents(true);
}

void ActionButton::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	emit buttonPressed();
}

void ActionButton::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QColor backgroundColor = QColor(190, 178, 140);
	Utils::setBacgroundColor(backgroundColor, this);
}

void ActionButton::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QColor backgroundColor = QColor(150, 120, 100);
	Utils::setBacgroundColor(backgroundColor, this);
}