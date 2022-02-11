#ifndef BOARD_H
#define BOARD_H
#include "optional"
#include "array"
#include "fstream"
#include <Piece.hpp>
#include <Position.hpp>
#include <Direction.hpp>

namespace Modele{
    class Board {
        static const unsigned BOARD_SIZE = 10;
        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;
        void initializeArmy(std::string fileName);
        std::optional<Piece> attack(std::optional<Piece> piece, std::optional<Piece> piece2);
        void swapPieces(Position pos1, Position pos2);
        bool isInside(Position pos);
        bool isPiece(Position pos);
        void setPiece(Position pos, std::optional<Piece>);
        public:
        Board(std::string fileName);
        void move(Position pos, Direction direction, int distance=1);
        std::optional<Piece> getPiece(Position pos);
    };
};
#endif // BOARD_H
