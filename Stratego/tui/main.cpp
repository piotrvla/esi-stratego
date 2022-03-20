#include "Controller.h"
int main(){
    Facade facade{};
    stratego::View view{facade};
    stratego::Controller controller{facade,view};
    Modele::Board board{};
    std::cout<<board.to_string(2);
    return 0;
}

