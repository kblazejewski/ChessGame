// ChessBoardWidget.cpp
#include "ChessBoardWidget.h"
#include "Constants.h"
#include <QBrush>

ChessBoardWidget::ChessBoardWidget(QWidget* parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Constants::viewWidth, Constants::viewHeight);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, Constants::viewWidth, Constants::viewHeight);
    setScene(scene);


    //initializing chessboard
    chessBoard = new ChessBoard(scene);

    qreal centerX = (Constants::viewWidth - chessBoard->boundingRect().width()) / 2;
    qreal centerY = (Constants::viewHeight - chessBoard->boundingRect().height()) / 2;

    chessBoard->setPosition(centerX, centerY);
    scene->addItem(chessBoard);


    //initialize background color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor color = QColor(44, 41, 51);
    brush.setColor(color);
    scene->setBackgroundBrush(brush);
}