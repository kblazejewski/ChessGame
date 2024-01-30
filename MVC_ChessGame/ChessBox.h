#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Position.h"
#include <qcolor.h>
#include <qobject.h>

/**
 * @brief The ChessBox class represents a single square on the chessboard.
 */
class ChessBox : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    Position position; /**< The position of the chessbox on the chessboard. */
    QColor defaultColor; /**< The default background color of the chessbox. */

public:
    /**
     * @brief Constructor for ChessBox.
     * @param backgroundColor The initial background color of the chessbox.
     * @param position The position of the chessbox on the chessboard.
     * @param parent The parent QGraphicsItem.
     */
    ChessBox(QColor backgroundColor, Position position, QGraphicsItem* parent = nullptr);

    /**
     * @brief Sets the position of the chessbox.
     * @param position The new position of the chessbox.
     */
    void setPosition(Position position);

    /**
     * @brief Gets the position of the chessbox.
     * @return The position of the chessbox.
     */
    const Position getPosition();

    /**
     * @brief Changes the background color of the chessbox to indicate it is under attack.
     */
    void changeColorUnderAttack();

    /**
     * @brief Restores the default background color of the chessbox.
     */
    void restoreDefaultColor();

    /**
     * @brief Detect mouse click.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    /**
     * @brief Signal emitted when the chessbox is clicked.
     * @param position The position of the clicked chessbox.
     */
    void boxClicked(const Position& position);
};
