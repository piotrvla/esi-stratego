#include "view.h"
using namespace stratego;


string View::askSwap(){
    string swapParams;
    regex paramRule("([A-J]{1}[1-9]{1} [A-J]{1}[1-9]{1})( )*|END");
    cout<<"To swap pieces, type the two piece positions like this : A7 C7"<<endl;
    cout<<"Type END to start the game"<<endl;
    getline(cin, swapParams);
    transform(swapParams.begin(), swapParams.end(), swapParams.begin(), ::toupper);
    while(!regex_match(swapParams,paramRule)){
        cout<<"Wrong, try again!"<<endl;
        cout<<"To swap pieces, type the two piece positions like this : A7 C7 or E5 RIGHT 3"<<endl;
        cout<<"Type END to start the game"<<endl;
        getline(cin, swapParams);
        transform(swapParams.begin(), swapParams.end(), swapParams.begin(), ::toupper);
    }
    return swapParams;
}

string View::askMove(){
    string moveParams;
    regex paramRule("[A-J]{1}(([1-9])|0)+\\s(TOP|BOTTOM|LEFT|RIGHT)+(\\s(([1-9])))?");
    cout<<"Insert position from where you'd like to move, then direction, then the distance(optional)"<<endl;
    cout<<"Example: A7 TOP"<<endl;
    getline(cin, moveParams);
    transform(moveParams.begin(), moveParams.end(), moveParams.begin(), ::toupper);
    while(!regex_match(moveParams,paramRule)){
        cout<<"Wrong, try again!"<<endl;
        cout<<"Insert position from where you'd like to move, then direction, then the distance(optional)"<<endl;
        cout<<"Example: A5 TOP"<<endl;
        getline(cin, moveParams);
        transform(moveParams.begin(), moveParams.end(), moveParams.begin(), ::toupper);
    }
    return moveParams;
}
char View::askCheatMode(){
    string cheatMode;
    cout<<"Do you want to use the cheat mode? [y/n]"<<endl;
    regex cheatAnswer("(^[y].*){1}|(^[n].*){1}");
    getline(cin, cheatMode);
    transform(cheatMode.begin(), cheatMode.end(), cheatMode.begin(), ::tolower);
    while(!regex_match(cheatMode,cheatAnswer)){
        cout<<"Answer is y or n, try again."<<endl;
        getline(cin, cheatMode);

    }
    return cheatMode.at(0);
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

void View::displayError(string err){
    cout<<err<<endl;
}

void View::printPlayer(){
    cout<<"########PLAYER "<<facade.getCurrentPlayer()<<"########\n\n"<<endl;
}
