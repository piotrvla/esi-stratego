#include "Controller.h"
#include <iostream>
#include <algorithm>

void stratego::Controller::start(){
    while(true){
        view.printPlayer();
        switch(facade.getState()){
            case State::NOT_STARTED:{
                facade.start();
                break;
            }
        case State::SWAPING:{
            view.displayBoard();
            std::string swapParams;
            while((swapParams=view.askSwap())!="END"){
                view.printPlayer();
                Position p1 = createPosition(swapParams.substr(0, swapParams.find(" ")));
                swapParams=swapParams.erase(0, swapParams.find(" ")+1);

                try{
                facade.swap(p1, createPosition(swapParams));
                }catch(std::exception & e){
                    view.displayError("Swap interdit.");
                }
                view.displayBoard();
            }
            facade.nextPlayer();
            break;
        }
            case State::MOVING:{
            view.displayBoard();
                std::string moveParams=view.askMove();
                Position p = createPosition(moveParams.substr(0, moveParams.find(" ")));
                moveParams=moveParams.erase(0, moveParams.find(" ")+1);
                Direction d=createDirection(moveParams.substr(0, moveParams.find(" ")));
                moveParams=moveParams.erase(0, moveParams.find(" ")+1);
                int dist = 1;

                try{
                    dist = stoi(moveParams.substr(0, moveParams.find(" ")));
                }catch(exception & e){}
                try{
                facade.move(p, d, dist);
                }catch(std::exception & e){
                    view.displayError("Deplacement interdit.");
                }

                facade.isGameOver();
                break;
            }
            case State::NEXT_PLAYER:{
                facade.nextPlayer();
                break;
            }

            case State::GAME_OVER:{
                //possibilité de jouer une autre partie ou pas?
                view.displayWinner();
                break;
            }

        }


    }

}

Position stratego::Controller::createPosition(std::string position){
    Position p = Position{position.at(1)-48, position.at(0)-65};

    if(facade.getCurrentPlayer()==1){
        return Position(facade.getBoardSize()-1-p.getX(), facade.getBoardSize()-1-p.getY());
    }else{
        return p;
    }

}

Direction stratego::Controller::createDirection(std::string direction){
    direction.erase(remove(direction.begin(), direction.end(), ' '), direction.end());
    if(direction.compare("TOP")==0){
        return facade.getCurrentPlayer()==1 ? Direction::BOTTOM : Direction::TOP;
    }else if(direction.compare("BOTTOM")==0){
        return facade.getCurrentPlayer()==1 ? Direction::TOP : Direction::BOTTOM;
    }else if(direction.compare("LEFT")==0){
        return facade.getCurrentPlayer()==1 ? Direction::RIGHT : Direction::LEFT;
    }else{
        return facade.getCurrentPlayer()==1 ? Direction::LEFT : Direction::RIGHT;
    }
}

int stratego::Controller::createDistance(std::string distance){
    return distance.at(0)-49;
}
