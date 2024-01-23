// W klasie ChessBoard dodaj deklaracjê dla QGraphicsItemGroup
#include <QGraphicsItemGroup>
#include <qgraphicsscene.h>
#include <qlist.h>
#include "ChessBox.h"
#include "ChessPieceBox.h"
#include "ChessPiece.h"
#include "qpointer.h"
#include <qstring.h>
#include "ChessPiece.h"

class ChessBoard : public QGraphicsRectItem {
private:
    QGraphicsScene* scene;
    QGraphicsItemGroup* chessBoardGroup;  // Dodaj deklaracjê dla grupy
    void draw();
    QList <ChessBox*> chessBoxes;
    QList <QPointer<ChessPieceBox>> chessPieceBoxes;

    QString getImagePath(ChessPiece* piece);

public:
    ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent = nullptr);
    void setPosition(qreal x, qreal y);

    void updatePieceView(QList <ChessPiece*> whitePieces, QList <ChessPiece*> blackPieces);

};