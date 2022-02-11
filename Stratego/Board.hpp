#ifndef BOARD_H
#define BOARD_H
#include "optional"
#include "array"
#include <Piece.hpp>
#include <Position.hpp>
#include <Direction.hpp>

namespace Modele{
    class Board {
        static const unsigned BOARD_SIZE = 10;
        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;

        void initializeArmy();
        Piece attack(std::optional<Piece> piece, std::optional<Piece> piece2);
        void swapPieces(Position pos1, Position pos2);
        inline bool isInside(Position pos);
        inline bool isPiece(Position pos);
        void setPiece(Position pos, std::optional<Piece>);
        public:
        Board();
        void move(Position pos, Direction direction, int distance=1);
        inline std::optional<Piece> getPiece(Position pos);
    };
};
#endif // BOARD_H
