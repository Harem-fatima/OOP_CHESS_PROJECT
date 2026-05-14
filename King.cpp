#include "ChessPieces.h"
// ==========================================
// King Class
// ==========================================
King::King(bool white) : Piece(white, 'K')
{}
bool King::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    int rowDiff = abs(endR - startR);
    int colDiff = abs(endC - startC);
    if (rowDiff <= 1 && colDiff <= 1)
        return true;
    return false;
}
