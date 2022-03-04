#ifndef PIECE_H
#define PIECE_H

class Piece{
private:
    char symbole;
    unsigned player;

public:
    Piece (char symbole,unsigned player=0);
    char getSymbole() const;
    unsigned getPlayer() const;
};
#endif // PIECE_H
