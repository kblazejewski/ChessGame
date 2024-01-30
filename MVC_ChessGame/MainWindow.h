#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "ChessController.h"

/**
 * @brief The MainWindow class represents the main window of the chess application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainWindow.
     * @param parent The parent widget.
     */
    MainWindow(QWidget* parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

private:
    Ui::MainWindowClass ui; ///< The UI object for the main window.
    ChessController* chessController; ///< The controller for the chess game.
};
