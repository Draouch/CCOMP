#include <iostream>
#include <string>

using namespace std;

class jugador{

 private:

    string clase;
    int vida;
    int fuerza;
    int agilidad;
    float armadura;
    int oro;
    int nivel;

public:

    jugador(string z, int a, int b, int c, float i, int e, int f);
    void setClase(string x);
    void setVida(int h);
    void setFuerza(int s);
    void setAgilidad(int d);
    void setArmadura(float arm);
    void setOro(int g);
    void setNivel(int l);
    void addVida();
    void subVida();
    void addOro();
    void subOro();
    void addNivel();

    string getClase(){

        return clase;

    }

    int getVida(){

    return vida;

    }

    int getFuerza(){

        return fuerza;

    }

    int getAgilidad(){

        return agilidad;

    }

    float getArmadura(){

        return armadura;

    }

    int getOro(){

        return oro;

    }

    int getNivel(){

        return nivel;

    }

};
