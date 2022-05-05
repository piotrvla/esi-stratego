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

class View : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    View(Facade &f, QWidget *parent = nullptr);
    /*inline void controller(Controller & controller){
        ctrl_ = controller;
    }*/
    void updateGameStatus(QString text);
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
    void gameOver();
    void resizeEvent(QResizeEvent *e);

};
}

#endif // VIEW_HPP
