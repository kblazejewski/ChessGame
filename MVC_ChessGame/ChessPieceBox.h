#pragma once

#include <qgraphicsitem.h>
#include <qlabel.h>
#include "Position.h"

/**
 * @brief The ChessPieceBox class represents a graphical item displaying a chess piece on the chessboard.
 */
class ChessPieceBox :
    public QGraphicsRectItem
{
private:
    Position position; ///< The position of the chess piece on the chessboard.
    QLabel* imageLabel; ///< The label displaying the chess piece's image.
    QPixmap image; ///< The image representing the chess piece.

public:
    /**
     * @brief Constructor for ChessPieceBox.
     * @param position The position of the chess piece on the chessboard.
     * @param imagePath The file path to the image representing the chess piece.
     * @param parent The parent QGraphicsItem.
     */
    ChessPieceBox(Position position, QString imagePath, QGraphicsItem* parent = nullptr);
};
