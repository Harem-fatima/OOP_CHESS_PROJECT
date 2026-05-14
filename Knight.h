#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
// ==========================================
// Knight Class
// ==========================================
class Knight : public Piece
{
public:
    Knight(bool white);
  bool isValidMove( int startR, int startC,  int endR,  int endC,   Piece* board[8][8]) override;
};
#endif
