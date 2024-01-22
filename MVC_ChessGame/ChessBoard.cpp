// W pliku ChessBoard.cpp
#include "ChessBoard.h"
#include "Constants.h"
#include "ChessBox.h"

ChessBoard::ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent)
    : QGraphicsRectItem(parent), scene(sceneIn)
{
    int size = Constants::numberOfRowsCols * Constants::defaultWidhHeight;
    setRect(0, 0, size, size);

    // Utwórz grupê dla pionków na szachownicy
    chessPiecesGroup = new QGraphicsItemGroup(this);
    scene->addItem(chessPiecesGroup);

    draw();
}

void ChessBoard::setPosition(qreal x, qreal y)
{
    this->setPos(x, y);
    chessPiecesGroup->setPos(x, y);
}

void ChessBoard::draw()
{
    for (int x = 0; x < Constants::numberOfRowsCols; x++)
    {
        for (int y = 0; y < Constants::numberOfRowsCols; y++)
        {
            QColor squareColor = ((x + y) % 2 == 0) ? Constants::lightBoxColor : Constants::darkBoxColor;
            ChessBox* box = new ChessBox(squareColor, { x, y }, this);
            qreal boxXPosition = x * Constants::defaultWidhHeight;
            qreal boxYPosition = y * Constants::defaultWidhHeight;
            box->setRect(boxXPosition, boxYPosition, Constants::defaultWidhHeight, Constants::defaultWidhHeight);

            // Dodaj pole do grupy
            chessPiecesGroup->addToGroup(box);
        }
    }
}