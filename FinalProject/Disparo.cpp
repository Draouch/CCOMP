#include "Disparo.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

Disparo::Disparo(){

    rect.setSize(Vector2f(75,75));
    rect.setFillColor(Color::Red);
    sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));

    if (ProyectilEnemigo==true){

        velocidad = 5;

    }
}

void Disparo::update(){

    if(direccion == 1){ //ARRIBA

        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*3, 75, 75));

    }
    if(direccion == 2){ //ABAJO

        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*0, 75, 75));
    }
    if(direccion == 3){ //IZQUIERDA

        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*1, 75, 75));
    }
    if(direccion == 4){ //DERECHA

        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*2, 75, 75));
    }
    contadorTiempoVida++;
    if(contadorTiempoVida >= TiempoVida){

        contadorTiempoVida = 0;
        destruir = true;
    }

    contadorAnimacion++;
    if(contadorAnimacion >= 2){

        contadorAnimacion = 0;
    }

}
void Disparo::updatePosition(){

    sprite.setPosition(rect.getPosition());

    if(direccion == 1){ //ARRIBA

        rect.move(0, -velocidad);
        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*3, 75, 75));
    }
    if(direccion == 2){ //ABAJO

        rect.move(0, velocidad);
        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 0, 75, 75));
    }
    if(direccion == 3){ //IZQUIERDA

        rect.move(-velocidad, 0);
        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*1, 75, 75));
    }
    if(direccion == 4){ //DERECHA

        rect.move(velocidad, 0);
        sprite.setTextureRect(sf::IntRect(contadorAnimacion*75, 75*2, 75, 75));
    }

}
