// ChessBoardWidget.cpp
#include "ChessBoardWidget.h"
#include "Constants.h"
#include <QBrush>
#include "Utils.h"
#include "ActionButton.h"

ChessBoardWidget::ChessBoardWidget(ChessController* chessController, QWidget* parent)
    : QGraphicsView(parent), chessController(chessController)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Constants::viewWidth, Constants::viewHeight);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, Constants::viewWidth, Constants::viewHeight);
    setScene(scene);


    //initialize background color
    initializeBackgroundColor();
    drawTitle();
    displayMenu();
}

void ChessBoardWidget::markPossibleMoves(ChessPiece* piece)
{   
    this->chessBoard->changeColorUnderAttack(piece);
}

void ChessBoardWidget::handleSquareClicked(const Position& position)
{
    this->chessController->handleBoxClicked(position);
}

void ChessBoardWidget::showWinnerPanel(Player &winner)
{
    //scene->removeItem(this->chessBoard);


    int fontSize = 30;
    int yPosition = 600;
    QString win = (winner == Player::White) ? "WHITE" : "BLACK";
    QGraphicsTextItem* winnerText = Utils::createTextItem(win + " WON", fontSize, Qt::white);
    double xPosition = this->width() / 2 - winnerText->boundingRect().width() / 2;
    winnerText->setPos(xPosition, yPosition);
    scene->addItem(winnerText);
    undoButton->setVisible(false);
    //displayMenu();
}

void ChessBoardWidget::quit()
{
    qDebug() << "Forced close";
    close();
}

void ChessBoardWidget::showPromotionButtons()
{
    queenButton->setVisible(true);
    bishopButton->setVisible(true);
    rookButton->setVisible(true);
    knightButton->setVisible(true);
}

void ChessBoardWidget::initializeChessBoard()
{
    scene->clear();
    drawTitle();
    //initializing chessboard
    chessBoard = new ChessBoard(scene);
    chessBoard->setHandlesChildEvents(false);

    qreal centerX = (Constants::viewWidth - chessBoard->boundingRect().width()) / 2;
    qreal centerY = (Constants::viewHeight - chessBoard->boundingRect().height()) / 2;

    chessBoard->setPos(centerX, centerY);
    scene->addItem(chessBoard);
    scene->views().first()->update();
    emit gameStarted();
    connect(this->chessBoard, &ChessBoard::signalBoxClicked, this, &ChessBoardWidget::handleSquareClicked);

    // undo button
    undoButton = new ActionButton("Undo");
    double buttonXPosition = chessBoard->boundingRect().width() - 450;
    double buttonYPosition = 275;
    undoButton->setPos(buttonXPosition, buttonYPosition);

    connect(undoButton, &ActionButton::buttonPressed, this, &ChessBoardWidget::undoRequest);
    scene->addItem(undoButton);
    undoButton->setVisible(true);

    // reset button
    resetButton = new ActionButton("Reset Game");
    double resetButtonXPosition = chessBoard->boundingRect().width() - 450;
    double resetButtonYPosition = 325;
    resetButton->setPos(resetButtonXPosition, resetButtonYPosition);

    connect(resetButton, SIGNAL(buttonPressed()), this, SLOT(initializeChessBoard()));
    scene->addItem(resetButton);

    //adding promotion button;
    this->queenButton = new ActionButton("Queen");
    double queenButtonXPosition = chessBoard->boundingRect().width() + 450;
    double queenButtonYPosition = 275;
    this->queenButton->setPos(queenButtonXPosition, queenButtonYPosition);
    connect(queenButton, &ActionButton::buttonPressed, this, &ChessBoardWidget::promoteToQueen);

    //adding promotion button;
    this->bishopButton = new ActionButton("Bishop");
    double bishopButtonXPosition = chessBoard->boundingRect().width() + 450;
    double bishopButtonYPosition = 325;
    this->bishopButton->setPos(bishopButtonXPosition, bishopButtonYPosition);
    connect(bishopButton, &ActionButton::buttonPressed, this, &ChessBoardWidget::promoteToBishop);

    //adding promotion button;
    this->rookButton = new ActionButton("Rook");
    double rookButtonXPosition = chessBoard->boundingRect().width() + 450;
    double rookButtonYPosition = 375;
    this->rookButton->setPos(rookButtonXPosition, rookButtonYPosition);
    connect(rookButton, &ActionButton::buttonPressed, this, &ChessBoardWidget::promoteToRook);

    //adding promotion button;
    this->knightButton = new ActionButton("Knight");
    double knightButtonXPosition = chessBoard->boundingRect().width() + 450;
    double knightButtonYPosition = 425;
    this->knightButton->setPos(knightButtonXPosition, knightButtonYPosition);
    connect(knightButton, &ActionButton::buttonPressed, this, &ChessBoardWidget::promoteToKnight);

    scene->addItem(this->queenButton);
    scene->addItem(this->bishopButton);
    scene->addItem(this->rookButton);
    scene->addItem(this->knightButton);
    hidePromotionButtons();
}

void ChessBoardWidget::updateBoard(const QList<ChessPiece*>& chessPieces)
{
    chessBoard->updateBoard(chessPieces);
    chessBoard->restoreDefaultColor();
}

void ChessBoardWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        this->chessController->cancelMove();
        this->chessBoard->restoreDefaultColor();
    }
    QGraphicsView::mousePressEvent(event);
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
    // Start button
    ActionButton* startButton = new ActionButton("New Game");
    double buttonXPosition = this->width() / 2 - startButton->boundingRect().width() / 2;
    double buttonYPosition = 275;
    startButton->setPos(buttonXPosition, buttonYPosition);

    connect(startButton, SIGNAL(buttonPressed()), this, SLOT(initializeChessBoard()));
    scene->addItem(startButton);
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

void ChessBoardWidget::hidePromotionButtons()
{
    queenButton->setVisible(false);
    bishopButton->setVisible(false);
    rookButton->setVisible(false);
    knightButton->setVisible(false);
}


