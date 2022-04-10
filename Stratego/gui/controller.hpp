#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "view.hpp"
class Facade;
class View;
namespace strategoGui {
/**
 * @brief The Controller class allows to link the model and the view.
 * It manages the game mechanism for the graphic version .
 */
class Controller {
    Facade &facade;
    View & view;

public:
    /**
     * @brief Constructor of Controller.
     * @param game game
     * @param view view of the game
     */
    Controller(Facade &facade, View &view) :
        facade{facade}, view{view} {
    }
    /**
     * @brief Starts the game.
     */
    void start();

    void move(Position pos1, Position pos2);


};

}

#endif //CONTROLLER_HPP
