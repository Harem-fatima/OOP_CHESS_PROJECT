#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
// ==========================================
// Queen Class
// ==========================================
class Queen : public Piece
{
public:
    Queen(bool white);
    bool isValidMove( int startR, int startC,int endR, int endC, Piece* board[8][8] ) override;
};
#endif
