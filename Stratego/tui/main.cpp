#include "Controller.h"

int main(){
    Facade facade{};
    stratego::View view{facade};
    stratego::Controller controller{facade,view};
    view.askMove();
    //controller.start();
    return 0;
}

