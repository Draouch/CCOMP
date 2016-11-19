#include "Objeto.h"
#include <SFML/Graphics.hpp>


class Jugador: public Objeto{

    public:
        Jugador();
        int hp = 1000;
        int rings = 0;
        bool FuegoTriple = false;
        bool AtaqueNova = false;
        bool Erupcion = false;
        int dimension = 65;
        float velocidad = 5;
        int contadorpasos = 0;
        bool IrArriba = true;
        bool IrAbajo = true;
        bool IrIzquierda = true;
        bool IrDerecha = true;
        int poderAtaque = 25;
        int kills = 0;
        int direccion = 2; //1 = ARRIBA, 2 = ABAJO, 3 = IZQUIERDA, 4 = DERECHA
        int score;
        void update();
        sf::Clock clock1;
        sf::Time elapsed1;
        void updateMovimiento();

        Jugador operator+(const Jugador A){

            Jugador B;
            int _kills = A.kills;
            int _rings = A.rings;
            B.score = _kills + _rings;
            return B;
        }

};
