#include "view.h"
using namespace stratego;
using namespace std;
std::string View::askMove(){
    std::string moveParams;
/*
    while(!areParamsValid(moveParams)){
        cout<<"Please insert the position as a x y value."<<endl;


    }
    */
    return moveParams;
}
void View::displayBoard(){

}
void View::displayWinner(){
    cout<<"The player "<<facade.getWinner()<<" is the winner!"<<endl;
}
void View::displayCurrentPlayer(){
    cout<<"Current player is the player: "<<facade.getCurrentPlayer()<<endl;

}

