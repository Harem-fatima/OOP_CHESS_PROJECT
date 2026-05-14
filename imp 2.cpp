//This section handles moving pieces, victory conditions, saving/loading the game state, and checking if the game is over.
#include "Chess.h"

bool Board::movePiece(int startR, int startC, int endR, int endC, bool isWhiteTurn)
{
    if (isGameOver())
    {
        cout << '\a';
        return false;
    }
    if (startR < 0 || startR > 7 || startC < 0 || startC > 7 || endR < 0 || endR > 7 || endC < 0 || endC > 7)
        return false;
    Piece* pieceToMove = grid[startR][startC];
    if (pieceToMove == nullptr || pieceToMove->getIsWhite() != isWhiteTurn)
    {
        if (pieceToMove != nullptr) cout << "\033[38;5;196m[WARNING] You can only move your own pieces!\033[0m" << endl;
        cout << '\a';
        return false;
    }
    if (grid[endR][endC] != nullptr && grid[endR][endC]->getIsWhite() == isWhiteTurn)
        return false;
    if (pieceToMove->isValidMove(startR, startC, endR, endC, grid))
    {
        if (grid[endR][endC] != nullptr)
        {
            cout << '\a' << '\a';

            if (grid[endR][endC]->getIsWhite()) capturedWhite += grid[endR][endC]->getSymbol();
            else capturedBlack += grid[endR][endC]->getSymbol();

            cout << endl << "\033[38;5;226m---------------------------------------\033[0m" << endl;
            cout << "\033[1m PIECES CAPTURED SO FAR:\033[0m" << endl;
            cout << " \033[38;5;51mWhite Team Lost : \033[0m" << (capturedWhite.empty() ? "None" : capturedWhite) << endl;
            cout << " \033[38;5;208mBlack Team Lost : \033[0m" << (capturedBlack.empty() ? "None" : capturedBlack) << endl;
            cout << "\033[38;5;226m---------------------------------------\033[0m" << endl;

            if (grid[endR][endC]->getSymbol() == 'K' || grid[endR][endC]->getSymbol() == 'k') {
                cout << endl << "\033[38;5;226m====================================================\033[0m" << endl;
                if (isWhiteTurn) cout << "\033[38;5;51m\033[1m  WHITE HAS CAPTURED THE KING! WHITE WINS!  \033[0m" << endl;
                else cout << "\033[38;5;208m\033[1m  BLACK HAS CAPTURED THE KING! BLACK WINS!  \033[0m" << endl;
                cout << "\033[38;5;226m====================================================\033[0m" << endl;
            }
            delete grid[endR][endC];
        }
        else {
            cout << '\a';
        }
        grid[endR][endC] = pieceToMove;
        grid[startR][startC] = nullptr;
        return true;
    }
    else {
        cout << '\a';
        return false;
    }
}

bool Board::saveGame(bool whiteTurn)
{
    ofstream file("chess_save.txt");
    if (!file)
        return false;
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
    if (!file)
        return false;
    file >> whiteTurn;
    file >> capturedWhite;
    if (capturedWhite == "-")
        capturedWhite = "";
    file >> capturedBlack;
    if (capturedBlack == "-")
        capturedBlack = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char symbol;
            file >> symbol;
            if (grid[i][j] != nullptr)
                delete grid[i][j];
            grid[i][j] = nullptr;
            if (symbol == '-')
                continue;
            bool isWhite = isupper(symbol);
            char lowerSym = tolower(symbol);

            if (lowerSym == 'p') grid[i][j] = new Pawn(isWhite);
            else if (lowerSym == 'r') grid[i][j] = new Rook(isWhite);
            else if (lowerSym == 'n') grid[i][j] = new Knight(isWhite);
            else if (lowerSym == 'b') grid[i][j] = new Bishop(isWhite);
            else if (lowerSym == 'q') grid[i][j] = new Queen(isWhite);
            else if (lowerSym == 'k') grid[i][j] = new King(isWhite);
        }
    }
    file.close();
    return true;
}

bool Board::isGameOver() {
    bool whiteKingAlive = false;
    bool blackKingAlive = false;
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (grid[r][c] != nullptr)
            {
                if (grid[r][c]->getSymbol() == 'K') whiteKingAlive = true;
                if (grid[r][c]->getSymbol() == 'k') blackKingAlive = true;
            }
        }
    }
    return !(whiteKingAlive && blackKingAlive);
}