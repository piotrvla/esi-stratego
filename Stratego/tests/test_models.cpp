#include <catch.hpp>
#include <Board.hpp>

using namespace Modele;


TEST_CASE("canMoveAt"){

}
TEST_CASE("Moving"){

    Board board(1);
    SECTION("Moving as a flag"){
        Position pos{1,1};
        std::optional pc{Piece{'F'}};
        REQUIRE_THROWS(board.move(pos,Direction::BOTTOM,1));

    }
    SECTION("Moving as a bomb"){
        Position pos{1,1};
        std::optional pc{Piece{'B'}};
        REQUIRE_THROWS(board.move(pos,Direction::BOTTOM,1));
    }
    SECTION("Moving as a flag more than by 1 case"){
        Position pos{1,1};
        std::optional pc{Piece{'F'}};
        REQUIRE_THROWS(board.move(pos,Direction::LEFT,3));

    }
    SECTION("Moving as a bomb more than by 1 case"){
        Position pos{1,1};
        std::optional pc{Piece{'B'}};
        REQUIRE_THROWS(board.move(pos,Direction::RIGHT,5));
    }
    SECTION("Trying to move outside the board - left"){
        Position pos{0,0};
        std::optional pc{Piece{'7'}};
        REQUIRE_THROWS(board.move(pos,Direction::LEFT));
    }
    SECTION("Trying to move 1 that more case as a marechal.") {
        Position pos{1,1};
        Position pos2{1,2};
        std::optional pc{Piece{'9',1}};
        board.at(pos)=pc;
        REQUIRE_THROWS(board.move(pos,Direction::BOTTOM,5));
    }
    SECTION("Scout moving more than 1 case - RIGHT, and obstacle between") {
        Position pos{5,5};
        std::optional pc{Piece{'0',5}};
        board.at(pos)=pc;
        board.at(Position{5,3})=std::optional{Piece('2',4)};
        REQUIRE_THROWS(board.move(pos,Direction::BOTTOM,4););
    }

    SECTION("Moving straignt into an obstacle (water)" ) {
        Position pos{7,2};
        std::optional pc{Piece{'5',5}};
        board.at(pos)=pc;
        board.at(Position{7,3})=std::optional{Piece('W')};
        REQUIRE_THROWS(board.move(pos,Direction::TOP,1));
    }
    SECTION("Moving into an empty space right by 1 - TOP") {

        Position pos{1,1};
        Position pos2{1,2};
        std::optional pc{Piece{'3',1}};
        board.at(pos)=pc;
        board.at(pos2)=std::nullopt;
        board.move(pos,Direction::TOP);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Moving into an empty space right by 1 - LEFT"){
        Position pos{3,1};
        Position pos2{2,1};
        std::optional pc{Piece{'7',1}};
        board.at(pos)=pc;
        board.move(pos,Direction::LEFT);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Moving into an empty space right by 1 - RIGHT"){
        Position pos{3,2};
        Position pos2{4,2};
        std::optional pc{Piece{'7',1}};
        board.at(pos)=pc;
        board.move(pos,Direction::RIGHT);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Moving into an empty space right by 1 - BOTTOM"){
        Position pos{8,8};
        Position pos2{8,7};
        std::optional pc{Piece{'7',1}};
        board.at(pos)=pc;
        board.move(pos,Direction::BOTTOM);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Scout moving more than 1 case - TOP") {
        Position pos{1,1};
        Position pos2{1,4};
        std::optional pc{Piece{'0',5}};
        board.at(pos)=pc;
        board.move(pos,Direction::TOP,3);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Scout moving more than 1 case - LEFT") {
        Position pos{5,1};
        Position pos2{2,1};
        std::optional pc{Piece{'0',5}};
        board.at(pos)=pc;
        board.move(pos,Direction::LEFT,3);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Scout moving more than 1 case - RIGHT") {
        Position pos{1,1};
        Position pos2{7,1};
        std::optional pc{Piece{'0',5}};
        board.at(pos)=pc;
        board.move(pos,Direction::RIGHT,6);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Scout moving more than 1 case - BOTTOM") {
        Position pos{5,5};
        Position pos2{5,1};
        std::optional pc{Piece{'0',5}};
        board.at(pos)=pc;
        board.move(pos,Direction::BOTTOM,4);
        REQUIRE(board.at(pos2)->getSymbole()==pc->getSymbole());
    }
    SECTION("Move then check if previous position empty" ) {
        Position pos{6,8};
        std::optional pc{Piece{'5',5}};
        board.at(pos)=pc;
        board.move(pos,LEFT);
        REQUIRE(!board.isPiece(pos));
    }


}
TEST_CASE("Attack"){
    Board board(1);
    // 7 tests
    SECTION("Both same value"){
        Position pos{3,3};
        Position pos2{3,4};
        std::optional pc{Piece{'2',1}};
        std::optional pc2{Piece{'2',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,TOP);
        REQUIRE(!board.isPiece(pos2));
    }
    SECTION("Both same value check last position"){
        Position pos{3,3};
        Position pos2{3,4};
        std::optional pc{Piece{'2',1}};
        std::optional pc2{Piece{'2',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,TOP);
        REQUIRE(!board.isPiece(pos));
    }

    SECTION("Scout attacking marechal - move RIGHT"){
        Position pos{2,3};
        Position pos2{6,3};
        std::optional pc{Piece{'0',1}};
        std::optional pc2{Piece{'9',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,RIGHT,4);
        REQUIRE(board.at(pos2)->getSymbole()=='0');
    }
    SECTION("Marechal attacking scout - move LEFT"){
        Position pos{4,2};
        Position pos2{4,3};
        std::optional pc{Piece{'9',1}};
        std::optional pc2{Piece{'0',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,LEFT);
        REQUIRE(board.at(pos)->getSymbole()=='9');
    }
    SECTION("Marechal attacking scout - move BOTTOM"){
        Position pos{8,6};
        Position pos2{8,5};
        std::optional pc{Piece{'9',1}};
        std::optional pc2{Piece{'0',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,BOTTOM);
        REQUIRE(board.at(pos2)->getSymbole()=='9');
    }
    SECTION("Marechal attacking scout - move RIGHT"){
        Position pos{7,5};
        Position pos2{8,5};
        std::optional pc{Piece{'9',1}};
        std::optional pc2{Piece{'0',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,RIGHT);
        REQUIRE(board.at(pos2)->getSymbole()=='9');
    }
    SECTION("Marechal attacking scout - move TOP"){
        Position pos{9,3};
        Position pos2{9,4};
        std::optional pc{Piece{'9',1}};
        std::optional pc2{Piece{'0',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,TOP);
        REQUIRE(board.at(pos2)->getSymbole()=='9');
    }
    SECTION("Attack then check if previous position empty"){
        Position pos{9,3};
        Position pos2{9,4};
        std::optional pc{Piece{'6',1}};
        std::optional pc2{Piece{'5',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos,TOP);
        REQUIRE((!board.isPiece(pos) && board.at(pos2)->getSymbole()=='6'));
    }
    SECTION("Bomb is attacked by non-sapper"){
        Position pos{1,1};
        Position pos2{1,2};
        std::optional pc{Piece{'B',1}};
        std::optional pc2{Piece{'3',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos2,BOTTOM);
        REQUIRE(board.at(pos)->getSymbole()==pc->getSymbole());
    }
    SECTION("Bomb is attacked by a sapper"){
        Position pos{4,4};
        Position pos2{3,4};
        std::optional pc{Piece{'B',1}};
        std::optional pc2{Piece{'2',2}};
        board.at(pos)=pc;
        board.at(pos2)=pc2;
        board.move(pos2,RIGHT);
        REQUIRE(board.at(pos)->getSymbole()==pc2->getSymbole());


    }





}
TEST_CASE("isGameOver"){


}
TEST_CASE("getWinner"){


}
