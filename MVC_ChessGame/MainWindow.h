#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
//#include "ChessBoardWidget.h"
#include "ChessController.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindowClass ui;
    //ChessBoardWidget* chessBoardWidget;
    ChessController* chessController;
};
