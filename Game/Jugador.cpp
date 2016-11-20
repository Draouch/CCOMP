#include "Jugador.h"

jugador::jugador(string z, int a, int b, int c, float i, int e, int f){

    setClase(z);
    setVida(a);
    setFuerza(b);
    setAgilidad(c);
    setArmadura(i);
    setOro(e);
    setNivel(f);

}

void jugador::setClase(string x){

    clase = x;

}

void jugador::setVida(int h){

    vida = h;

}

void jugador::setFuerza(int s){

    fuerza = s;

}

void jugador::setAgilidad(int d){

    agilidad = d;
}

void jugador::setArmadura(float arm){

    armadura=arm;

}

void jugador::setOro(int g){

    oro = g;

}

void jugador::setNivel(int l){

    nivel = l;
}

void jugador::addVida(){

    ++vida;

}

void jugador::subVida(){

    --vida;

}

void jugador::addOro(){

    ++oro;

}

void jugador::subOro(){

    --oro;

}

void jugador::addNivel(){

    ++nivel;

}
