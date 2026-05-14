#include "ChessPieces.h"
// ==========================================
// Knight Class
// ==========================================
Knight::Knight(bool white) : Piece(white, 'N') 
{}
bool Knight::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    int rowDiff = abs(endR - startR);
    int colDiff = abs(endC - startC);
    if ((rowDiff == 2 && colDiff == 1) ||
        (rowDiff == 1 && colDiff == 2))
    {
        return true;
    }
    return false;
}
