#pragma once

#include <QAbstractGraphicsShapeItem>
#include <QColor>
#include <QFont>

/**
 * @brief The Utils class provides utility functions for graphical items.
 */
class Utils
{
public:
    /**
     * @brief Sets the background color of a QAbstractGraphicsShapeItem.
     * @param color The background color to set.
     * @param item The QAbstractGraphicsShapeItem whose background color will be set.
     */
    static void setBacgroundColor(QColor color, QAbstractGraphicsShapeItem* item);

    /**
     * @brief Creates a QGraphicsTextItem with the specified title, font size, and text color.
     * @param title The text content of the item.
     * @param fontSize The font size of the text.
     * @param textColor The color of the text.
     * @param parent The parent QGraphicsItem.
     * @return A pointer to the created QGraphicsTextItem.
     */
    static QGraphicsTextItem* createTextItem(QString title, int fontSize, QColor textColor, QGraphicsItem* parent = nullptr);
};

