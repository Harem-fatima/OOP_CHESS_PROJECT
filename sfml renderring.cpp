void Board::drawSFML(sf::RenderWindow& window, int selectedRow, int selectedCol) {
    // 1. Draw the checkered background
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
            square.setPosition(col * 100.f, row * 100.f);

            // Light cream and Dark brown pattern
            if ((row + col) % 2 == 0)
                square.setFillColor(sf::Color(255, 248, 220));
            else 
                square.setFillColor(sf::Color(101, 67, 33));

            // Highlight the currently selected piece
            if (row == selectedRow && col == selectedCol)
                square.setFillColor(sf::Color(255, 255, 50, 150));

            window.draw(square);
        }
    }

    // 2. Draw the pieces and the move highlights
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (grid[row][col] != nullptr) {
                // Determine color and shapes based on piece type...
                // (Keep your existing if/else block for circles, triangles, etc.)
            }
        }
    }

    // 3. Highlight valid moves (This calls your partner's logic!)
    if (selectedRow != -1 && selectedCol != -1 && grid[selectedRow][selectedCol] != nullptr) {
        Piece* selectedPiece = grid[selectedRow][selectedCol];
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                // Testing the rules your partner wrote:
                if (selectedPiece->isValidMove(selectedRow, selectedCol, r, c, grid)) {
                    if (grid[r][c] == nullptr || grid[r][c]->getIsWhite() != selectedPiece->getIsWhite()) {
                        sf::CircleShape highlight(15.f);
                        highlight.setFillColor(sf::Color(0, 200, 0, 150));
                        highlight.setPosition(c * 100.f + 35.f, r * 100.f + 35.f);
                        window.draw(highlight);
                    }
                }
            }
        }
    }
}
