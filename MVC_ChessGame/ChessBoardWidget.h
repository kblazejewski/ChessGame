#pragma once

#include <QGraphicsView>
#include "ChessBoard.h"
#include "Position.h"
#include "ChessController.h"
#include "qlist.h"
#include "ChessPiece.h"
#include "ChessPieceBox.h"
#include <QMouseEvent>
#include "ChessBox.h"
#include "ActionButton.h"

class ActionButton;
class ChessController;

/**
 * @brief The ChessBoardWidget class represents the graphical user interface for the chess game.
 */
class ChessBoardWidget : public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for ChessBoardWidget.
     * @param chessController The associated ChessController instance.
     * @param parent The parent widget.
     */
    ChessBoardWidget(ChessController* chessController, QWidget* parent = nullptr);

    /**
     * @brief Marks the possible moves for the given chess piece on the chessboard.
     * @param piece The chess piece for which possible moves will be marked.
     */
    void markPossibleMoves(ChessPiece* piece);

public slots:
    /**
     * @brief Initializes the chessboard and starts the game.
     */
    void initializeChessBoard();

    /**
     * @brief Updates the chessboard with the current state of the game.
     * @param chessPieces The list of chess pieces on the board.
     */
    void updateBoard(const QList<ChessPiece*>& chessPieces);

    /**
     * @brief Handles the click event on a chessboard square.
     * @param position The position of the clicked square.
     */
    void handleSquareClicked(const Position& position);

    /**
     * @brief Displays the winner panel with the winning player's name.
     * @param winner The winning player.
     */
    void showWinnerPanel(Player& winner);

    /**
     * @brief Quits the game.
     */
    void quit();

    /**
     * @brief Shows the promotion buttons when a pawn reaches the end of the board.
     */
    void showPromotionButtons();

    /**
     * @brief Hides the promotion buttons.
     */
    void hidePromotionButtons();

signals:
    /**
     * @brief Signal emitted when the game is started.
     */
    void gameStarted();

    /**
     * @brief Signal emitted when an undo move is requested.
     */
    void undoRequest();

    /**
     * @brief Signal emitted when a pawn is promoted to a queen.
     */
    void promoteToQueen();

    /**
     * @brief Signal emitted when a pawn is promoted to a rook.
     */
    void promoteToRook();

    /**
     * @brief Signal emitted when a pawn is promoted to a bishop.
     */
    void promoteToBishop();

    /**
     * @brief Signal emitted when a pawn is promoted to a knight.
     */
    void promoteToKnight();

private:
    QGraphicsScene* scene; /**< The graphics scene for the chessboard. */
    ChessBoard* chessBoard; /**< The chessboard instance. */
    ChessController* chessController; /**< The associated ChessController instance. */
    ActionButton* queenButton; /**< Promotion button for Queen. */
    ActionButton* rookButton; /**< Promotion button for Rook. */
    ActionButton* bishopButton; /**< Promotion button for Bishop. */
    ActionButton* knightButton; /**< Promotion button for Knight. */
    ActionButton* undoButton; /**< Button to request an undo move. */
    ActionButton* resetButton; /**< Button to reset the game. */

    /**
     * @brief Handles the mouse press event on the chessboard view.
     * @param event The mouse press event.
     */
    void mousePressEvent(QMouseEvent* event);

    /**
     * @brief Initializes the background color of the chessboard.
     */
    void initializeBackgroundColor();

    /**
     * @brief Displays the initial menu with the start button.
     */
    void displayMenu();

    /**
     * @brief Draws the title of the chess game.
     */
    void drawTitle();
};
