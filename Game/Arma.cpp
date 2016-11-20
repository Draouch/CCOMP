#include "Arma.h"

arma::arma(string a, float b, float c){

    setNombre(a);
    setAtaquePrincipal(b);
    setAtaqueSecundario(c);

}

void arma::setNombre(string x){

    nombre = x;

}

void arma::setAtaquePrincipal(float y){

    AtaquePrincipal = y;

}

void arma::setAtaqueSecundario(float z){

    AtaqueSecundario = z;

}

void arma::mejorarAtaquePrincipal(){

    AtaquePrincipal=AtaquePrincipal+2;

}

void arma::mejorarAtaqueSecundario(){

    AtaqueSecundario=AtaqueSecundario+1;

}
