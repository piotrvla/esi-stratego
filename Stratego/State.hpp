#ifndef STATE_H
#define STATE_H
#include <Position.hpp>

enum class State{
    NOT_STARTED,
    NEXT_PLAYER,
    GAME_OVER,
    MOVING
};
#endif // STATE_H
