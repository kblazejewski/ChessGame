// ChessBoardWidget.cpp
#include "ChessBoardWidget.h"
#include "Constants.h"
#include <QBrush>
#include "Utils.h"

ChessBoardWidget::ChessBoardWidget(QWidget* parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Constants::viewWidth, Constants::viewHeight);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, Constants::viewWidth, Constants::viewHeight);
    setScene(scene);

    //initializing chessBoard
    initializeChessBoard();

    //initialize background color
    initializeBackgroundColor();
    drawTitle();
}

void ChessBoardWidget::initializeChessBoard()
{
    //initializing chessboard
    chessBoard = new ChessBoard(scene);

    qreal centerX = (Constants::viewWidth - chessBoard->boundingRect().width()) / 2;
    qreal centerY = (Constants::viewHeight - chessBoard->boundingRect().height()) / 2;

    chessBoard->setPosition(centerX, centerY);
    scene->addItem(chessBoard);
}

void ChessBoardWidget::initializeBackgroundColor()
{
    //initialize background color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor color = QColor(44, 41, 51);
    brush.setColor(color);
    scene->setBackgroundBrush(brush);
}

void ChessBoardWidget::displayMenu()
{

}

void ChessBoardWidget::drawTitle()
{
    int fontSize = 30;
    int yPosition = 30;
    QGraphicsTextItem* title = Utils::createTextItem("Chess Game", fontSize, Qt::white);
    double xPosition = this->width() / 2 - title->boundingRect().width() / 2;
    title->setPos(xPosition, yPosition);
    scene->addItem(title);
}
