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
    this->setWindowTitle("Stratego - Smolinski Piotr & Noé Delcroix");

    facade.addObserver(this);
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

    }
}
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
        updateBoard();
    }else if(propertyName=="game over"){
        gameOver();


    }

}
void View::resizeEvent(QResizeEvent *e){
    ui->gridLayoutWidget->setFixedSize(ui->centralwidget->width()*0.7,ui->centralwidget->height());
    ui->verticalLayoutWidget->setGeometry(ui->centralwidget->width()/2,0,ui->gridLayoutWidget->width(),ui->verticalLayoutWidget->height());
    ui->verticalLayoutWidget->setFixedSize(ui->centralwidget->width()*0.7,ui->centralwidget->height());

}


View::~View()
{
    delete ui;
}



