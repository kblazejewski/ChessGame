#pragma once
#include "ChessPiece.h"

/**
 * @brief The KingPiece class represents the king chess piece.
 */
class KingPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for KingPiece.
     * @param position The initial position of the king piece.
     * @param player The player to whom the king piece belongs.
     * @param pieceType The type of the king piece.
     */
    KingPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the king piece to the specified position.
     * @param positionToMove The position to which the king piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the king piece.
     * @return Pointer to the deep copy of the king piece.
     */
    virtual ChessPiece* deepCopy() override;
};
