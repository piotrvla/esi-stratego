#ifndef PIECE_H
#define PIECE_H

class Piece{
private:
    char symbole;
    unsigned player;
    //bool isVisible=false;

public:
    Piece (char symbole,unsigned player);
    char getSymbole();
    unsigned getPlayer();
    /*bool getVisibility();
    void changeVisibility();*/
};
#endif // PIECE_H
