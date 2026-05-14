#ifndef PIECE_H
#define PIECE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Piece
{
protected:
    bool isWhite;
    char symbol;
public:
    Piece(bool white, char sym);
    virtual ~Piece();
    virtual bool isValidMove(int startR, int startC, int endR, int endC,Piece* board[8][8] ) = 0;
    char getSymbol();
    bool getIsWhite();
};
#endif
