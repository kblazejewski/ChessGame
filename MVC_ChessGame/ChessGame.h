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
    
public slots:
    void startGame();

signals:
    void updateBoard(const QList<ChessPiece*> chessPieces);

private:
    ChessBoardModel chessBoardModel;
    bool gameStarted;
};
