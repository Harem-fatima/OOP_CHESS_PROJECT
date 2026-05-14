bool Board::saveGame(bool whiteTurn)//exception hadling here
{
    try 
    {
        ofstream file("chess_save.txt");
        if (!file.is_open())
        {
            throw runtime_error("Failed to open save file for writing.");
        }

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
    catch (const exception& e) {
        cerr << "Save Error: " << e.what() << endl;
        return false;
    }
}
