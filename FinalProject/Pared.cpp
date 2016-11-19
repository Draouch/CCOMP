#include "Pared.h"

Pared::Pared(){

    rect.setSize(sf::Vector2f(70,70));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Green);

}

void Pared::update(){

    sprite.setPosition(rect.getPosition());

}

void Pared::updateMovimiento(){

         sprite.setTextureRect(sf::IntRect(contador*72, 72*0, 72, 72));
         contador++;
         if(contador>=5){

             contador = 0;

         }
}
