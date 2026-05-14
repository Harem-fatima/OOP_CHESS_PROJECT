// ==========================================
// Semester Project: Chess Game in C++
// Part 1: Initialization and UI Setup
// Prepared by: Sahrish Batool
// ==========================================
#include "Chess.h"
using namespace std;
int main()
{
    // PER CHESS GAME RULE WHITE TURN FIRST IS FIX AND SHOWN
    sf::RenderWindow window(sf::VideoMode(800, 800), "OOP Chess GUI - WHITE'S TURN");
    Board gameBoard;
    gameBoard.setupBoard();
    bool whiteTurn = true;
    int startR = -1, startC = -1;
    // INSTRUCTION BOX
    cout << "\033[38;5;51m|_______________________________________|\033[0m" << endl;
    cout << "\033[38;5;51m\033[1m        WELCOME TO  CHESS        \033[0m" << endl;
    cout << "\033[38;5;51m\033[1m          PLAY AND ENJOY!            \033[0m" << endl;
    cout << "\033[38;5;51m|_______________________________________|\033[0m" << endl;
    cout << "\033[38;5;226m            --- LEGEND ---             \033[0m" << endl;
    cout << "  \033[38;5;204mCircle\033[0m    =  Pawn" << endl;
    cout << "  \033[38;5;208mSquare\033[0m    =  Rook" << endl;
    cout << "  \033[38;5;118mTriangle\033[0m  =  Knight" << endl;
    cout << "  \033[38;5;147mDiamond\033[0m   =  Bishop" << endl;
    cout << "  \033[38;5;213mPentagon\033[0m  =  Queen" << endl;
    cout << "  \033[38;5;220mOctagon\033[0m   =  King" << endl;
    cout << "\033[38;5;240m---------------------------------------\033[0m" << endl;
    cout << "\033[38;5;226m        { CONTROLS }         \033[0m" << endl;
    cout << "  \033[38;5;15mMouse\033[0m : Click piece, then destination" << endl;
    cout << "  \033[38;5;15mKey S\033[0m : Save Game" << endl;
    cout << "  \033[38;5;15mKey L\033[0m : Load Game" << endl;
    cout << "  \033[38;5;15mKey E\033[0m : Exit Game" << endl;
    cout << "\033[38;5;51m_________________________________________\033[0m" << endl;
    cout << "\033[38;5;82m\GAME  STARTED!\033[0m" << endl;
    // Simple system beep to signal the game has started
    cout << '\a';
    // (The game loop logic is handled in Part 2)
}
// Part 2: Game Loop and Input Handling
// Prepared by: Harem
    // (Continued from Part 1)
while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        // KEYBOARD CONTROLS 
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::E)
            {
                cout << "Thanks for playing. Goodbye!" << endl;
                window.close();
            }
            else if (event.key.code == sf::Keyboard::S)
            {
                if (gameBoard.saveGame(whiteTurn))
                    cout << "\n[SUCCESS] Game saved." << endl;
                else
                    cout << "\n[ERROR] Could not save." << endl;
            }
            else if (event.key.code == sf::Keyboard::L)
            {
                if (gameBoard.loadGame(whiteTurn))
                {
                    cout << "\n[SUCCESS] Game loaded!" << endl;
                    window.setTitle(whiteTurn ? "OOP Chess GUI - WHITE'S TURN" : "OOP Chess GUI - BLACK'S TURN");
                }
                else cout << "\n[ERROR] No save file found." << endl;
            }
        }
        //  MOUSE MOVEMENT LOGIC 
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                int clickedCol = event.mouseButton.x / 100;
                int clickedRow = event.mouseButton.y / 100;
                if (startR == -1)
                {
                    if (!gameBoard.isGameOver())
                    {
                        startR = clickedRow;
                        startC = clickedCol;
                    }
                }
                else
                {
                    int endR = clickedRow, endC = clickedCol;
                    if (gameBoard.movePiece(startR, startC, endR, endC, whiteTurn))
                    {
                        whiteTurn = !whiteTurn;
                        window.setTitle(whiteTurn ? "OOP Chess GUI - WHITE'S TURN" : "OOP Chess GUI - BLACK'S TURN");
                        if (!gameBoard.isGameOver())
                        {
                            if (whiteTurn)
                                cout << "\n\033[38;5;51m---> White's Turn\033[0m" << endl;
                            else
                                cout << "\n\033[38;5;208m---> Black's Turn\033[0m" << endl;
                        }
                    }
                    startR = -1;
                    startC = -1;
                }
            }
        }
    }
    window.clear();
    gameBoard.drawSFML(window, startR, startC);
    window.display();
}

return 0;
}
