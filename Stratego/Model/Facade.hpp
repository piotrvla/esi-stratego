#ifndef FACADE_H
#define FACADE_H
#include "./Board.hpp"
#include "State.hpp"
#include "observable.h"
#include "observer.h"

#include <list>


/**
 * @brief The Facade class
 */
class Facade : public Observable{

    Modele::Board board;
    unsigned currentPlayer;
    State state;
    bool cheatMode;
    std::list<Observer *> observers_;


public:
    /**
     * @brief Facade is a constructor with no parameters, that initializes board and sets the current player at 1,
     * initial state becomes NOT_STARTED.
     */
    Facade();
    /**
     * @brief move asks the board to move from the given position, in the given direction by distance cases.
     * @param pos position to move from.
     * @param direction direction to move to.
     * @param distance distance to move.
     */
    void move(Position pos, Direction direction, int distance=1);
    /**
     * @brief at is a getter of pieces.
     * @param pos position to return the piece from.
     * @return piece.
     */
    Piece at(Position pos) const;
    /**
     * @brief isGameOver verifies if the game is over.
     * @return boolean.
     */
    bool isGameOver();
    /**
     * @brief getWinner returns the game winner.
     * @return winner.
     */
    int getWinner();
    /**
     * @brief getState is a getter of states.
     * @return state.
     */
    State getState() const;
    /**
     * @brief getCurrentPlayer is a getter of current player.
     * @return current player.
     */
    unsigned getCurrentPlayer() const;
    /**
     * @brief nextPlayer is choosing the next player.
     */
    void nextPlayer();
    /**
     * @brief to_string converts the board in to a string.
     * @return board as a string.
     */
    std::string to_string();
    /**
     * @brief start sets the state at started.
     */
    void start();
    /**
     * @brief getBoardSize returns the board size.
     * @return board size.
     */
    int getBoardSize() const;
    /**
     * @brief swap swaps the pieces at two given positions.
     * @param p1 position to swap.
     * @param p2 position to swap.
     */
    void swap(Position p1, Position p2);
    /**
     * @brief setCheatMode sets the chead mode on true.
     * @param mode answer of the user.
     */
    void setCheatMode(char mode);
    bool isPiece(Position pos);

    void randomPieces();
    // Subject interface

    void addObserver(Observer * o)override
    {
        observers_.push_back(o);
    }
    void removeObserver(Observer * o)override
    {
        observers_.remove(o);
    }
    void notify(const std::string &propertyName)override
    {
        for (auto const & o : observers_) {
            o->update(propertyName);
        }
    }
};

#endif // FACADE_H
