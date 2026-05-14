#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
// ==========================================
// Pawn Class
// ==========================================
class Pawn : public Piece
{
public:
    Pawn(bool white);
    bool isValidMove( int startR, int startC,  int endR, int endC,  Piece* board[8][8] ) override;
};
#endif
