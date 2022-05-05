#include "view.hpp"
#include "boardGui.hpp"
#include "ui_stratego.h"
#include <QMessageBox>
#include <QPalette>
#include <QPalette>
#include <QPushButton>
#include <iostream>
#include <string>
#include "case.hpp"
#include "controller.hpp"

namespace strategoGui{
View::View(Facade &f, QWidget *parent)
    : QMainWindow(parent)
    , facade{f}
    , ui(new Ui::View)
    , buttonsClicked{}
    , board(ui, this, facade, parent)

{
    ui->setupUi(this);
    this->setWindowTitle("Stratego - Smolinski Piotr & Noé Delcroix");

    facade.addObserver(this);
    board.setController(ctrl_);
    board.updateBoard();
}
/*
void View::dragEventHandler(bool status){
    qDebug("dragStatus");
}

void View::eventHandler(Position pos){
    qDebug("%zu", buttonsClicked.size());
    if(buttonsClicked.size()==0 || pos.getX()!=buttonsClicked.at(0).getX() || pos.getY()!=buttonsClicked.at(0).getY()){
        qDebug("ok");
    buttonsClicked.push_back(pos);
    }
    if(buttonsClicked.size()>=2 && !dragStatus){
        while(buttonsClicked.size()>2){
            buttonsClicked.erase(buttonsClicked.begin()+1);
        }
        ctrl_->move(buttonsClicked.at(0),buttonsClicked.at(1));
        //Si le deuxième emplacement n'est pas une pièce ou si la deuxième pièce n'appartient pas au joueur courant
        if(!facade.isPiece(buttonsClicked.at(1)) || facade.at(buttonsClicked.at(1)).getPlayer()!=facade.getCurrentPlayer()){
        buttonsClicked.clear();
        }else{
            buttonsClicked.erase(buttonsClicked.begin());
        }
    }else if(buttonsClicked.size()==1 && (!facade.isPiece(pos) || facade.at(pos).getPlayer()!=facade.getCurrentPlayer())){
        //Si le premier emplacement cliqué n'est pas une pièce ou n'appartient pas au joueur.
        updateGameStatus("Cette pièce n'appartient pas au joueur.");
        buttonsClicked.clear();
    }
}
*/
void View::updateGameStatus(QString text){
    ui->gamestatus->setText(text);
}
void View::updateCurrentPlayer(QString text){
    ui->player->setText(text);

}
void View::gameOver(){
    QLayoutItem *child;
    while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    ui->player->setText("");
    ui->winner->setText("Player " + QString::number(facade.getWinner())+" is the winner.");

}
void View::update(const std::string & propertyName){
    if(propertyName=="move"){
        board.updateBoard();
    }else if(propertyName=="game over"){
        gameOver();


    }

}

void View::resizeEvent(QResizeEvent *e){
    ui->gridLayoutWidget->setFixedSize(ui->centralwidget->width()*0.5,ui->centralwidget->height());
    //ui->verticalLayoutWidget->setGeometry(ui->centralwidget->width()/2,0,ui->gridLayoutWidget->width(),ui->verticalLayoutWidget->height());
    ui->verticalLayoutWidget->setFixedSize(ui->centralwidget->width()*0.5,ui->centralwidget->height());

}


View::~View()
{
    //delete ui;
}

}


