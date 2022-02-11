#include <Board.hpp>

Modele::Board::Board(std::string fileName){
    initializeArmy(fileName);
}

inline std::optional<Piece> Modele::Board::getPiece(Position pos){
    return board.at(pos.getX()).at(pos.getY());
}

void Modele::Board::setPiece(Position pos, std::optional<Piece> piece){
    board.at(pos.getX()).at(pos.getY())=piece;
}

void Modele::Board::initializeArmy(std::string fileName){

}

void Modele::Board::swapPieces(Position pos1, Position pos2){

}
bool Modele::Board::isInside(Position pos){
    return 0>=pos.getX() && pos.getX()<BOARD_SIZE && 0>=pos.getY()&&pos.getY()<BOARD_SIZE;
}


inline bool Modele::Board::isPiece(Position pos){
    try {
        this->board.at(pos.getX()).at(pos.getY()).value();
    }  catch (const std::bad_optional_access &ex) {
        return false;
    }
    return true;
}

std::optional<Piece> Modele::Board::attack(std::optional<Piece> piece, std::optional<Piece> piece2){
    if(piece->getSymbole()=='2' && piece2->getSymbole()=='B')
        return piece;
    else if(piece2->getSymbole()=='B')
        return piece2;
    else if(piece->getSymbole()=='0' && piece2->getSymbole()=='9')
        return piece;
    else if(piece2->getSymbole()=='F')
        return piece;
    else if(piece->getSymbole()>piece2->getSymbole())
        return piece;
    else if(piece->getSymbole()<piece2->getSymbole())
        return piece2;
    else
        return std::optional<Piece>{};


}
void Modele::Board::move(Position pos, Direction direction, int distance){
    if(!isPiece(pos))
        throw std::invalid_argument("That's not a piece to move!");
    else if(!isInside(pos)){
        throw std::invalid_argument("Given position is out of bonds");
    }
    if(getPiece(pos).value().getSymbole()=='F' || getPiece(pos).value().getSymbole()=='B'){
        throw std::invalid_argument("Bombs or flags cannot move!");
    } else if(getPiece(pos)->getSymbole()!='2' && distance !=1 ){
        throw std::invalid_argument("This piece cannot move more than 1 case at the time");
    }

    switch(direction){
        case Direction::TOP:{
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
        }

        case Direction::LEFT:{
            Position moveAt{pos.getX()-distance, pos.getY()};
            if(!isInside(moveAt))
                throw std::invalid_argument("Cannot move there! Out of the board");
            if(isPiece(moveAt) && getPiece(moveAt).value().getSymbole()=='W')
                throw std::invalid_argument("Obstacle at given destination");
            if(distance!=1){
                for(int i=1;i<distance;i++){
                    if(isInside(Position{pos.getX()-i,pos.getY()})
                            && isPiece(Position{pos.getX()-i,pos.getY()}))
                        throw std::invalid_argument("Piece cannot move there!");
                }
            }
            setPiece(moveAt,attack(getPiece(pos),getPiece(moveAt)));
            break;
        }




        case RIGHT:{
            Position moveAt{pos.getX()+distance, pos.getY()};
            if(!isInside(moveAt))
                throw std::invalid_argument("Cannot move there! Out of the board");
            if(isPiece(moveAt) && getPiece(moveAt).value().getSymbole()=='W')
                throw std::invalid_argument("Obstacle at given destination");
            if(distance!=1){
                for(int i=1;i<distance;i++){
                    if(isInside(Position{pos.getX()+i,pos.getY()})
                            && isPiece(Position{pos.getX()+i,pos.getY()}))
                        throw std::invalid_argument("Piece cannot move there!");
                }
            }
            setPiece(moveAt,attack(getPiece(pos),getPiece(moveAt)));
            break;
        }
        case BOTTOM:{
            Position moveAt{pos.getX(), pos.getY()-distance};
            if(!isInside(moveAt))
                throw std::invalid_argument("Cannot move there! Out of the board");
            if(isPiece(moveAt) && getPiece(moveAt).value().getSymbole()=='W')
                throw std::invalid_argument("Obstacle at given destination");
            if(distance!=1){
                for(int i=1;i<distance;i++){
                    if(isInside(Position{pos.getX(),pos.getY()-distance})
                            && isPiece(Position{pos.getX(),pos.getY()-distance}))
                        throw std::invalid_argument("Piece cannot move there!");
                }
            }
            setPiece(moveAt,attack(getPiece(pos),getPiece(moveAt)));
            break;
        }

    }

}

