#include "controller.hpp"
#include <cmath>
#include <QDebug>

namespace strategoGui{
    void Controller::start(){
        view.show();
        view.controller(this);
        facade.nextPlayer();
        //view.update("move");
    }
    void Controller::move(Position pos1, Position pos2){
        qDebug("ok");
        qDebug("okok");
        if(!facade.isPiece(pos1) || facade.at(pos1).getPlayer()!=facade.getCurrentPlayer()){
            view.updateGameStatus("Cette pièce n'appartient pas au joueur.");
            return;
        }

        view.updateGameStatus("");
        Direction dir;
        int dirVertical=pos1.getX()-pos2.getX();
        int dirHorizontal=pos1.getY()-pos2.getY();
        if(dirVertical>0)
            dir=Direction::TOP;
        else if(dirVertical<0){
            dir=Direction::BOTTOM;
        }else
            if(dirHorizontal<0){
                dir=Direction::RIGHT;
            }
            else if(dirHorizontal>0)
                dir=Direction::LEFT;
            else{
                view.updateGameStatus("Cannot determinate the direction.");
                return;
            }


        int distance;
        if(dir==Direction::TOP || dir== Direction::BOTTOM){
            distance = abs(dirVertical);
        }else if(dir==Direction::LEFT || dir==Direction::RIGHT){
            distance = abs(dirHorizontal);
        }else{
            return;
        }
        if(distance==0){
            view.updateGameStatus("You have to move.");
            return;
        }
        try {
            facade.move(pos1,dir,distance);
            facade.nextPlayer();
            facade.isGameOver();
        }  catch (std::exception &e) {
            view.updateGameStatus(e.what());
        }

        view.updateCurrentPlayer("Player " + QString::number(facade.getCurrentPlayer()) + " turn.");
    }

}

