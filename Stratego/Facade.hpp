#ifndef FACADE_H
#define FACADE_H
#include <Board.hpp>
#include <State.hpp>

class Facade{
private:
    Modele::Board board;
    int currentPlayer;
    State state;

    void nextPlayer();
public:
    Facade();
    void swap(Position pos1, Position pos2);
    void move(Piece piece, Direction direction, int distance=1);
};

#endif // FACADE_H
