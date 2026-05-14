#include "Chess.h"
Board::Board()
{
    capturedWhite = "";
    capturedBlack = "";
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            grid[i][j] = nullptr;
        }
    }
}
// Destructor: Cleans up all pieces to prevent memory leaks
Board::~Board() 
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr)
                delete grid[i][j];
        }
    }
}
