#include "Objeto.h"
#include "Random.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Enemigo : public Objeto{

    private:
    protected:
    public:
        Enemigo();
        int dimensionx = 32;
        int dimensiony = 35;
        int dimensionxStart=32*0;
        int dimensionyStart=35*4;
        int hp = 3;
        int maxhp = 3;
        int poderAtaque = 1;
        bool vivo = true;
        bool IrArriba = true;
        bool IrAbajo = true;
        bool IrIzquierda = true;
        bool IrDerecha = true;
        bool herido = false;
        bool boss1 = false;
        bool boss2 = false;
        float velocidad = 4;
        int contadorpasos = 0;
        int direccion = 2; //1 = ARRIBA, 2 = ABAJO, 3 = IZQUIERDA, 4 = DERECHA
        int contador = 0;
        void update();
        void updateMovimiento();

};
