#ifndef KING_H
#define KING_H
#include "Piece.h"
// ==========================================
// King Class
// ==========================================
class King : public Piece
{
public:
    King(bool white);
    bool isValidMove( int startR, int startC, int endR,  int endC,Piece* board[8][8] ) override;
};

#endif
