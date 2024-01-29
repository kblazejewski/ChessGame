#pragma once
#include <QObject> 
#include <qlist.h>
#include "ChessPiece.h"
#include "ChessBoardModel.h"

class ChessGame : public QObject 
{
    Q_OBJECT 

public:
    ChessGame();
    void makeMove(Position posFrom, Position posTo);
    ChessPiece* getPieceAtPositionActivePlayer(Position position);
    void saveRound();
    void promotePawn(PieceType type);
    
public slots:
    void startGame();
    void undoMove();

signals:
    void updateBoard(const QList<ChessPiece*> chessPieces);
    void gameOver(Player &winner);
    void promotionActive();


private:
    QList<QList<ChessPiece*>> gameHistory;
    ChessBoardModel chessBoardModel;
    bool gameStarted;
    bool gamePaused;
    Player winner;
    void clearGameHistory();
};
