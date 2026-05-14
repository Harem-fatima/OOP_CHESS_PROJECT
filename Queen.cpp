#include "ChessPieces.h"

// ==========================================
// Queen Class
// ==========================================

Queen::Queen(bool white) : Piece(white, 'Q') {}

bool Queen::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    // Straight movement
    if (startR == endR || startC == endC)
    {
        int rowStep = 0;
        int colStep = 0;

        if (endR > startR)
            rowStep = 1;
        else if (endR < startR)
            rowStep = -1;

        if (endC > startC)
            colStep = 1;
        else if (endC < startC)
            colStep = -1;

        int r = startR + rowStep;
        int c = startC + colStep;

        while (r != endR || c != endC)
        {
            if (board[r][c] != nullptr)
                return false;

            r += rowStep;
            c += colStep;
        }
        return true;
    }
    // Diagonal movement
    if (abs(endR - startR) == abs(endC - startC))
    {
        int rowStep;
        int colStep;
        if (endR > startR)
            rowStep = 1;
        else
            rowStep = -1;
        if (endC > startC)
            colStep = 1;
        else
            colStep = -1;
        int r = startR + rowStep;
        int c = startC + colStep;
        while (r != endR && c != endC)
        {
            if (board[r][c] != nullptr)
                return false;

            r += rowStep;
            c += colStep;
        }
        return true;
    }
    return false;
}
