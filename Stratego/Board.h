#ifndef BOARD_H
#define BOARD_H

#include "optional"
#include "array"
#include <Piece.h>
#include <Position.h>
#include <Direction.h>
namespace Board{
    class Board {
        Board();
        std::array<std::array<std::optional<Piece>,10>,10> board;
        Piece attack(Piece piece, Piece piece2);
        void swapPieces(Position pos1, Position pos2);
        inline bool isInside(Position pos);
        inline bool isPiece(Position pos);
        public:
        void initializeArmy();
        void move(Piece piece, Direction direction, int distance);
        inline Piece getPiece(Position pos);


    };
};
#endif // BOARD_H
