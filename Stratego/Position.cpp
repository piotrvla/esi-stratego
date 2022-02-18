#include <Position.hpp>

Position::Position(unsigned x, unsigned y ):x{x},y{y}{}


unsigned Position::getX(){
    return x;
}
unsigned Position::getY(){
    return y;
}
