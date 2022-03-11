#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Facade.hpp"
#include "view.h"
namespace stratego {

class Controller {
    Facade &facade;
    View &view;
public:
    /**
     * @brief Constructor of Controller.
     * @param game game
     * @param view view of the game
     */
    inline Controller(Facade &facade, View &view):facade{facade},view{view}{}

    /**
     * Starts the game.
     */
    void start();
};

}

#endif // CONTROLLER_H
