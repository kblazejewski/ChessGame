#pragma once

#include <qcolor.h>

/**
 * @brief The Constants class provides a set of static constants used in the chess game.
 */
class Constants
{
public:
    static int numberOfRowsCols; /**< Number of rows and columns on the chessboard. */
    static int defaultMargin; /**< Default margin for chessboard squares. */
    static int defaultWidhHeight; /**< Default width and height of chessboard squares. */
    static int startXPosition; /**< Starting X position of the chessboard. */
    static int startYPosition; /**< Starting Y position of the chessboard. */
    static int viewWidth; /**< Width of the chessboard view. */
    static int viewHeight; /**< Height of the chessboard view. */
    static QColor defaultTextColor; /**< Default text color. */
    static QColor lightBoxColor; /**< Color of light-colored chessboard squares. */
    static QColor darkBoxColor; /**< Color of dark-colored chessboard squares. */
};
