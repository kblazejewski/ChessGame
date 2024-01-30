#pragma once
#include "ChessPiece.h"

/**
 * @brief The KnightPiece class represents the knight chess piece.
 */
class KnightPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for KnightPiece.
     * @param position The initial position of the knight piece.
     * @param player The player to whom the knight piece belongs.
     * @param pieceType The type of the knight piece.
     */
    KnightPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the knight piece to the specified position.
     * @param positionToMove The position to which the knight piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the knight piece.
     * @return Pointer to the deep copy of the knight piece.
     */
    virtual ChessPiece* deepCopy() override;
};
