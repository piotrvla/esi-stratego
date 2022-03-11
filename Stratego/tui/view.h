#ifndef VIEW_H
#define VIEW_H
#include "Facade.hpp"
#include <iostream>
namespace stratego{

class View{

Facade & facade;
bool areParamsValid(std::string params);
public:
inline View(Facade &facade):facade(facade){}
std::string askMove();
void displayBoard();
void displayWinner();
void displayCurrentPlayer();
};



}


#endif // VIEW_H
