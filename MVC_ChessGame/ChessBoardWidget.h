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
#include "ActionButton.h"

class ActionButton;
class ChessController;

class ChessBoardWidget : public QGraphicsView
{
    Q_OBJECT

public:
    ChessBoardWidget(ChessController* chessController, QWidget* parent = nullptr);
    bool started = false;
    void markPossibleMoves(ChessPiece* piece);

    ActionButton* queenButton;
    ActionButton* rookButton;
    ActionButton* bishopButton;
    ActionButton* knightButton;
    
public slots:
    void initializeChessBoard();
    void updateBoard(const QList<ChessPiece*>& chessPieces);
    void handleSquareClicked(const Position& position);
    void showWinnerPanel(Player &winner);
    void quit();
    void showPromotionButtons();
    void hidePromotionButtons();

signals:
    void gameStarted();
    void undoRequest();
    void promoteToQueen();
    void promoteToRook();
    void promoteToBishop();
    void promoteToKnight();
   
private:
    QGraphicsScene* scene;
    ChessBoard* chessBoard;
    ChessController* chessController;


    void mousePressEvent(QMouseEvent* event);
    void initializeBackgroundColor();
    void displayMenu();
    void drawTitle();

};
