#include "ChessPieces.h"
// ==========================================
// Bishop Class
// ==========================================
Bishop::Bishop(bool white) : Piece(white, 'B')
{}
bool Bishop::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    if (abs(endR - startR) != abs(endC - startC))
        return false;
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
