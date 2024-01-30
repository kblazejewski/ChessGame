#pragma once
#include "ChessPiece.h"
#include "Position.h"

/**
 * @brief The RookPiece class represents the rook chess piece.
 */
class RookPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for RookPiece.
     * @param position The initial position of the rook piece.
     * @param player The player to whom the rook piece belongs.
     * @param pieceType The type of the rook piece.
     */
    RookPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the rook piece to the specified position.
     * @param positionToMove The position to which the rook piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the rook piece.
     * @return Pointer to the deep copy of the rook piece.
     */
    virtual ChessPiece* deepCopy() override;
};
