#include "Objeto.h"

class Item : public Objeto{

    private:
    protected:
    public:
        Item();
        bool isRing = false;
        bool isFuegoTriple = false;
        bool isAtaqueNova = false;
        bool isErupcion = false;
        bool isMasHP = false;
        int valorMasHP = 5000;
        bool isMasPoder = false;
        int valorMasPoder = 2000;
        bool isMasVelocidad = false;
        int valorMasVelocidad = 5;
        bool inTienda = false;
        int valorRing = 5;
        int costo = 0;
        bool destruir = false;
        int contador = 0;
        void update();
        void updateMovimiento();

};
