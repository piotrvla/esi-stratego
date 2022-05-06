#include "controller.hpp"
#include <cmath>
#include <QDebug>

namespace strategoGui{
    void Controller::start(){
        view.show();
        view.controller(this);
        facade.start();
        view.updateGameStatus("You can swap your pieces. \nMake an invalid swap to finish.");
        view.updateCurrentPlayer("Player " + QString::number(facade.getCurrentPlayer()) + " turn.");
    }
}

