#include "ChessPieces.h"
Piece::Piece(bool white, char sym)
{
    isWhite = white;
    symbol = sym;
}
Piece::~Piece() {}

char Piece::getSymbol()
{
    return symbol;
}

bool Piece::getIsWhite()
{
    return isWhite;
}
