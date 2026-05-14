bool Board::movePiece(int startR, int startC, int endR, int endC, bool isWhiteTurn)
{
    try {
        // Prevent moves if the game is already over
        if (isGameOver())
        {
            cout << '\a'; // Typical Beep
            return false;
        }
        // Exception Handling: Prevent moves outside the bounds of the 8x8 array
        if (startR < 0 || startR > 7 || startC < 0 || startC > 7 ||
            endR < 0 || endR > 7 || endC < 0 || endC > 7)
        {
            throw out_of_range("Coordinates outside board boundaries.");
        }
        Piece* pieceToMove = grid[startR][startC];
        // Exception Handling: Ensure the square actually contains a piece
        if (pieceToMove == nullptr)
        {
            throw invalid_argument("No piece exists at the starting coordinates.");
        }

        // Ensure the player is only moving their own pieces
        if (pieceToMove->getIsWhite() != isWhiteTurn)
        {
            cout << "\033[38;5;196mWARNING :You can only move your own pieces!\033[0m" << endl;
            cout << '\a'; // Typical Beep
            return false;
        }
        // Ensure the player isn't trying to capture their own piece
        if (grid[endR][endC] != nullptr && grid[endR][endC]->getIsWhite() == isWhiteTurn)
            return false;
        // Check if the specific piece's movement rules allow this move
        if (pieceToMove->isValidMove(startR, startC, endR, endC, grid))
        {
            // Handle capturing an enemy piece
            if (grid[endR][endC] != nullptr)
            {
                Beep(750, 150); // Pitch: 750Hz, Duration: 150ms
                Beep(1000, 200); // Pitch: 1000Hz, Duration: 200ms
                // Add the captured piece to the list
                if (grid[endR][endC]->getIsWhite())
                    capturedWhite += grid[endR][endC]->getSymbol();
                else
                    capturedBlack += grid[endR][endC]->getSymbol();
                // capturing cout 
                cout << endl << "\033[38;5;226m---------------------------------------\033[0m" << endl;
                cout << "\033[1m PIECES CAPTURED SO FAR:\033[0m" << endl;
                cout << " \033[38;5;51mWhite Team Lost : \033[0m" << (capturedWhite.empty() ? "None" : capturedWhite) << endl;
                cout << " \033[38;5;208mBlack Team Lost : \033[0m" << (capturedBlack.empty() ? "None" : capturedBlack) << endl;
                cout << "\033[38;5;226m---------------------------------------\033[0m" << endl;
                // Check for victory condition (King captured)
                if (grid[endR][endC]->getSymbol() == 'K' || grid[endR][endC]->getSymbol() == 'k') {
                    cout << endl << "\033[38;5;226m====================================================\033[0m" << endl;
                    if (isWhiteTurn)
                        cout << "\033[38;5;51m\033[1m  WHITE HAS CAPTURED THE KING! WHITE WINS!  \033[0m" << endl;
                    else
                        cout << "\033[38;5;208m\033[1m  BLACK HAS CAPTURED THE KING! BLACK WINS!  \033[0m" << endl;
                    cout << "\033[38;5;226m====================================================\033[0m" << endl;
                }
                delete grid[endR][endC];
            }
            else
            {
                Beep(600, 100); // Single beep for a normal move
            }
            // Execute the move in the array
            grid[endR][endC] = pieceToMove;//changing the position of peace
            grid[startR][startC] = nullptr;
            return true;
        }
        else {
            Beep(200, 300); // Error beep for invalid move
            return false;
        }
    }
    catch (const out_of_range& e) 
    {
        cerr << "\033[31mArray Error: " << e.what() << "\033[0m" << endl;
        return false;
    }
    catch (const exception& e) 
    {
        cerr << "\033[31mUnexpected Error: " << e.what() << "\033[0m" << endl;
        return false;
    }
}
