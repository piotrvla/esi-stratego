#ifndef PIECE_H
#define PIECE_H

class Piece{
private:
    char symbole;
    unsigned player;
    //bool isVisible=false;

public:
    Piece(unsigned player, char symbole);
    inline char getSymbole();
    inline unsigned getPlayer();
    /*bool getVisibility();
    void changeVisibility();*/
};
#endif // PIECE_H
