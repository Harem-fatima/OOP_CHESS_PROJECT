#include "ChessPieces.h"
// ==========================================
// Rook Class
// ==========================================
Rook::Rook(bool white) : Piece(white, 'R')
{}
bool Rook::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    if (startR != endR && startC != endC)
        return false;
    // Horizontal movement
    if (startR == endR)
    {
        int step;
        if (endC > startC)
            step = 1;
        else
            step = -1;
        for (int c = startC + step; c != endC; c += step)
        {
            if (board[startR][c] != nullptr)
                return false;
        }
    }
    // Vertical movement
    if (startC == endC)
    {
        int step;
        if (endR > startR)
            step = 1;
        else
            step = -1;
        for (int r = startR + step; r != endR; r += step)
        {
            if (board[r][startC] != nullptr)
                return false;
        }
    }
    return true;
}
