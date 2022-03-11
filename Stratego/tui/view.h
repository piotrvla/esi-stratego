#ifndef VIEW_H
#define VIEW_H
#include "Facade.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
using namespace std;
namespace stratego{

class View{

Facade & facade;

public:
inline View(Facade &facade):facade(facade){}
string askMove();
void displayBoard();
void displayWinner();
void displayCurrentPlayer();
void displayHelp();
};



}


#endif // VIEW_H
