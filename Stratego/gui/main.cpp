#include "Position.hpp"
#include "Facade.hpp"
#include "boardGui.hpp"
#include "controller.hpp"
#include "view.hpp"
#include "case.hpp"
#include "ui_stratego.h"

#include "qapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Facade facade{};

    strategoGui::View w(facade);
    strategoGui::Controller controller(facade,w);
    controller.start();
    return a.exec();
}
