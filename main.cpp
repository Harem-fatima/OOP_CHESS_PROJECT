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