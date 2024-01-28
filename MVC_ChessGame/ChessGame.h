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
    
public slots:
    void startGame();

signals:
    void updateBoard(const QList<ChessPiece*> chessPieces);
    void gameOver(Player &winner);


private:
    ChessBoardModel chessBoardModel;
    bool gameStarted;
    Player winner;
};
