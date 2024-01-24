#include <QObject>
#include <QGraphicsItemGroup>
#include <qgraphicsscene.h>
#include <qlist.h>
#include "ChessBox.h"
#include "ChessPieceBox.h"
#include "ChessPiece.h"
#include "qpointer.h"
#include <qstring.h>
#include "ChessPiece.h"



class ChessBoard : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
private:
    QGraphicsScene* scene;
    //QGraphicsItemGroup* chessBoardGroup;  // Dodaj deklaracjê dla grupy
    void draw();
    QList <ChessBox*> chessBoxes;
    QList <ChessPieceBox*> chessPieceBoxes;

    QString getImagePath(ChessPiece* piece);
    void deletePieceBoxes();
    
public slots:
    void boxClicked(const Position& position);

public:
    void updateBoard(const QList<ChessPiece*> chessPieces);
    ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent = nullptr);
    Position getPositionAtMousePoint(QPoint point);
};