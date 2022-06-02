#ifndef BOARD_H
#define BOARD_H
#include <optional>
#include <array>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Piece.hpp"
#include "Position.hpp"
#include <stdlib.h>
#include <stdio.h>

namespace Modele{
    /**
     * @brief The Board class represents an 2d array of the pieces.
     */
    class Board {
        static const int BOARD_SIZE = 10;

        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;
        bool cheatMode=false;
        bool player1=false;
        bool player2=false;
        /**
         *
         * @brief initializeArmy initializes the board of 1 player at the time, if a file doesn't exist
         * the file is created and filled with the random generated pieces that respect the given quantity
         * then the array is filled optional pieces from the textfile.
         * @param player is a number of the player to initialize the board.
         */
        void initializeArmy(unsigned player);
        /**
         * @brief attack method returns the winner of the brawl between pieces according to the rules
         * of the game.
         * @param piece attacker
         * @param piece2 defender
         * @return reference of the winner.
         */
        std::optional<Piece> attack(std::optional<Piece> &piece, std::optional<Piece> &piece2);
        /**
         * @brief isInside verifies if the given position is inside.
         * @param pos to check.
         * @return true if is inside, if not false.
         */
        bool isInside(Position pos);
    public:
        /**
         * @brief Board is a constructor with no parameters,
         *  that calls initializeArmy to initialize the board
         */
        Board();
        /**
         * test use only.
         */
        Board(bool a);
        /**
         * @brief move allows the player to move from the given position,
         *  in the given direction by given distance which is by default 1.
         *  We also suppose that every move is an attack, so attack method is called.
         * @param pos to move from.
         * @param direction to move.
         * @param distance of the move.
         */
        void move(Position pos, Direction direction, int distance=1);
        /**
         * @brief isGameOver verifies if the game is over or not.
         * @return a boolean
         */
        bool isGameOver();

        /**
         * @brief getWinner finds the winner of the game.
         * @return the winner.
         */
        unsigned getWinner();
        /**
         * @brief at is an getter of the board.
         * @param pos position to get the piece from.
         * @return returns a constant copy of piece.
         */
        std::optional<Piece> at (Position pos) const;
        /**
         * (public only for test use only)
         * @brief to_string converts the board in to a string, and hides enemy pieces.
         * @param player is the player to convert.
         * @return the board as a string.
         */
        std::string to_string(unsigned player);
        /**
         * @brief canMoveAt verifies if the player is allowed to move from the given position,
         *  in the given direction by given distance which is by default 1.
         * @param pos position to move from.
         * @param direction to move.
         * @param distance of the move.
         * @return true if the move is possible, if not false.
         */
        bool canMoveAt(Position pos, Direction direction, int distance=1);
        /**
         * @brief at method is an setter.
         * @param pos is a position to set the piece at.
         * @return returns the reference of the piece at the given position.
         */
        std::optional<Piece> & at(Position pos);
        /**
         * @brief isPiece verifies if there's a piece at the given position.
         * @param pos, position to check.
         * @return true if it's a piece, if not false.
         */
        bool isPiece(Position pos);
        /**
         * @brief getBoardSize returns the board size.
         * @return board size.
         */
        int getBoardSize() const;
        /**
         * @brief swap used to swap 2 pieces between.
         * @param p1 position 1 to swap from.
         * @param p2 position 2 to swap to.
         */
        void swap(Position p1, Position p2);

        void randomPieces(unsigned player);

        
    };
}
#endif // BOARD_H
