#pragma once

#include "ChessGame.h"
#include "ChessBoardWidget.h"
#include <qobject.h>
#include "Position.h"

class ChessBoardWidget;

/**
 * @brief The ChessController class handles the communication between the ChessGame logic and the ChessBoardWidget GUI.
 */
class ChessController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for ChessController.
     */
    ChessController();

    /**
     * @brief Gets the ChessBoardWidget associated with the ChessController.
     * @return A pointer to the ChessBoardWidget.
     */
    ChessBoardWidget* getChessBoardWidget();

    /**
     * @brief Handles the click event on a chessboard box.
     * @param position The position of the clicked box.
     */
    void handleBoxClicked(Position position);

    /**
     * @brief Cancels the current move in progress.
     */
    void cancelMove();

public slots:
    /**
     * @brief Slot to handle promoting a pawn to a queen.
     */
    void handlePromoteToQueen();

    /**
     * @brief Slot to handle promoting a pawn to a bishop.
     */
    void handlePromoteToBishop();

    /**
     * @brief Slot to handle promoting a pawn to a rook.
     */
    void handlePromoteToRook();

    /**
     * @brief Slot to handle promoting a pawn to a knight.
     */
    void handlePromoteToKnight();

private:
    Position positionFrom; /**< Stores the position from which a piece is selected for a move. */
    bool positionFromActive; /**< Flag indicating if a piece for the move has been selected. */
    Position positionTo; /**< Stores the destination position for a move. */
    bool positionToActive; /**< Flag indicating if the destination position for a move has been selected. */
    ChessGame* chessGame; /**< Pointer to the ChessGame instance. */
    ChessBoardWidget* chessBoardWidget; /**< Pointer to the associated ChessBoardWidget instance. */
};