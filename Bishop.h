#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
// ==========================================
// Bishop Class
// ==========================================
class Bishop : public Piece
{
public:
    Bishop(bool white);
    bool isValidMove( int startR, int startC, int endR, int endC, Piece* board[8][8] ) override;
};
#endif
