#include "Objeto.h"

class Disparo : public Objeto{

    private:
    protected:
    public:
        Disparo();
        int velocidad = 17;
        int poderAtaque = 1;
        int contadorTiempoVida = 0;
        int contadorAnimacion = 0;
        int TiempoVida = 34;
        bool destruir = false;
        bool ProyectilEnemigo = false;
        int direccion = 0; //1= ARRIBA, 2=ABAJO, 3= IZQUIERDA, 4=DERECHA
        void update();
        void updatePosition();

};
