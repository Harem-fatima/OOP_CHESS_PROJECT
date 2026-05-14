#include "ChessPieces.h"
// ==========================================
// Pawn Class
// ==========================================
Pawn::Pawn(bool white) : Piece(white, 'P') 
{}
bool Pawn::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    int direction;
    if (isWhite)
        direction = -1;
    else
        direction = 1;
    // Forward move
    if (startC == endC && board[endR][endC] == nullptr)
    {
        if (endR == startR + direction)
            return true;
    }
    // First double move
    if (startC == endC && board[endR][endC] == nullptr)
    {
        if (isWhite && startR == 6 && endR == 4)
            return true;
        if (!isWhite && startR == 1 && endR == 3)
            return true;
    }
    // Diagonal capture
    if (abs(startC - endC) == 1 && endR == startR + direction)
    {
        if (board[endR][endC] != nullptr)
        {
            if (board[endR][endC]->getIsWhite() != isWhite)
                return true;
        }
    }
    return false;
}
