#ifndef FACADE_H
#define FACADE_H
#include <Board.hpp>
#include <State.hpp>

class Piece;
class Direction;

class Facade{

    Modele::Board board;
    unsigned currentPlayer;
    State state;

    void nextPlayer();
public:
    Facade();
    void move(Position pos, Direction direction, int distance=1);
    Piece at(Position pos) const;
    bool isGameOver();
    int getWinner();
    State getState() const;
    unsigned getCurrentPlayer() const;

};

#endif // FACADE_H
