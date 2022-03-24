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
    void start();
    int getBoardSize() const;
    void swap(Position p1, Position p2);
};

#endif // FACADE_H
