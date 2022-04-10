#include <QApplication>
#include "Facade.hpp"
#include "view.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Facade facade{};
    View w{facade};
    strategoGui::Controller controller(facade,w);
    controller.start();
    return a.exec();
}
