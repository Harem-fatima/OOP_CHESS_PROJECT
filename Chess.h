// ==========================================
// Semester Project: Chess Game in C++
// Part 1: Piece Definitions and Logic
// Prepared by: Sahrish batool
// ==========================================
#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// Parent class for all chess pieces
class Piece
{
protected:
    bool isWhite; // true if white team, false if black
    char symbol;  // 'P', 'R', 'N', 'B', 'Q', 'K'
public:
    Piece(bool white, char sym);
    virtual ~Piece();
    // Pure virtual function: Each piece defines its own movement rules
    virtual bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) = 0;
    char getSymbol();
    bool getIsWhite();
};
// --- Specialized Piece Classes ---
class Pawn : public Piece
{
public:
    Pawn(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
class Rook : public Piece 
{
public:
    Rook(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
class Knight : public Piece 
{
public:
    Knight(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
class Bishop : public Piece 
{
public:
    Bishop(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
class Queen : public Piece
{
public:
    Queen(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
class King : public Piece 
{
public:
    King(bool white);
    bool isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) override;
};
#endif
