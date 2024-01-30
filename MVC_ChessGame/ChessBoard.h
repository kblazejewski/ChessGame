#pragma once

#include <QObject>
#include <QGraphicsItemGroup>
#include <qgraphicsscene.h>
#include <qlist.h>
#include "ChessBox.h"
#include "ChessPieceBox.h"
#include "ChessPiece.h"
#include "qpointer.h"
#include <qstring.h>
#include "ChessPiece.h"

/**
 * @brief The ChessBoard class represents the chessboard in the graphical user interface.
 */
class ChessBoard : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
private:
    QGraphicsScene* scene; /**< The graphics scene containing the chessboard. */
    QList<ChessBox*> chessBoxes; /**< List of individual squares on the chessboard. */
    QList<ChessPieceBox*> chessPieceBoxes; /**< List of graphical items representing chess pieces. */

    /**
     * @brief Draws the initial configuration of the chessboard.
     */
    void draw();

    /**
     * @brief Gets the file path to the image representing a chess piece.
     * @param piece The chess piece.
     * @return The file path to the image.
     */
    QString getImagePath(ChessPiece* piece);

    /**
     * @brief Deletes all graphical items representing chess pieces.
     */
    void deletePieceBoxes();

    /**
     * @brief Gets the ChessBox at the specified position.
     * @param position The position on the chessboard.
     * @return Pointer to the ChessBox at the specified position.
     */
    ChessBox* getBoxAtPosition(Position position);

signals:
    /**
     * @brief Signal emitted when a chessbox is clicked.
     * @param position The position of the clicked chessbox.
     */
    void signalBoxClicked(const Position& position);

public slots:
    /**
     * @brief Slot function called when a chessbox is clicked.
     * @param position The position of the clicked chessbox.
     */
    void boxClicked(const Position& position);

public:
    /**
     * @brief Updates the chessboard with the current state of the game.
     * @param chessPieces The list of chess pieces on the board.
     */
    void updateBoard(const QList<ChessPiece*> chessPieces);

    /**
     * @brief Constructor for ChessBoard.
     * @param sceneIn The QGraphicsScene containing the chessboard.
     * @param parent The parent QGraphicsItem.
     */
    ChessBoard(QGraphicsScene* sceneIn, QGraphicsItem* parent = nullptr);

    /**
     * @brief Changes the color of chessboard squares to indicate pieces under attack.
     * @param piece The chess piece under attack.
     */
    void changeColorUnderAttack(ChessPiece* piece);

    /**
     * @brief Restores the default background color of all chessboard squares.
     */
    void restoreDefaultColor();
};
