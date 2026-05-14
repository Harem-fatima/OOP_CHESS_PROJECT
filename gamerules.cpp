#include "Chess.h"
bool Board::movePiece(int startR, int startC, int endR, int endC, bool isWhiteTurn) {
    // ... (Insert your movePiece logic with the Beep sounds and victory messages) ...
}

// Responsibility: Scan the grid to determine if both Kings are present
bool Board::isGameOver() {
    bool whiteKingAlive = false, blackKingAlive = false;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (grid[r][c] != nullptr) {
                if (grid[r][c]->getSymbol() == 'K') whiteKingAlive = true;
                if (grid[r][c]->getSymbol() == 'k') blackKingAlive = true;
            }
        }
    }
    return !(whiteKingAlive && blackKingAlive);
}
