#include "boardGui.hpp"
#include "Facade.hpp"
#include "case.hpp"
#include "qlayoutitem.h"
#include "ui_stratego.h"
#include "controller.hpp"

namespace strategoGui{
Board::Board(Ui::View * ui, strategoGui::View * view, Facade & facade, QWidget * parent):movPosInit(-1,-1), movPosEnd(-1,-1), ui{ui}, facade{facade}, view{view}, parent{parent}, dragStatus{false}{}


void Board::updateBoard(){
        QLayoutItem *child;
        while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    for (int i=0;i<10 ;i++ ) {
        for (int j =0;j<10 ;j++ ) {
            if(facade.isPiece(Position{i,j})){
                Case *piece = new Case(facade.at(Position{i,j}).getPlayer(),
                                     facade.at(Position{i,j}).getSymbole(),Position{i,j},facade.at(Position{i,j}).getPlayer()!=facade.getCurrentPlayer(),parent);
                ui->gridLayout->addWidget(piece,i,j);
                if(facade.at(Position{i,j}).getSymbole()!='W'){
                    QObject::connect(piece,SIGNAL(sendValue(Position)),this,SLOT(positionHandler(Position)));
                    QObject::connect(piece,SIGNAL(sendDragStatus(bool)),this,SLOT(dragStatusHandler(bool)));
                }
             }else{
                Case *piece = new Case(0,'E',Position{i,j},false,parent);
                ui->gridLayout->addWidget(piece,i,j);
                QObject::connect(piece,SIGNAL(sendValue(Position)),this,SLOT(positionHandler(Position)));
                QObject::connect(piece,SIGNAL(sendDragStatus(bool)),this,SLOT(dragStatusHandler(bool)));
            }
         }
     }

}

void Board::positionHandler(Position pos){
    view->updateGameStatus("");
    if(movPosInit.getX()==-1 && movPosInit.getY()==-1)
        movPosInit=pos;
    else
        movPosEnd=pos;

    if(!dragStatus && movPosInit.getX()!=-1 && movPosInit.getY()!=-1 && movPosEnd.getX()!=-1 && movPosEnd.getY()!=-1){
        if(facade.getState()==State::MOVING){
        move(movPosInit, movPosEnd);
        }else if(facade.getState()==State::SWAPING){
            try{
            facade.swap(movPosInit, movPosEnd);
            }catch(std::exception & e){
                view->updateGameStatus("Invalid swap. Going to next player.");
                facade.nextPlayer();
                view->updateCurrentPlayer("Player " + QString::number(facade.getCurrentPlayer()) + " turn.");
            }
        }
        movPosInit=Position(-1, -1);
        movPosEnd=Position(-1,-1);

    }
}

void Board::dragStatusHandler(bool status){
    dragStatus=status;
    qDebug("%d", status);
    positionHandler(movPosEnd);

}

void Board::move(Position pos1, Position pos2){
    qDebug("%d", facade.getState());
    if(!facade.isPiece(pos1) || facade.at(pos1).getPlayer()!=facade.getCurrentPlayer()){
        view->updateGameStatus("Cette pièce n'appartient pas au joueur.");
        return;
    }

    view->updateGameStatus("");
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
            view->updateGameStatus("Cannot determinate the direction.");
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
        view->updateGameStatus("You have to move.");
        return;
    }
    try {
        facade.move(pos1,dir,distance);
        facade.nextPlayer();
        facade.isGameOver();
    }  catch (std::exception &e) {
        view->updateGameStatus(e.what());
    }

    view->updateCurrentPlayer("Player " + QString::number(facade.getCurrentPlayer()) + " turn.");
}

}
