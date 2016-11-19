#include "Objeto.h"

class Pared : public Objeto{

    private:
    protected:
    public:
        Pared();
        bool destruible = false;
        int hp = 10;
        bool destruir = false;
        void update();
        void updateMovimiento();
        int contador = 0;

};
