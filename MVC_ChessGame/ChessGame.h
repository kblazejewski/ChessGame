#pragma once

#include <QObject> 
#include <qlist.h>
#include "ChessPiece.h"
#include "ChessBoardModel.h"

/**
 * @brief The ChessGame class represents the logic and state of a chess game.
 */
class ChessGame : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for ChessGame.
     */
    ChessGame();

    /**
     * @brief Makes a move on the chessboard.
     * @param posFrom The starting position of the move.
     * @param posTo The destination position of the move.
     */
    void makeMove(Position posFrom, Position posTo);

    /**
     * @brief Gets the chess piece at the specified position for the active player.
     * @param position The position on the chessboard.
     * @return Pointer to the chess piece at the specified position for the active player.
     */
    ChessPiece* getPieceAtPositionActivePlayer(Position position);

    /**
     * @brief Saves the current round to the game history.
     */
    void saveRound();

    /**
     * @brief Promotes a pawn to the specified piece type.
     * @param type The type to which the pawn should be promoted.
     */
    void promotePawn(PieceType type);

public slots:
    /**
     * @brief Starts a new game.
     */
    void startGame();

    /**
     * @brief Undoes the last move.
     */
    void undoMove();

signals:
    /**
     * @brief Signal emitted to update the graphical representation of the chessboard.
     * @param chessPieces The list of chess pieces on the board.
     */
    void updateBoard(const QList<ChessPiece*> chessPieces);

    /**
     * @brief Signal emitted when the game is over.
     * @param winner The player who won the game.
     */
    void gameOver(Player& winner);

    /**
     * @brief Signal emitted when pawn promotion is active.
     */
    void promotionActive();

private:
    QList<QList<ChessPiece*>> gameHistory; /**< List of game rounds. */
    ChessBoardModel chessBoardModel; /**< The model representing the chessboard. */
    bool gameStarted; /**< Flag indicating whether the game has started. */
    bool gamePaused; /**< Flag indicating whether the game is paused. */
    Player winner; /**< The player who won the game. */

    /**
     * @brief Clears the game history.
     */
    void clearGameHistory();
};
