#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Objeto{

    public:
        Objeto();
        sf::RectangleShape rect;
        sf::Sprite sprite;
        sf::Text text;

};

#endif //OBJETO_H
