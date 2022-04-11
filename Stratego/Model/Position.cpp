#include "Position.hpp"

Position::Position(int x, int y ):x{x},y{y}{}


int Position::getX()const {
    return x;
}

int Position::getY()const {
    return y;
}
