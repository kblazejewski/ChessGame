#pragma once
#include <QGraphicsRectItem>
#include "Position.h"
#include <qcolor.h>

class ChessBox :
    public QGraphicsRectItem
{
private:
    Position position;
    QColor defaultColor;

public:
    ChessBox(QColor backgroundColor, Position position, QGraphicsItem* parent = nullptr);

    void setPosition(Position position);
    const Position getPosition();

    void changeColorUnderAttack();
    void restoreDefaultColor();
};

