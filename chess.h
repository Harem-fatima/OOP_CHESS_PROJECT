// Semester Project: Chess Game in C++
// Part 2: Board Management and SFML Interface
// Prepared by: Harem
#ifndef CHESS_H
#define CHESS_H
// Dependencies from Part 1
#include "chess.h" 
#include <fstream> 
#include <cctype>
class Board
{
private:
    Piece* grid[8][8];
    string capturedWhite;
    string capturedBlack;
public:
    Board();
    ~Board();
    void setupBoard();
    void drawSFML(sf::RenderWindow& window, int selectedRow, int selectedCol);
    bool movePiece(int startR, int startC, int endR, int endC, bool isWhiteTurn);
    bool isGameOver();
    bool saveGame(bool whiteTurn);
    bool loadGame(bool& whiteTurn);
};
#endif