#ifndef BOARD_H
#define BOARD_H
#include "optional"
#include "array"
#include <Piece.hpp>
#include <Position.hpp>
#include <Direction.hpp>

namespace Modele{
    class Board {
    private:
        std::array<std::array<std::optional<Piece>,10>,10> board;

        void initializeArmy();
        Piece attack(Piece piece, Piece piece2);
        void swapPieces(Position pos1, Position pos2);
        inline bool isInside(Position pos);
        inline bool isPiece(Position pos);

        public:
        Board();
        void move(Piece piece, Direction direction, int distance=1);
        inline std::optional<Piece> getPiece(Position pos);
    };
};
#endif // BOARD_H
