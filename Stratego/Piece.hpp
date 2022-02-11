#ifndef PIECE_H
#define PIECE_H

class Piece{
    Piece(char symbole);
    char symbole;
    bool isVisible=false;

    /**
     * @brief changeVisibility
     */
    void changeVisibility();



};
#endif // PIECE_H
