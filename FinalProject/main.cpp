#include "Funciones.h"

int main(){

    Game* RPG = Game::getSingleton();
    RPG -> Menu();
    delete Game::getSingleton();
    return 0;

}
