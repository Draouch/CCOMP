#include "Item.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Item::Item(){

    rect.setSize(Vector2f(32,32));
    rect.setPosition(Vector2f(500,500));
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

}

void Item::update(){

    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x, rect.getPosition().y - 75);

}

void Item::updateMovimiento(){

         sprite.setTextureRect(sf::IntRect(contador*32, 32*0, 32, 32));
         contador++;
         if(contador>=8){

             contador = 0;

         }
}
