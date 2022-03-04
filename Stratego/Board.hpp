#ifndef BOARD_H
#define BOARD_H
#include "optional"
#include "array"
#include "fstream"
#include "vector"
#include <Piece.hpp>
#include <Position.hpp>
#include <Direction.hpp>

namespace Modele{
    class Board {
        static const unsigned BOARD_SIZE = 10;
        bool cheatMode;
        std::vector<std::pair<char, int>> listOfPieces;
        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;

        void initializeArmy();
        void move(Position pos, Direction direction, int distance=1);
        bool isGameOver();
        int getWinner();
        std::optional<Piece> at(Position pos);
        std::optional<Piece> attack(std::optional<Piece> piece, std::optional<Piece> piece2);
        void swapPieces(Position pos1, Position pos2);
        bool isInside(Position pos);
        bool isPiece(Position pos);
        void setPiece(Position pos, std::optional<Piece>);
        public:
        Board();
    };
};
#endif // BOARD_H
