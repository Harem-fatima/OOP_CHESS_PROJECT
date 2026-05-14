//This section handles the class constructor, destructor, initial piece placement, and the graphical drawing logic.
#include "Chess.h"
Board::Board() {
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
Board::~Board() 
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr)
                delete grid[i][j];
        }
    }
}

void Board::setupBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
    capturedWhite = "";
    capturedBlack = "";

    grid[0][0] = new Rook(false); grid[0][1] = new Knight(false);
    grid[0][2] = new Bishop(false); grid[0][3] = new Queen(false);
    grid[0][4] = new King(false); grid[0][5] = new Bishop(false);
    grid[0][6] = new Knight(false); grid[0][7] = new Rook(false);
    for (int i = 0; i < 8; i++) grid[1][i] = new Pawn(false);

    grid[7][0] = new Rook(true); grid[7][1] = new Knight(true);
    grid[7][2] = new Bishop(true); grid[7][3] = new Queen(true);
    grid[7][4] = new King(true); grid[7][5] = new Bishop(true);
    grid[7][6] = new Knight(true); grid[7][7] = new Rook(true);
    for (int i = 0; i < 8; i++) grid[6][i] = new Pawn(true);
}

void Board::drawSFML(sf::RenderWindow& window, int selectedRow, int selectedCol) {
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
            square.setPosition(col * 100.f, row * 100.f);

            if ((row + col) % 2 == 0)
                square.setFillColor(sf::Color(255, 248, 220));
            else square.setFillColor(sf::Color(101, 67, 33));

            if (row == selectedRow && col == selectedCol)
                square.setFillColor(sf::Color(255, 255, 50, 150));

            window.draw(square);
        }
    }

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (grid[row][col] != nullptr)
            {
                char type = tolower(grid[row][col]->getSymbol());
                bool isWhite = grid[row][col]->getIsWhite();

                sf::Color fillColor = isWhite ? sf::Color::White : sf::Color(40, 40, 40);
                sf::Color outlineColor = isWhite ? sf::Color::Black : sf::Color::White;
                float centerX = col * 100.f + 50.f;
                float centerY = row * 100.f + 50.f;

                if (type == 'p')
                {
                    sf::CircleShape pawn(30.f);
                    pawn.setOrigin(30.f, 30.f); pawn.setPosition(centerX, centerY);
                    pawn.setFillColor(fillColor); pawn.setOutlineThickness(3.f); pawn.setOutlineColor(outlineColor);
                    window.draw(pawn);
                }
                else if (type == 'r')
                {
                    sf::RectangleShape rook(sf::Vector2f(60.f, 60.f));
                    rook.setOrigin(30.f, 30.f); rook.setPosition(centerX, centerY);
                    rook.setFillColor(fillColor); rook.setOutlineThickness(3.f); rook.setOutlineColor(outlineColor);
                    window.draw(rook);
                }
                else if (type == 'n')
                {
                    sf::CircleShape knight(35.f, 3);
                    knight.setOrigin(35.f, 35.f); knight.setPosition(centerX, centerY + 10.f);
                    knight.setFillColor(fillColor); knight.setOutlineThickness(3.f); knight.setOutlineColor(outlineColor);
                    window.draw(knight);
                }
                else if (type == 'b')
                {
                    sf::CircleShape bishop(35.f, 4);
                    bishop.setOrigin(35.f, 35.f); bishop.setPosition(centerX, centerY);
                    bishop.setFillColor(fillColor); bishop.setOutlineThickness(3.f); bishop.setOutlineColor(outlineColor);
                    window.draw(bishop);
                }
                else if (type == 'q')
                {
                    sf::CircleShape queen(35.f, 5);
                    queen.setOrigin(35.f, 35.f); queen.setPosition(centerX, centerY);
                    queen.setFillColor(fillColor); queen.setOutlineThickness(3.f); queen.setOutlineColor(outlineColor);
                    window.draw(queen);
                }
                else if (type == 'k')
                {
                    sf::CircleShape king(38.f, 8);
                    king.setOrigin(38.f, 38.f); king.setPosition(centerX, centerY);
                    king.setFillColor(fillColor); king.setOutlineThickness(4.f); king.setOutlineColor(outlineColor);
                    window.draw(king);
                }
            }
        }
    }
    if (selectedRow != -1 && selectedCol != -1 && grid[selectedRow][selectedCol] != nullptr)
    {
        Piece* selectedPiece = grid[selectedRow][selectedCol];
        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                if (selectedPiece->isValidMove(selectedRow, selectedCol, r, c, grid))
                {
                    if (grid[r][c] == nullptr || grid[r][c]->getIsWhite() != selectedPiece->getIsWhite())
                    {
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