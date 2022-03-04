#ifndef BOARD_H
#define BOARD_H
#include "optional"
#include "array"
#include "fstream"
#include "vector"
#include "algorithm"
#include "stdexcept"
#include <Piece.hpp>
#include <Position.hpp>
#include <Direction.hpp>
#include <time.h>

namespace Modele{
    class Board {
        static const unsigned BOARD_SIZE = 10;
        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;
        bool cheatMode;

        void initializeArmy();
        std::optional<Piece> attack(std::optional<Piece> piece, std::optional<Piece> piece2);
        bool canMoveAt(Position pos, Direction direction, int distance=1);
        bool isInside(Position pos);
    public:
        Board();
        Board(bool a);
        void move(Position pos, Direction direction, int distance=1);
        bool isGameOver();
        unsigned getWinner();
        std::optional<Piece> at (Position pos) const;


        //also used for tests
        std::optional<Piece> & at(Position pos);
        bool isPiece(Position pos);
        void setPiece(Position pos, std::optional<Piece>);
        
    };
}
#endif // BOARD_H
