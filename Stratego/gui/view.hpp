#ifndef VIEW_HPP
#define VIEW_HPP

#include "boardGui.hpp"
#include "qglobal.h"
#include <QMainWindow>

#include "observer.h"
#include "Position.hpp"
#include "Facade.hpp"

QT_BEGIN_NAMESPACE
namespace Ui{
class View;
}
QT_END_NAMESPACE

namespace strategoGui{
/**
 * @brief The View class is the main class of the graphical ui.
 */
class View : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    /**
     * @brief View's constructor.
     * @param f is the facade  of the game.
     * @param parent of the instance.
     */
    View(Facade &f, QWidget *parent = nullptr);
    /*inline void controller(Controller & controller){
        ctrl_ = controller;
    }*/
    /**
     * @brief updateGameStatus updates the game status by modyfing a label.
     * @param text to set.
     */
    void updateGameStatus(QString text);
    /**
     * @brief updateCurrentPlayer updates the label that indicates the current palyer.
     * @param text is the current player.
     */
    void updateCurrentPlayer(QString text);
    inline void controller(strategoGui::Controller * controller){
            ctrl_ = controller;
        }

    void update(const std::string & propertyName) override;

    ~View();

private:
    Facade &facade;
    Ui::View * ui;
    std::vector<Position> buttonsClicked;
    strategoGui::Board board;
    strategoGui::Controller * ctrl_=nullptr;
    /**
     * @brief gameOver updates the labels whenever the game is over.
     */
    void gameOver();
    /**
     * @brief resizeEvent modifies widgets size within the new window's size.
     */
    void resizeEvent(QResizeEvent *e);

};
}

#endif // VIEW_HPP
