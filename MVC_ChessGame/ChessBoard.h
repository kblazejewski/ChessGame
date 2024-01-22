// W klasie ChessBoard dodaj deklaracjê dla QGraphicsItemGroup
#include <QGraphicsItemGroup>
#include <qgraphicsscene.h>

class ChessBoard : public QGraphicsRectItem {
private:
    QGraphicsScene* scene;
    QGraphicsItemGroup* chessPiecesGroup;  // Dodaj deklaracjê dla grupy
    void draw();

public:
    ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent = nullptr);
    void setPosition(qreal x, qreal y);

};