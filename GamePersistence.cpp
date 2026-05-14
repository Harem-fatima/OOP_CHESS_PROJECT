#include "Chess.h"
bool Board::saveGame(bool whiteTurn) {
    ofstream file("chess_save.txt");
    if (!file) return false;
    file << whiteTurn << endl;
    file << (capturedWhite.empty() ? "-" : capturedWhite) << endl;
    file << (capturedBlack.empty() ? "-" : capturedBlack) << endl;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == nullptr) file << "- ";
            else file << grid[i][j]->getSymbol() << " ";
        }
        file << endl;
    }
    file.close();
    return true;
}

bool Board::loadGame(bool& whiteTurn) 
{
    ifstream file("chess_save.txt");
    if (!file) return false;
    return true;
}
