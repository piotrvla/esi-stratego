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
        std::array<std::array<std::optional<Piece>,BOARD_SIZE>,BOARD_SIZE> board;
        bool cheatMode;

        const std::vector<std::pair<Piece, int>> listOfPieces
        {{Piece{'9',99},1},{Piece{'8',99},2},{Piece{'7',99},3},{Piece{'6',99},4},{Piece{'5',99},4},
            {Piece{'4',99},4},{Piece{'3',99},4},{Piece{'2',99},5},{Piece{'1',99},8},
            {Piece{'0',99},1},{Piece{'D',99},1},{Piece{'B',99},6}};

        void initializeArmy(std::string fileName);
        std::optional<Piece> attack(std::optional<Piece> piece, std::optional<Piece> piece2);
        bool canMoveAt(Position pos, Direction direction, int distance=1);
        bool isInside(Position pos);
    public:
        Board(std::string fileName);

        //used for tests
        Board() = default;

        void move(Position pos, Direction direction, int distance=1);
        bool isGameOver();
        unsigned getWinner();
        std::optional<Piece> at(Position pos) const;

        //also used for tests
        std::optional<Piece> &at(Position pos);
        bool isPiece(Position pos);






    };
}
#endif // BOARD_H
