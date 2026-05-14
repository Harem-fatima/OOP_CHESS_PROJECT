bool Board::loadGame(bool& whiteTurn)
{
    try {
        ifstream file("chess_save.txt");
        if (!file.is_open()) 
        {
            throw runtime_error("Save file 'chess_save.txt' not found.");
        }
        if (!(file >> whiteTurn))
            throw runtime_error("Corrupted turn data.");
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
                if (!(file >> symbol))
                    throw runtime_error("Incomplete board data.");
                if (grid[i][j] != nullptr) delete grid[i][j];
                grid[i][j] = nullptr;
                if (symbol == '-') 
                    continue;
                bool isWhite = isupper(symbol);
                char lowerSym = tolower(symbol);
                if (lowerSym == 'p')
                    grid[i][j] = new Pawn(isWhite);
                else if (lowerSym == 'r') 
                    grid[i][j] = new Rook(isWhite);
                else if (lowerSym == 'n')
                    grid[i][j] = new Knight(isWhite);
                else if (lowerSym == 'b')
                    grid[i][j] = new Bishop(isWhite);
                else if (lowerSym == 'q')
                    grid[i][j] = new Queen(isWhite);
                else if (lowerSym == 'k')
                    grid[i][j] = new King(isWhite);
                else 
                    throw runtime_error("Unknown piece symbol in save file.");
            }
        }
        file.close();
        return true;
    }
    catch (const exception& e) {
        cerr << "Load Error: " << e.what() << endl;
        return false;
    }
}
