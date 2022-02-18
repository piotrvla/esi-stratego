#include <Board.hpp>

Modele::Board::Board(){
    initializeArmy();
}

inline std::optional<Piece> Modele::Board::getPiece(Position pos){
    return board.at(pos.getX()).at(pos.getY());
}

void Modele::Board::initializeArmy(){

}

void Modele::Board::swapPieces(Position pos1, Position pos2){

}

inline bool Modele::Board::isPiece(Position pos){
    try {
        this->board.at(pos.getX()).at(pos.getY()).value();
    }  catch (const std::bad_optional_access &ex) {
        return false;
    }
    return true;
}
void Modele::Board::move(Position pos, Direction direction, int distance){
    if(!isPiece(pos))
        throw std::invalid_argument("That's not a piece to move!");
    else if(!isInside(pos)){
        throw std::invalid_argument("Given position is out of bonds");
    }
    if(getPiece(pos).value().getSymbole()=='F' || getPiece(pos).value().getSymbole()=='B'){
        throw std::invalid_argument("Bombs or flags cannot move!");
    }

    switch(direction){
        case Direction::TOP:
            Position moveAt{pos.getX(),pos.getY()+distance};
            if(!isInside(moveAt))
                throw std::invalid_argument("Cannot move there! Out of the board");
            if(isPiece(moveAt) && getPiece(moveAt).value().getSymbole()=='W')
                throw std::invalid_argument("Obstacle at given destination");
            if(distance!=1){
                for(int i=1;i<distance;i++){
                    if(isInside(Position{pos.getX(),pos.getY()+i})
                            && isPiece(Position{pos.getX(),pos.getY()+i}))
                        throw std::invalid_argument("Piece cannot move there!");
                }
            }
            setPiece(moveAt,attack(getPiece(pos),getPiece(moveAt)));
            break;


        case Direction::LEFT:
            Position moveAt{pos.getX(),pos.getY()+distance};



        break;
        case RIGHT:
        break;
        case BOTTOM:

        break;

    }

}

