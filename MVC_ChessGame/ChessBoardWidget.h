#pragma once
#include <qgraphicsview.h>
#include "ChessBoard.h"
#include "Position.h"

class ChessBoardWidget :
    public QGraphicsView
{
    Q_OBJECT

public:
    ChessBoardWidget(QWidget* parent = nullptr);
    Position getMousePosition();
private:
    QGraphicsScene* scene;
    ChessBoard* chessBoard;
    void initializeChessBoard();
    void initializeBackgroundColor();
    void displayMenu();

    void drawTitle();
};

