#pragma once
#include "ChessPiece.h"

/**
 * @brief The BishopPiece class represents the bishop chess piece.
 */
class BishopPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for BishopPiece.
     * @param position The initial position of the bishop piece.
     * @param player The player to whom the bishop piece belongs.
     * @param pieceType The type of the bishop piece.
     */
    BishopPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the bishop piece to the specified position.
     * @param positionToMove The position to which the bishop piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the bishop piece.
     * @return Pointer to the deep copy of the bishop piece.
     */
    virtual ChessPiece* deepCopy() override;
};
