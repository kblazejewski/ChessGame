#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Position.h"
#include <qcolor.h>
#include <qobject.h>


class ChessBox : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    Position position;
    QColor defaultColor;

public:
    ChessBox(QColor backgroundColor, Position position, QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void setPosition(Position position);
    const Position getPosition();

    void changeColorUnderAttack();
    void restoreDefaultColor();

signals:
    void boxClicked(const Position& position);



};

