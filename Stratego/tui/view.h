#ifndef VIEW_H
#define VIEW_H
#include "Facade.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
namespace stratego{
/**
 * @brief The View class is view of the tui game mode.
 */
class View{

Facade & facade;

public:
    /**
     * @brief View constructor of the view.
     * @param facade is a reference of the facade.
     */
    inline View(Facade &facade):facade(facade){}
    /**
     * @brief askMove asks the player the move until it respect the structure.
     * @return move as a string.
     */
    string askMove();
    /**
     * @brief displayBoard displays the board.
     */
    void displayBoard();
    /**
     * @brief displayWinner displays the winner.
     */
    void displayWinner();
    /**
     * @brief displayCurrentPlayer displays the current player.
     */
    void displayCurrentPlayer();
    /**
     * @brief displayHelp displays additional info about the tui game mode.
     */
    void displayHelp();
    /**
     * @brief displayError displays given errror in the arguments.
     * @param err error to display.
     */
    void displayError(string err);
    /**
     * @brief askSwap asks the player positions to swap in the board.
     * @return positions to swap.
     */
    string askSwap();
    /**
     * @brief printPlayer prints the current player.
     */
    void printPlayer();
};



}


#endif // VIEW_H
