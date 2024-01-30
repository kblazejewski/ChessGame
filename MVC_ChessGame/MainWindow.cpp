#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->chessController = new ChessController();
    setCentralWidget(this->chessController->getChessBoardWidget());
    resize(centralWidget()->size());
    setFixedSize(size());
}

MainWindow::~MainWindow()
{}
