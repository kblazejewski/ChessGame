#pragma once
#include "ChessPiece.h"

/**
 * @brief The PawnPiece class represents the pawn chess piece.
 */
class PawnPiece :
    public ChessPiece
{
public:
    /**
     * @brief Constructor for PawnPiece.
     * @param position The initial position of the pawn piece.
     * @param player The player to whom the pawn piece belongs.
     * @param pieceType The type of the pawn piece.
     */
    PawnPiece(Position position, Player player, PieceType pieceType);

    /**
     * @brief Validates the move of the pawn piece to the specified position.
     * @param positionToMove The position to which the pawn piece is to be moved.
     * @param chessPieces The list of all chess pieces on the chessboard.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool validateMove(Position positionToMove, QList<ChessPiece*> chessPieces) override;

    /**
     * @brief Creates a deep copy of the pawn piece.
     * @return Pointer to the deep copy of the pawn piece.
     */
    virtual ChessPiece* deepCopy() override;

    /**
     * @brief Sets the pawn piece as vulnerable to en passant capture.
     */
    void setEnPassantVurnelable();

    /**
     * @brief Resets the vulnerability of the pawn piece to en passant capture.
     */
    void resetEnPassantVurnelable();

private:
    bool enPassantVurnelable; ///< Flag indicating whether the pawn is vulnerable to en passant capture.
};
