#include "Controller.h"
#include <iostream>

void stratego::Controller::start(){
    while(!facade.isGameOver()){
        switch(facade.getState()){
            case State::NOT_STARTED:{

            }
            case State::MOVING:{
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
    return Position{position.at(0)-65,
                position.at(1)-65};
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
