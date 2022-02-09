#ifndef FACADE_H
#define FACADE_H
#include <Board.h>
#include <State.h>
class Facade{
    Facade();
    Board::Board board;
    int currentPlayer;
    State state;

    void nextPlayer();

public:
    void swap(Position pos1, Position pos2);
    void move(Piece piece, Direction direction, int distance=1);
};

#endif // FACADE_H
