#include "ChessController.h"

ChessController::ChessController()
{
    // Initialization
    this->chessBoardWidget = new ChessBoardWidget(this);
    this->chessGame = new ChessGame();
    this->positionFromActive = false;
    this->positionToActive = false;

    // Connect signals and slots
    connect(this->chessBoardWidget, SIGNAL(gameStarted()), this->chessGame, SLOT(startGame()));
    connect(this->chessGame, SIGNAL(updateBoard(const QList<ChessPiece*>&)), this->chessBoardWidget, SLOT(updateBoard(const QList<ChessPiece*>&)));
    connect(this->chessGame, &ChessGame::gameOver, this->chessBoardWidget, &ChessBoardWidget::showWinnerPanel);
    connect(this->chessBoardWidget, &ChessBoardWidget::undoRequest, this->chessGame, &ChessGame::undoMove);
    connect(this->chessGame, &ChessGame::promotionActive, this->chessBoardWidget, &ChessBoardWidget::showPromotionButtons);
    connect(this->chessBoardWidget, &ChessBoardWidget::promoteToQueen, this, &ChessController::handlePromoteToQueen);
    connect(this->chessBoardWidget, &ChessBoardWidget::promoteToBishop, this, &ChessController::handlePromoteToBishop);
    connect(this->chessBoardWidget, &ChessBoardWidget::promoteToRook, this, &ChessController::handlePromoteToRook);
    connect(this->chessBoardWidget, &ChessBoardWidget::promoteToKnight, this, &ChessController::handlePromoteToKnight);
}

ChessBoardWidget* ChessController::getChessBoardWidget()
{
    return this->chessBoardWidget;
}

void ChessController::handleBoxClicked(Position position)
{
    if (this->chessGame->getPieceAtPositionActivePlayer(position))
    {
        // If a piece is clicked, store its position and mark possible moves on the ChessBoardWidget.
        this->positionFrom = this->chessGame->getPieceAtPositionActivePlayer(position)->getPosition();
        this->positionFromActive = true;
        this->chessBoardWidget->markPossibleMoves(this->chessGame->getPieceAtPositionActivePlayer(position));
        return;
    }

    // If the source position is already set, execute the move.
    if (positionFromActive)
    {
        this->positionTo = position;
        this->positionToActive = true;
        this->chessGame->makeMove(positionFrom, positionTo);

        // Reset flags.
        this->positionFromActive = false;
        this->positionToActive = false;
    }
}

void ChessController::cancelMove()
{
    // Reset flags to cancel the current move.
    this->positionFromActive = false;
    this->positionToActive = false;
}

void ChessController::handlePromoteToQueen()
{
    // Promote the pawn to a queen and hide the promotion buttons.
    this->chessGame->promotePawn(PieceType::Queen);
    this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToBishop()
{
    // Promote the pawn to a bishop and hide the promotion buttons.
    this->chessGame->promotePawn(PieceType::Bishop);
    this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToRook()
{
    // Promote the pawn to a rook and hide the promotion buttons.
    this->chessGame->promotePawn(PieceType::Rook);
    this->chessBoardWidget->hidePromotionButtons();
}

void ChessController::handlePromoteToKnight()
{
    // Promote the pawn to a knight and hide the promotion buttons.
    this->chessGame->promotePawn(PieceType::Knight);
    this->chessBoardWidget->hidePromotionButtons();
}