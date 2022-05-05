#ifndef STATE_H
#define STATE_H
/**
 * @brief The State enum represents all the states of the game.
 */
enum class State{
    NOT_STARTED = 0,
    NEXT_PLAYER = 1,
    GAME_OVER = 2,
    MOVING = 3,
    SWAPING = 4
};
#endif // STATE_H
