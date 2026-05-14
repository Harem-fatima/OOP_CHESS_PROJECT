#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
// ==========================================
// Rook Class
// ==========================================
class Rook : public Piece
{
public:
    Rook(bool white);

    bool isValidMove( int startR, int startC, int endR, int endC, Piece* board[8][8] ) override;
};
#endif
