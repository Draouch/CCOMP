#include "Jugador.h"
#include "Objeto.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


Jugador::Jugador(){

    rect.setSize(Vector2f(dimension,dimension));
    rect.setPosition(Vector2f(400,200));
    sprite.setTextureRect(sf::IntRect(0, 0, dimension, dimension));

}

void Jugador::update(){

    sprite.setPosition(rect.getPosition());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        if(IrArriba == true){
            rect.move(0,-velocidad);
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*3, dimension, dimension));
        direccion = 1;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        if (IrAbajo == true){
            rect.move(0,velocidad);
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*0, dimension, dimension));
        direccion = 2;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        if (IrIzquierda == true){

            rect.move(-velocidad,0);
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*1, dimension, dimension));
        direccion = 3;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        if (IrDerecha == true){

            rect.move(velocidad,0);
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }
        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*2, dimension, dimension));
        direccion = 4;

    }

}

void Jugador::updateMovimiento(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        if(IrArriba==true){

            rect.move(0,-velocidad);
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*3, dimension, dimension));
        direccion = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        if(IrAbajo==true){

             rect.move(0,velocidad);
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*0, dimension, dimension));
        direccion = 2;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        if(IrIzquierda==true){

             rect.move(-velocidad,0);
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*1, dimension, dimension));
        direccion = 3;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        if(IrDerecha==true){

            rect.move(velocidad,0);
        }

        sprite.setTextureRect(sf::IntRect(contadorpasos*dimension, dimension*2, dimension, dimension));
        direccion = 4;

    }

    contadorpasos++;
    if(contadorpasos>=3){

        contadorpasos = 0;

    }
}
