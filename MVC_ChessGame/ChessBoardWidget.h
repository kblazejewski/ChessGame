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
    void markPossibleMoves(ChessPiece* piece);
    
public slots:
    void initializeChessBoard();
    void updateBoard(const QList<ChessPiece*>& chessPieces);
    void handleSquareClicked(const Position& position);
    void showWinnerPanel(Player winner);
    void quit();

signals:
    void gameStarted();
   
private:
    QGraphicsScene* scene;
    ChessBoard* chessBoard;
    ChessController* chessController;

    void mousePressEvent(QMouseEvent* event);
    void initializeBackgroundColor();
    void displayMenu();
    void drawTitle();
};
