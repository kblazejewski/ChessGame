#pragma once
#include "ChessPiece.h"
#include "Position.h"

/**
 * @brief The QueenPiece class represents the queen chess piece.
 */
class QueenPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for QueenPiece.
     * @param position The initial position of the queen piece.
     * @param player The player to whom the queen piece belongs.
     * @param pieceType The type of the queen piece.
     */
    QueenPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the queen piece to the specified position.
     * @param positionToMove The position to which the queen piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the queen piece.
     * @return Pointer to the deep copy of the queen piece.
     */
    virtual ChessPiece* deepCopy() override;
};
