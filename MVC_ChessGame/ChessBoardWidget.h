#pragma once
#include <qgraphicsview.h>
#include "ChessBoard.h"

class ChessBoardWidget :
    public QGraphicsView
{
    //Q_OBJECT
public:
    ChessBoardWidget(QWidget* parent = nullptr);
private:
    QGraphicsScene* scene;
    ChessBoard* chessBoard;
};

