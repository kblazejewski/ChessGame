#pragma once

#include <qlist.h>
#include "ChessPiece.h"
#include "Position.h"

/**
 * @brief The ChessBoardModel class represents the state and logic of the chessboard.
 */
class ChessBoardModel
{
private:
    QList<ChessPiece*> pieces; /**< List of chess pieces on the chessboard. */
    Player whosTurn; /**< The player whose turn it is to make a move. */
    Position enPassantCapturePosition; /**< Position for en passant capture. */
    Position enPassantMovePosition; /**< Position for en passant move. */

public:
    // En passant logic

    /**
     * @brief Sets the en passant capture position.
     * @param position The position for en passant capture.
     */
    void setEnPassantCapturePosition(Position position);

    /**
     * @brief Gets the en passant capture position.
     * @return The position for en passant capture.
     */
    const Position getEnPassantCapturePositon() const;

    /**
     * @brief Sets the en passant move position.
     * @param position The position for en passant move.
     */
    void setEnPassantMovePosition(Position position);

    /**
     * @brief Gets the en passant move position.
     * @return The position for en passant move.
     */
    const Position getEnPassantMovePosition() const;

    /**
     * @brief Clears en passant data.
     */
    void clearEnPassantData();

    // General chessboard operations

    /**
     * @brief Gets the chess piece at the specified position.
     * @param position The position on the chessboard.
     * @return Pointer to the chess piece at the specified position.
     */
    ChessPiece* getPieceAt(Position position);

    /**
     * @brief Gets the chess piece at the specified position from a given list of chess pieces.
     * @param position The position on the chessboard.
     * @param chessPieces The list of chess pieces to search.
     * @return Pointer to the chess piece at the specified position.
     */
    ChessPiece* getPieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces);

    /**
     * @brief Removes the chess piece at the specified position.
     * @param position The position on the chessboard.
     */
    void removePieceAt(Position position);

    /**
     * @brief Removes the chess piece at the specified position from a given list of chess pieces.
     * @param position The position on the chessboard.
     * @param chessPieces The list of chess pieces to search.
     */
    void removePieceAtGivenPosition(Position position, QList<ChessPiece*> chessPieces);

    /**
     * @brief Moves a chess piece to the specified position.
     * @param piece The chess piece to move.
     * @param position The destination position.
     */
    void movePieceTo(ChessPiece* piece, Position position);

    /**
     * @brief Constructor for ChessBoardModel.
     */
    ChessBoardModel();

    /**
     * @brief Gets a list of all chess pieces on the chessboard.
     * @return List of chess pieces.
     */
    QList<ChessPiece*> getPieces();

    /**
     * @brief Gets the player whose turn it is to make a move.
     * @return The current player.
     */
    const Player getWhosTurn();

    /**
     * @brief Switches the turn to the other player.
     */
    void switchTurn();

    /**
     * @brief Calculates possible moves for all chess pieces on the chessboard.
     */
    void calculatePossibleMoves();

    /**
     * @brief Calculates possible moves for chess pieces at a given position from a given list.
     * @param chessPieces The list of chess pieces.
     */
    void calculatePossibleMovesForGivenPosition(QList<ChessPiece*> chessPieces);

    /**
     * @brief Gets a deep copy of the current chessboard position.
     * @return Deep copy of the current position.
     */
    QList<ChessPiece*> getCopyOfCurrentPosition();

    /**
     * @brief Restores the chessboard to a given position.
     * @param chessPieces The list of chess pieces representing the desired position.
     */
    void restorePosition(QList<ChessPiece*> chessPieces);

    /**
     * @brief Checks if the king of the specified player is in check in a given position.
     * @param player The player to check.
     * @param chessPieces The list of chess pieces representing the position.
     * @return True if the king is in check, false otherwise.
     */
    const bool isKingInCheckInGivenPosition(Player player, QList<ChessPiece*> chessPieces) const;

    /**
     * @brief Checks if the game is in checkmate for the specified player.
     * @param player The player to check for checkmate.
     * @return True if checkmate, false otherwise.
     */
    const bool isCheckMate(Player player) const;

    /**
     * @brief Checks if pawn promotion is available.
     * @return True if promotion is available, false otherwise.
     */
    const bool isPromotionAvailable() const;

    /**
     * @brief Promotes a pawn to the specified piece type.
     * @param pieceType The type to which the pawn should be promoted.
     */
    void promotePawn(PieceType pieceType);

    /**
     * @brief Performs castling for the specified player.
     * @param player The player to perform castling for.
     * @param isShortCastle True for short castling, false for long castling.
     */
    void performCastle(Player player, bool isShortCastle);

    /**
     * @brief Restores all pawns' vulnerabilities.
     */
    void restoreAllPawnsVulnerablnes();

    /**
     * @brief Initializes the chess pieces on the chessboard.
     */
    void initializePieces();
};
