#include <Piece.hpp>

Piece::Piece( char symbole,unsigned player):symbole{symbole},player{player}{}

char Piece::getSymbole(){
    return symbole;
}

unsigned Piece::getPlayer(){
    return player;
}
