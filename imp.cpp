// ==========================================
// Semester Project: Chess Game in C++
// Part 1: Implementation of Piece Logic
// Prepared by: Sahrish Batool
// ==========================================
#include "Chess.h"  
// BASE PIECE LOGIC
// Constructor to initialize team color and character symbol
Piece::Piece(bool white, char sym)
{
    isWhite = white;
    symbol = sym;
}
// Empty destructor for the base class
Piece::~Piece()
{
}
// Returns the character symbol of the piece 
char Piece::getSymbol()
{
    return symbol;
}
// Returns true if the piece is white, false if black
bool Piece::getIsWhite()
{
    return isWhite;
}
//SPECIFIC PIECE CONSTRUCTORS & MOVEMENT
//PAWN
Pawn::Pawn(bool white) : Piece(white, white ? 'P' : 'p')
{
}
bool Pawn::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    // White moves up the board (-1), Black moves down (+1)
    int direction = isWhite ? -1 : 1;
    // Normal one step forward move
    // we ad 3 conditions in this for first checking the coloumn
    // should remain same 2nd the end row = to start + the direction u are moving 3rd the next box should be empty
    if (startC == endC && endR == startR + direction && board[endR][endC] == nullptr)
        return true;
    // same as one step forward just check if piece are in their default row they will move 2 step else 1
    if (startC == endC && endR == startR + (2 * direction) && board[endR][endC] == nullptr && board[startR + direction][startC] == nullptr)
    {
        if ((isWhite && startR == 6) || (!isWhite && startR == 1)) return true;
    }
    // Diagonal capture move
    if (abs(startC - endC) == 1 && endR == startR + direction && board[endR][endC] != nullptr)
    {
        if (board[endR][endC]->getIsWhite() != isWhite)// to make sure it is kiling opposite team piece
            return true;
    }
    return false;
}
// ROOK
Rook::Rook(bool white) : Piece(white, white ? 'R' : 'r')
{
}
bool Rook::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    // Rooks only move straight horizontally or vertically
    if (startR != endR && startC != endC)
    {
        return false; // it will reject illegal moves
    }
    // Moving horizontally (same row)
    if (startR == endR)
    {
        int step = (endC > startC) ? 1 : -1;// it will check left and right
        for (int c = startC + step; c != endC; c += step)
        {
            if (board[startR][c] != nullptr)
                return false; // Path blocked
        }
    }
    // Moving vertically (same column)
    else {
        int step = (endR > startR) ? 1 : -1;// it will check up and down
        for (int r = startR + step; r != endR; r += step)
        {
            if (board[r][startC] != nullptr)
                return false; // Path blocked
        }
    }
    return true;
}
// KNIGHT
Knight::Knight(bool white) : Piece(white, white ? 'N' : 'n')
{
}
bool Knight::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    int rowDiff = abs(startR - endR);//abs for neg to pos-
    int colDiff = abs(startC - endC);
    // Knights move in an L shape (2 steps one way, 1 step the other) By OR it means 1 condition needs to be true
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}
// BISHOP
Bishop::Bishop(bool white) : Piece(white, white ? 'B' : 'b')
{
}
bool Bishop::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) {
    // Bishops only move diagonally (row difference must equal column difference)
    if (abs(startR - endR) != abs(startC - endC))
        return false;
    int rStep = (endR > startR) ? 1 : -1;
    int cStep = (endC > startC) ? 1 : -1;
    int r = startR + rStep;
    int c = startC + cStep;
    // Check if the diagonal path is clear
    while (r != endR && c != endC) {
        if (board[r][c] != nullptr) return false; // Path blocked
        r += rStep;
        c += cStep;
    }
    return true;
}
// QUEEN
Queen::Queen(bool white) : Piece(white, white ? 'Q' : 'q') 
{}
bool Queen::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8]) 
{
    int rowDiff = abs(startR - endR);
    int colDiff = abs(startC - endC);
    // Queen moves like a Rook (straight lines)
    if (startR == endR || startC == endC)
    {
        int rStep = (startR == endR) ? 0 : ((endR > startR) ? 1 : -1);
        int cStep = (startC == endC) ? 0 : ((endC > startC) ? 1 : -1);
        int r = startR + rStep;
        int c = startC + cStep;
        while (r != endR || c != endC) 
        {
            if (board[r][c] != nullptr) return false;
            r += rStep;
            c += cStep;
        }
        return true;
    }
    // Queen moves like a Bishop (diagonal lines)
    else if (rowDiff == colDiff) 
    {
        int rStep = (endR > startR) ? 1 : -1;
        int cStep = (endC > startC) ? 1 : -1;
        int r = startR + rStep;
        int c = startC + cStep;
        while (r != endR && c != endC) 
        {
            if (board[r][c] != nullptr)
                return false;
            r += rStep;
            c += cStep;
        }
        return true;
    }
    return false;
}
// KING
King::King(bool white) : Piece(white, white ? 'K' : 'k') 
{}
bool King::isValidMove(int startR, int startC, int endR, int endC, Piece* board[8][8])
{
    int rowDiff = abs(startR - endR);
    int colDiff = abs(startC - endC);
    // Kings move exactly one step in any direction
    return (rowDiff <= 1 && colDiff <= 1);
}