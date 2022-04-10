#include "view.hpp"
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
{
    ui->setupUi(this);
    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);
    this->setWindowTitle("Stratego");
    updateBoard();
}

void View::updateBoard(){
    for ( QObject * a :this->ui->gridLayout->children() ) {
        a->~QObject();
    }
    for (int i=0;i<10 ;i++ ) {
        for (int j =0;j<10 ;j++ ) {
            QString are;
            if(facade.isPiece(Position{i,j})){
                Case *piece = new Case(facade.at(Position{i,j}).getPlayer(),
                                     facade.at(Position{i,j}).getSymbole(),Position{i,j},this);
                ui->gridLayout->addWidget(piece,i,j);
             }
         }
     }

}
void View::eventHandler(int i, int j){
    ui->label->setText("a");
}


View::~View()
{
    delete ui;
}



