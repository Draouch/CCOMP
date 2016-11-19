#include "Enemigo.h"
#include "Objeto.h"
#include "Random.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

Enemigo::Enemigo(){

    rect.setSize(Vector2f(dimensionx,dimensiony));
    rect.setPosition(Vector2f(600,200));
    sprite.setTextureRect(sf::IntRect((contadorpasos*dimensionx) + dimensionxStart, (dimensiony*0) + dimensionyStart, dimensionx, dimensiony));

}

void Enemigo::update(){

    sprite.setPosition(rect.getPosition());

}

void Enemigo::updateMovimiento(){

    if (direccion == 1){ //ARRIBA

        if (IrArriba == true){

            rect.move(0,-velocidad);
            sprite.setTextureRect(sf::IntRect((contadorpasos*dimensionx) + dimensionxStart, (dimensiony*3) + dimensionyStart, dimensionx, dimensiony));
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }
    }
    else if (direccion == 2){ //ABAJO

        if (IrAbajo == true){

            rect.move(0,velocidad);
            sprite.setTextureRect(sf::IntRect((contadorpasos*dimensionx) + dimensionxStart, (dimensiony*0) + dimensionyStart, dimensionx, dimensiony));
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }
    }
    else if (direccion == 3){ //IZQUIERDA

        if (IrIzquierda == true){

            rect.move(-velocidad,0);
            sprite.setTextureRect(sf::IntRect((contadorpasos*dimensionx) + dimensionxStart, (dimensiony*1) + dimensionyStart, dimensionx, dimensiony));
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }
    }
    else if (direccion == 4){ //DERECHA

        if (IrDerecha == true){

            rect.move(velocidad,0);
            sprite.setTextureRect(sf::IntRect((contadorpasos*dimensionx) + dimensionxStart, (dimensiony*2) + dimensionyStart, dimensionx, dimensiony));
            IrArriba = true;
            IrAbajo = true;
            IrIzquierda = true;
            IrDerecha = true;
        }
    }

    contadorpasos++;

    if(contadorpasos>=3){

        contadorpasos = 0;

    }

    contador++;
    if (contador >= 10){

        direccion = generarRandom(5);
        contador = 0;

    }
}
