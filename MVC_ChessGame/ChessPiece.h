#pragma once

#include <qstring.h>
#include "Position.h"
#include <qlist.h>

/**
 * @brief Enumeration representing the types of chess pieces.
 */
enum PieceType
{
    Pawn, Rook, Bishop, Knight, Queen, King
};

/**
 * @brief Enumeration representing the players in chess.
 */
enum Player
{
    Black, White, None
};

/**
 * @brief The ChessPiece class represents a generic chess piece.
 */
class ChessPiece
{
private:
    Position position; /**< The current position of the chess piece on the chessboard. */
    bool didTakeFirstMove; /**< Flag indicating whether the piece has made its first move. */
    Player player; /**< The player to whom the chess piece belongs (Black, White, or None). */
    QList<Position> possibleMoves; /**< List of possible moves for the chess piece. */
    PieceType type; /**< The type of the chess piece (Pawn, Rook, Bishop, Knight, Queen, King). */

public:
    /**
     * @brief Constructor for ChessPiece.
     * @param position The initial position of the chess piece.
     * @param player The player to whom the chess piece belongs.
     * @param pieceType The type of the chess piece.
     */
    ChessPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Virtual destructor for ChessPiece.
     */
    virtual ~ChessPiece() = default;

    /**
     * @brief Gets the list of possible moves for the chess piece.
     * @return List of possible moves.
     */
    const QList<Position> getPossibleMoves() const;

    /**
     * @brief Sets the list of possible moves for the chess piece.
     * @param legalMoves The list of legal moves.
     */
    void setPossibleMoves(QList<Position> legalMoves);

    /**
     * @brief Gets the type of the chess piece.
     * @return The type of the chess piece.
     */
    const PieceType getPieceType() const;

    /**
     * @brief Gets the player to whom the chess piece belongs.
     * @return The player (Black, White, or None).
     */
    const Player getPlayer() const;

    /**
     * @brief Gets the current position of the chess piece on the chessboard.
     * @return The current position.
     */
    const Position getPosition() const;

    /**
     * @brief Sets the position of the chess piece on the chessboard.
     * @param position The new position.
     */
    void setPosition(Position position);

    /**
     * @brief Validates the move of the chess piece to the specified position.
     * @param positionToMove The position to which the chess piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) = 0;

    /**
     * @brief Sets the flag indicating that the first move has been taken.
     */
    void setFirstMoveTaken();

    /**
     * @brief Checks whether the first move has been taken.
     * @return True if the first move has been taken, false otherwise.
     */
    const bool firstMoveTaken() const;

    /**
     * @brief Creates a deep copy of the chess piece.
     * @return Pointer to the deep copy of the chess piece.
     */
    virtual ChessPiece* deepCopy() = 0;

protected:
    /**
     * @brief Validates a diagonal move for the chess piece.
     * @param positionToMove The position to which the chess piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the diagonal move is valid, false otherwise.
     */
    const bool validateDiagonalMove(Position positionToMove, QList<ChessPiece*> chessPieces);

    /**
     * @brief Validates a vertical or horizontal move for the chess piece.
     * @param positionToMove The position to which the chess piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the vertical or horizontal move is valid, false otherwise.
     */
    const bool validateVerticalOrHorizontalMove(Position positionToMove, QList<ChessPiece*> chessPieces);

    /**
     * @brief Validates a one-field move for the chess piece.
     * @param positionToMove The position to which the chess piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the one-field move is valid, false otherwise.
     */
    const bool validateOneFieldMove(Position positionToMove, QList<ChessPiece*> chessPieces);

    /**
     * @brief Validates the intersection with another chess piece for the chess piece.
     * @param positionToMove The position to which the chess piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the intersection is valid, false otherwise.
     */
    const bool validateAnotherPieceIntersection(Position positionToMove, QList<ChessPiece*> chessPieces);
};
