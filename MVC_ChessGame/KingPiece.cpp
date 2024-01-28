#include "KingPiece.h"

KingPiece::KingPiece(Position position, Player player, PieceType pieceType):ChessPiece(position, player, pieceType)
{
}

bool KingPiece::validateMove(Position positionToMove, QList<ChessPiece*> chessPieces)
{
    if (this->firstMoveTaken())
    {
        return validateOneFieldMove(positionToMove, chessPieces);
    }
    else
    {
        if (abs(this->getPosition().x - positionToMove.x) == 2)
        {
            // castling
            ChessPiece* leftRook = nullptr;
            ChessPiece* rightRook = nullptr;

            Position posOfTheLeftRook = { 0, this->getPosition().y };
            Position posOfTheRightRook = { 7, this->getPosition().y };

            for (auto piece : chessPieces)
            {
                if (piece->getPosition().x == posOfTheLeftRook.x && piece->getPosition().y == posOfTheLeftRook.y)
                {
                    leftRook = piece;
                }
                else if (piece->getPosition().x == posOfTheRightRook.x && piece->getPosition().y == posOfTheRightRook.y)
                {
                    rightRook = piece;
                }
            }
            if (positionToMove.x == 2 && positionToMove.y == this->getPosition().y)
            {
                if (leftRook)
                {
                    // check if left rook has taken a first move
                    if (!leftRook->firstMoveTaken())
                    {
                        bool pathClear = true;
                        for (int x = 1; x < 4; x++)
                        {
                            Position posToCheckOnPath = { x, this->getPosition().y };

                            for (auto piece : chessPieces)
                            {
                                if (piece->getPosition().x == posToCheckOnPath.x && piece->getPosition().y == posToCheckOnPath.y)
                                {
                                    pathClear = false;
                                    break;
                                }
                            }
                        }
                        if (pathClear)
                        {
                            return true;
                        }
                    }
                }            
            }
            else if(positionToMove.x == 6 && positionToMove.y == this->getPosition().y)
            {
                if (rightRook)
                {
                    // check if left rook has taken a first move
                    if (!rightRook->firstMoveTaken() && rightRook)
                    {
                        bool pathClear = true;
                        for (int x = 5; x < 7; x++)
                        {
                            Position posToCheckOnPath = { x, this->getPosition().y };

                            for (auto piece : chessPieces)
                            {
                                if (piece->getPosition().x == posToCheckOnPath.x && piece->getPosition().y == posToCheckOnPath.y)
                                {
                                    pathClear = false;
                                    break;
                                }
                            }
                        }
                        if (pathClear)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        else
        {
            return validateOneFieldMove(positionToMove, chessPieces);
        }
    }
}

ChessPiece* KingPiece::deepCopy() const
{
    ChessPiece* copiedPiece = new KingPiece(this->getPosition(), this->getPlayer(), this->getPieceType());
    if (this->firstMoveTaken())
    {
        copiedPiece->setFirstMoveTaken();
    }
    return copiedPiece;
}
