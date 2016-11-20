#include <iostream>
#include <string>

using namespace std;

class arma{

private:

    string nombre;
    float AtaquePrincipal;
    float AtaqueSecundario;

public:

    arma(string a, float b, float c);
    void setNombre(string x);
    void setAtaquePrincipal(float y);
    void setAtaqueSecundario(float z);
    void mejorarAtaquePrincipal();
    void mejorarAtaqueSecundario();

    string getNombre(){

        return nombre;

    }

    float getAtaquePrincipal(){

        return AtaquePrincipal;

    }

    float getAtaqueSecundario(){

        return AtaqueSecundario;

    }

};
