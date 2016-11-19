#include "Texto.h"
#include <sstream>
#include <string>

Texto::Texto(){

    text.setColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setString(myString);

}

void Texto::update(){

    text.move(0,-velocidad);
    contador++;
    if (contador >= TiempoVida){

        destruir = true;

    }
}

string Texto::to_string(int x){

    int numero = x;

    stringstream ss;
    ss << numero;

    return ss.str();

}
