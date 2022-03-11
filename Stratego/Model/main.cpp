#include "Board.hpp"
#include <iostream>


int main(){
    Modele::Board test;
    //std::cout<<test.to_string()<<std::endl;
    std::cout<<test.at(Position{4,0})->getPlayer()<<std::endl;;
    std::cout<<test.at(Position{4,0})->getSymbole()<<std::endl;;
    std::cout<<test.at(Position{3,0})->getSymbole()<<std::endl;
    std::cout<<test.at(Position{3,0})->getPlayer()<<std::endl;
    test.move(Position{3,0},Direction::BOTTOM);

    std::cout<<test.to_string()<<std::endl;
    return(0);
}
