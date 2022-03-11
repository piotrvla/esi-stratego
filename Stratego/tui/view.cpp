#include "view.h"
using namespace stratego;

string View::askMove(){
    string moveParams;
    regex paramRule("[A-J]{1}+(([1-9])|0)+\\s(TOP|BOTTOM|LEFT|RIGHT)|(\\s+([1-9]))");
    cout<<"Insert position from where you'd like to move, then direction, then the distance(optional)"<<endl;
    cout<<"Example: A5 TOP"<<endl;
    cin>>moveParams;
    transform(moveParams.begin(), moveParams.end(), moveParams.begin(), ::toupper);

    while(!regex_match(moveParams,paramRule)){
        cout<<"Wrong, try again!"<<endl;
        cout<<"Insert position from where you'd like to move, then direction, then the distance(optional)"<<endl;
        cout<<"Example: A5 TOP"<<endl;
        cin>>moveParams;
        transform(moveParams.begin(), moveParams.end(), moveParams.begin(), ::toupper);
    }


    return moveParams;
}
void View::displayBoard(){
    cout<<facade.to_string()<<endl;
}
void View::displayWinner(){
    cout<<"The player "<<facade.getWinner()<<" is the winner!"<<endl;
}
void View::displayCurrentPlayer(){
    cout<<"Current player is the player: "<<facade.getCurrentPlayer()<<endl;
}


