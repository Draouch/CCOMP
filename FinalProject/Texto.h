#include "Objeto.h"
#include <string>
using namespace std;

class Texto : public Objeto{

    private:
    protected:
    public:
        Texto();
        int velocidad = 5;
        int TiempoVida = 50;
        int contador = 0;
        bool destruir = false;
        string myString = "Hello World";
        string to_string(int x);
        void update();

};
