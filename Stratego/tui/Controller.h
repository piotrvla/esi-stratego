#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Facade.hpp"
#include "view.h"
namespace stratego {
/**
 * @brief The Controller class is the controller of the tui game mode.
 */
class Controller {
    Facade &facade;
    View &view;
    /**
     * @brief createPosition converts the string into a position.
     * @param position as a string.
     * @return converted position.
     */
    Position createPosition(std::string position);
    /**
     * @brief createDirection converts the string into a direction.
     * @param direction as a string.
     * @return converted direction.
     */
    Direction createDirection(std::string direction);
    /**
     * @brief createDistance converts the string into the distance.
     * @param distance as a string.
     * @return converted distance.
     */
    int createDistance(std::string distance);
public:
    /**
     * @brief Constructor of Controller.
     * @param game game
     * @param view view of the game
     */
    inline Controller(Facade &facade, View &view):facade{facade},view{view}{}

    /**
     * @brief start starts the game.
     */
    void start();
};

}

#endif // CONTROLLER_H
