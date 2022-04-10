#include "view.hpp"
#include "controller.hpp"
#include "ui_stratego.h"
#include <QMessageBox>
#include <QPalette>
#include <QPalette>
#include <QPushButton>
#include <iostream>
#include <string>
#include "case.hpp"
View::View(Facade &f, QWidget *parent)
    : QMainWindow(parent)
    , facade{f}
    , ui(new Ui::View)
    , buttonsClicked{}

{
    ui->setupUi(this);
    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);
    this->setWindowTitle("Stratego - Smolinski Piotr & Noé Delcroix");
    updateBoard();
}

void View::updateBoard(){
        QLayoutItem *child;
        while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
    for (int i=0;i<10 ;i++ ) {
        for (int j =0;j<10 ;j++ ) {
            if(facade.isPiece(Position{i,j})){
                Case *piece = new Case(facade.at(Position{i,j}).getPlayer(),
                                     facade.at(Position{i,j}).getSymbole(),Position{i,j},facade.at(Position{i,j}).getPlayer()!=facade.getCurrentPlayer(),this);
                ui->gridLayout->addWidget(piece,i,j);
                if(facade.at(Position{i,j}).getSymbole()!='W')
                    connect(piece,SIGNAL(sendValue(Position)),this,SLOT(eventHandler(Position)));
             }else{
                Case *piece = new Case(0,'E',Position{i,j},false,this);
                ui->gridLayout->addWidget(piece,i,j);
                connect(piece,SIGNAL(sendValue(Position)),this,SLOT(eventHandler(Position)));
            }
         }
     }

}
void View::eventHandler(Position pos){
    buttonsClicked.push_back(pos);
    if(buttonsClicked.size()>=2){
        ctrl_->move(buttonsClicked.at(0),buttonsClicked.at(1));
        buttonsClicked.clear();
        updateBoard();
    }
}
void View::updateGameStatus(QString text){
    ui->gamestatus->setText(text);
}
void View::updateCurrentPlayer(QString text){
    ui->player->setText(text);

}


View::~View()
{
    delete ui;
}



