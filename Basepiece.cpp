#include "Chess.h"

Piece::Piece(bool white, char sym) : isWhite(white), symbol(sym)
{}
char Piece::getSymbol()
{
  return symbol;
}
bool Piece::getIsWhite() 
{ 
  return isWhite; 
}
