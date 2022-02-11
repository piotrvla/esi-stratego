#include <Board.hpp>

Modele::Board::Board(){
    initializeArmy();
}

inline std::optional<Piece> Modele::Board::getPiece(Position pos){
    return board.at(pos.getX()).at(pos.getY());
}

void initializeArmy(){

}

