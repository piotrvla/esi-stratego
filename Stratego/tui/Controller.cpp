#include "Controller.h"
#include <iostream>

void stratego::Controller::start(){
    while(true){
        switch(facade.getState()){
            case State::NOT_STARTED:{
                facade.start();
            }
            case State::MOVING:{
                view.displayBoard();
                std::string moveParams=view.askMove();
                facade.move(createPosition(moveParams.substr(0, moveParams.find(" "))),
                            createDirection(moveParams.substr(1, moveParams.find(" "))));
                facade.isGameOver();
            }
            case State::NEXT_PLAYER:{
                facade.nextPlayer();
            }

            case State::GAME_OVER:{
                //possibilité de jouer une autre partie ou pas?
            }

        }


    }

}

Position stratego::Controller::createPosition(std::string position){
    Position p = Position{position.at(1)-49,
                position.at(0)-65};

    if(facade.getCurrentPlayer()==1){
        cout<<"board size : "<<facade.getBoardSize()<<endl;
        cout<<"x:"<<facade.getBoardSize()-1-p.getX()<<"y:"<<facade.getBoardSize()-1-p.getY()<<endl;
        return Position(facade.getBoardSize()-1-p.getX(), facade.getBoardSize()-1-p.getY());
    }else{
        std::cout<<"x:"<<p.getX()<<"y:"<<p.getY()<<endl;
        return p;
    }

}

Direction stratego::Controller::createDirection(std::string direction){
    if(direction.compare("TOP")==0){
        return Direction::TOP;
    }else if(direction.compare("BOTTOM")==0){
        return Direction::BOTTOM;
    }else if(direction.compare("LEFT")==0){
        return Direction::LEFT;
    }else{
        return Direction::RIGHT;
    }
}

int stratego::Controller::createDistance(std::string distance){
    return distance.at(0)-49;
}
