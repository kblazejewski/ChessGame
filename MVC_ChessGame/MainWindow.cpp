#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //this->chessBoardWidget = new ChessBoardWidget(this);
    //setCentralWidget(this->chessBoardWidget);
    this->chessController = new ChessController();
    setCentralWidget(this->chessController->getChessBoardWidget());
    resize(centralWidget()->size());
    setFixedSize(size());
}

MainWindow::~MainWindow()
{}
