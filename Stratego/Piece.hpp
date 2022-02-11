#ifndef PIECE_H
#define PIECE_H

class Piece{
private:
    char symbole;
    bool isVisible=false;

public:
    Piece(char symbole);
    void changeVisibility();
};
#endif // PIECE_H
