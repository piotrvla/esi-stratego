#include "Piece.hpp"

Piece::Piece( char symbole,unsigned player):symbole{symbole},player{player}{}

char Piece::getSymbole() const{
    return symbole;
}

unsigned Piece::getPlayer() const{
    return player;
}
