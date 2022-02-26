#ifndef PIECE_H
#define PIECE_H

class Piece{
private:
    char symbole;
    unsigned player;
    //bool isVisible=false;

public:
    Piece (char symbole,unsigned player=0);
    char getSymbole() const;
    unsigned getPlayer() const;
    /*bool getVisibility();
    void changeVisibility();*/
};
#endif // PIECE_H
