#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

/**
 * @brief The ActionButton class represents a clickable button in the graphical user interface.
 */
class ActionButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for ActionButton.
     * @param title The text content of the button.
     */
    ActionButton(QString title);

    /**
     * @brief Handles the mouse press event on the button.
     * @param event The mouse press event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    /**
     * @brief Handles the hover enter event on the button.
     * @param event The hover enter event.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);

    /**
     * @brief Handles the hover leave event on the button.
     * @param event The hover leave event.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    /**
     * @brief Signal emitted when the button is pressed.
     */
    void buttonPressed();
};
