#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->chessBoardWidget = new ChessBoardWidget(this);
    setCentralWidget(this->chessBoardWidget);
}

MainWindow::~MainWindow()
{}
