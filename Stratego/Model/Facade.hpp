#ifndef FACADE_H
#define FACADE_H
#include "Board.hpp"
#include "State.hpp"



class Facade{

    Modele::Board board;
    unsigned currentPlayer;
    State state;


public:
    Facade();
    void move(Position pos, Direction direction, int distance=1);
    Piece at(Position pos) const;
    bool isGameOver();
    int getWinner();
    State getState() const;
    unsigned getCurrentPlayer() const;
    void nextPlayer();
    std::string to_string();
};

#endif // FACADE_H
