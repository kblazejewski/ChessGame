#pragma once
#include <QGraphicsView>
#include "ChessBoard.h"
#include "Position.h"
#include "ChessController.h"
#include "qlist.h"
#include "ChessPiece.h"
#include "ChessPieceBox.h"
#include <QMouseEvent>
#include "ChessBox.h"

class ChessController;

class ChessBoardWidget : public QGraphicsView
{
    Q_OBJECT

public:
    ChessBoardWidget(ChessController* chessController, QWidget* parent = nullptr);
    bool started = false;
public slots:
    void initializeChessBoard();
    void updateBoard(const QList<ChessPiece*>& chessPieces);

signals:
    void gameStarted();

private:
    QGraphicsScene* scene;
    ChessBoard* chessBoard;
    ChessController* chessController;

    void initializeBackgroundColor();
    void displayMenu();
    void drawTitle();
};
