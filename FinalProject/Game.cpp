#include "Game.h"

void Menu();

void Game(){

    srand(time(NULL));
    sf::Clock clock, clock2, clock3, clock4, clock5, clock6, clock7, clock8;
    sf::Time elapsed1, elapsed2, elapsed3, elapsed4, elapsed5, elapsed6, elapsed7, elapsed8;
    int contador, contador2, contador3;
    int sizeRoom;
    int PuertaDerecha;
    int PuertaIzquierda;
    int PuertaArriba;
    int PuertaAbajo;
    int roomStartX;
    int roomStartY;
    int tempRandom;
    int RoomSpawnRate = 100;//Incrementar para menor cantidad de enemigos


    //Ventana Principal
    RenderWindow window;
    window.create(VideoMode(1000, 600), "GAME-PROJECT-CCI", Style::Default);
    window.setFramerateLimit(60);

    //Vista del Jugador
    sf::View vista1;
    vista1.setSize(sf::Vector2f(window.getSize().x , window.getSize().y));
    vista1.setCenter(window.getSize().x/2 , window.getSize().y/2);
    window.setView(vista1);

    //Textura del Personaje
    Texture texturaPersonaje;
    if(!texturaPersonaje.loadFromFile("Imgs/Mewtwo.png")){

        exit(0);

    }
    //Textura del 1er Jefe
    Texture texturaJefe1;
    if(!texturaJefe1.loadFromFile("Imgs/Groudon.png")){

        exit(0);

    }
    //Textura del 2do Jefe
    Texture texturaJefe2;
    if(!texturaJefe2.loadFromFile("Imgs/Kyogre.png")){

        exit(0);

    }
    //Textura de los Enemigos
    Texture texturaEnemigos;
    if(!texturaEnemigos.loadFromFile("Imgs/Enemigos.png")){

        exit(0);

    }
    //Textura de los Rings
    Texture texturaRing;
    if(!texturaRing.loadFromFile("Imgs/Rings.png")){

        exit(0);

    }
    //Textura de los Disparos
    Texture texturaDisparo;
    if(!texturaDisparo.loadFromFile("Imgs/Disparo.png")){

        exit(0);

    }
    //Textura de los powerups
    Texture texturaPoderes;
    if(!texturaPoderes.loadFromFile("Imgs/Poderes.png")){

        exit(0);

    }
    //Textura del piso
    Texture texturaPiso;
    if(!texturaPiso.loadFromFile("Imgs/Pasto.png")){

        exit(0);

    }
    Texture texturaCaja;
    if(!texturaCaja.loadFromFile("Imgs/Caja.png")){

        exit(0);

    }
    Texture texturaPared;
    if(!texturaPared.loadFromFile("Imgs/Arbol.png")){

        exit(0);

    }
    //Making text
    sf::Font font;
    if (!font.loadFromFile("Text/font.ttf")){

        exit(0);

    }
    //Texto de los Rings
    sf::Text text, text2, text3, text4, text5;
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setCharacterSize(25);
    text.setPosition(0, 0);

    text2.setFont(font);
    text2.setColor(sf::Color::White);
    text2.setCharacterSize(25);
    text2.setPosition(200, 0);

    text3.setFont(font);
    text3.setColor(sf::Color::White);
    text3.setCharacterSize(25);
    text3.setPosition(400, 0);

    text4.setFont(font);
    text4.setColor(sf::Color::White);
    text4.setCharacterSize(25);
    text4.setPosition(600, 0);

    text5.setFont(font);
    text5.setColor(sf::Color::White);
    text5.setCharacterSize(25);
    text5.setPosition(800, 0);

    //Crear el objeto Jugador
    class Jugador Jugador1;
    Jugador1.sprite.setTexture(texturaPersonaje);
    //Crear el objeto Disparo
    class Disparo Disparo1;
    Disparo1.sprite.setTexture(texturaDisparo);
    //Crear el objeto Enemigo
    class Enemigo Enemigo1;
    Enemigo1.sprite.setTexture(texturaEnemigos);
    Enemigo1.text.setFont(font);
    Enemigo1.text.setColor(sf::Color::White);
    //Crear el objeto Boss
    class Enemigo EnemigoBOSS;
    EnemigoBOSS.sprite.setTexture(texturaJefe1);
    EnemigoBOSS.rect.setSize(Vector2f(100,100));
    EnemigoBOSS.dimensionx = 100;
    EnemigoBOSS.dimensiony = 100;
    EnemigoBOSS.dimensionxStart = 0;
    EnemigoBOSS.dimensionyStart = 0;
    EnemigoBOSS.velocidad = 7;
    EnemigoBOSS.hp = 999999;
    EnemigoBOSS.maxhp = 999999;
    EnemigoBOSS.boss1 = true;
    EnemigoBOSS.boss2 = false;
    EnemigoBOSS.herido = false;
    EnemigoBOSS.text.setFont(font);
    EnemigoBOSS.text.setColor(sf::Color::White);
    EnemigoBOSS.rect.setPosition(10*70 + 10*70 +30*70 +10*70,100);

    class Enemigo EnemigoBOSS2;
    EnemigoBOSS2.sprite.setTexture(texturaJefe2);
    EnemigoBOSS2.rect.setSize(Vector2f(100,100));
    EnemigoBOSS2.dimensionx = 100;
    EnemigoBOSS2.dimensiony = 100;
    EnemigoBOSS2.dimensionxStart = 0;
    EnemigoBOSS2.dimensionyStart = 0;
    EnemigoBOSS2.velocidad = 7;
    EnemigoBOSS2.hp = 10000;
    EnemigoBOSS2.maxhp = 10000;
    EnemigoBOSS2.boss2 = true;
    EnemigoBOSS2.boss1 = false;
    EnemigoBOSS2.herido = false;
    EnemigoBOSS2.text.setFont(font);
    EnemigoBOSS2.text.setColor(sf::Color::White);
    EnemigoBOSS2.rect.setPosition(10*70 + 10*70 +15*70,100);
    //Crear el objeto Texto
    class Texto text1;
    text1.text.setFont(font);
    //Crear el objeto Item
    class Item Item1;
    Item1.text.setFont(font);
    Item1.text.setCharacterSize(20);
    Item1.text.setColor(sf::Color::White);
    //Objeto Pared
    class Pared Pared1;

    //Crear un vector array para almacenar Disparos
    vector<Disparo>::const_iterator iter;
    vector<Disparo>::iterator iter4;
    vector<Disparo> DisparoArray;
    //Crear un vector array para los enemigos y sus sprites
    vector<Enemigo>::const_iterator iter2;
    vector<Enemigo>::iterator iter3;
    vector<Enemigo> EnemigoArray;

    EnemigoArray.push_back(EnemigoBOSS);
    EnemigoArray.push_back(EnemigoBOSS2);

    //Crear un vector array para el Texto
    vector<Texto>::const_iterator iter5;
    vector<Texto>::iterator iter6;
    vector<Texto> TextoArray;

    //Crear un vector array para los rings
    vector<Item>::const_iterator iter7;
    vector<Item>::iterator iter8;
    vector<Item> ItemArray;
    Item1.sprite.setTexture(texturaRing);

    //Crear un vector array para las Paredes
    vector<Pared>::const_iterator iter9;
    vector<Pared>::iterator iter10;
    vector<Pared> ParedArray;


    //Crear un vector array para el Piso
    vector<Pared>::const_iterator iter11;
    vector<Pared> groundArray;
    class Pared ground1;
    ground1.sprite.setTexture(texturaPiso);
    ground1.sprite.setTextureRect(sf::IntRect(64*3, 32*8, 64, 64));
    ground1.sprite.setPosition(Jugador1.rect.getPosition());

//*******************************************************EFECTOS DE SONIDO**********************************************************************************

    //Cargar la musica principal
    sf::Music music;
    if (!music.openFromFile("Music/Music.ogg")) {
        exit(0);
    }

    //Reproducir la musica
    music.play();
    music.setLoop(true);

    //Efectos de sonido
    sf::SoundBuffer bufferDisparo;
    if (!bufferDisparo.loadFromFile("Music/Piu.ogg"))
        exit(0);
    sf::Sound soundDisparo;
    soundDisparo.setBuffer(bufferDisparo);

    sf::SoundBuffer bufferColision;
    if (!bufferColision.loadFromFile("Music/Ditto.ogg"))
        exit(0);
    sf::Sound soundColision;
    soundColision.setBuffer(bufferColision);

    sf::SoundBuffer bufferRing;
    if (!bufferRing.loadFromFile("Music/Rings.ogg"))
         exit(0);
    sf::Sound soundRing;
    soundRing.setBuffer(bufferRing);

    sf::SoundBuffer bufferJugadorHerido;
    if (!bufferJugadorHerido.loadFromFile("Music/Jugador.ogg"))
         exit(0);
    sf::Sound soundJugadorHerido;
    soundJugadorHerido.setBuffer(bufferJugadorHerido);

    sf::SoundBuffer bufferGroudon;
    if (!bufferGroudon.loadFromFile("Music/Groudon.ogg"))
         exit(0);
    sf::Sound soundGroudon;
    soundGroudon.setBuffer(bufferGroudon);

    sf::SoundBuffer bufferKyogre;
    if (!bufferKyogre.loadFromFile("Music/Kyogre.ogg"))
         exit(0);
    sf::Sound soundKyogre;
    soundKyogre.setBuffer(bufferKyogre);

//***********************************************************MAPA********************************************************************************************

        //ROOM 1:{
        sizeRoom = 10;
        PuertaDerecha = 3;
        PuertaIzquierda = 100;
        PuertaArriba = 100;
        PuertaAbajo = 3;
        roomStartX = 0;
        roomStartY = 0;
        Pared1.destruible = false;
        Pared1.sprite.setTexture(texturaPared);
        //Pared de Arriba
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaArriba && contador != PuertaArriba + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;
        }
        //Pared Izquierda
        contador = 0;
        while(contador < sizeRoom){

            if (contador !=PuertaIzquierda && contador !=PuertaIzquierda + 1){

                Pared1.rect.setPosition(roomStartX , 70 * contador + roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared de Abajo
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaAbajo && contador != PuertaAbajo + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY + (70*sizeRoom));
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared Derecha
        contador = 0;
        while(contador < sizeRoom + 1){

            if (contador != PuertaDerecha && contador != PuertaDerecha + 1){

                Pared1.rect.setPosition(roomStartX + (70*sizeRoom) , (70*contador) + roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;

        }
        //Objetos random en el Room
        Pared1.sprite.setTexture(texturaCaja);
        Pared1.sprite.setTextureRect(sf::IntRect(0,0,72,72));

        contador = 0;
        while (contador < (sizeRoom - 1)){

            contador2 = 0;
            while (contador2 < (sizeRoom - 1)){

                tempRandom = generarRandom(RoomSpawnRate);

                //Cajas!
                if (tempRandom == 1){

                    Pared1.destruible = true;
                    Pared1.rect.setFillColor(sf::Color::Yellow);
                    Pared1.rect.setPosition(contador*70 + 70 + roomStartX , contador2*70 + 70 + roomStartY );
                    ParedArray.push_back(Pared1);

                }
                //Enemigos!
                if (tempRandom == 2){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);

                }
                if (tempRandom == 3){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 4){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 5){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 6){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 7){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 8){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 9){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                contador2++;
            }
            contador++;
        }
        //Pasto del piso!
        contador = 0;
        while (contador <= sizeRoom+1){

            contador2 = 0;
            while(contador2 <= sizeRoom+1){

                ground1.sprite.setPosition(60*contador, 60*contador2);
                groundArray.push_back(ground1);
                contador2++;
            }

            contador++;
        }

        //ROOM 2
        sizeRoom = 10;
        PuertaDerecha = 5;
        PuertaIzquierda = 3;
        PuertaArriba = 10;
        PuertaAbajo = 10;
        roomStartX = 10*70;
        roomStartY = 0;
        Pared1.destruible = false;
        Pared1.sprite.setTexture(texturaPared);
        //Pared de Arriba
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaArriba && contador != PuertaArriba + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;
        }
        //Pared Izquierda
        contador = 0;
        while(contador < sizeRoom){

            if (contador !=PuertaIzquierda && contador !=PuertaIzquierda + 1){

                Pared1.rect.setPosition(roomStartX , 70 * contador + roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared de Abajo
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaAbajo && contador != PuertaAbajo + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY + (70*sizeRoom));
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared Derecha
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaDerecha && contador != PuertaDerecha + 1){

                Pared1.rect.setPosition(roomStartX + (70*sizeRoom) , (70*contador) + roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;

        }
        //Objetos random en el Room
        Pared1.sprite.setTexture(texturaCaja);
        Pared1.sprite.setTextureRect(sf::IntRect(0,0,72,72));

        contador = 0;
        while (contador < (sizeRoom - 1)){

            contador2 = 0;
            while (contador2 < (sizeRoom - 1)){

                tempRandom = generarRandom(RoomSpawnRate);

                //Cajas!
                if (tempRandom == 1){

                    Pared1.destruible = true;
                    Pared1.rect.setFillColor(sf::Color::Yellow);
                    Pared1.rect.setPosition(contador*70 + 70 + roomStartX , contador2*70 + 70 + roomStartY );
                    ParedArray.push_back(Pared1);

                }
                //Enemigos!
                if (tempRandom == 2){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);

                }
                if (tempRandom == 3){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 4){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 5){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 6){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 7){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 8){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 9){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                contador2++;
            }
            contador++;
        }
        //Pasto del piso!
        contador = 0;
        while (contador <= sizeRoom+1){

            contador2 = 0;
            while(contador2 <= sizeRoom+1){

                ground1.sprite.setPosition(60*contador + roomStartX, 60*contador2 + roomStartY);
                groundArray.push_back(ground1);
                contador2++;
            }

            contador++;
        }

        //ROOM 3
        sizeRoom = 30;
        PuertaDerecha = 3;
        PuertaIzquierda = 15;
        PuertaArriba = 100;
        PuertaAbajo = 100;
        roomStartX = 10*70 + 10*70;
        roomStartY = -1*10*70;
        Pared1.destruible = false;
        Pared1.sprite.setTexture(texturaPared);
        //Pared de Arriba
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaArriba && contador != PuertaArriba + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;
        }
        //Pared Izquierda
        contador = 0;
        while(contador < sizeRoom){

            if (contador !=PuertaIzquierda && contador !=PuertaIzquierda + 1){

                Pared1.rect.setPosition(roomStartX , 70 * contador + roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared de Abajo
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaAbajo && contador != PuertaAbajo + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY + (70*sizeRoom));
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared Derecha
        contador = 0;
        while(contador < sizeRoom + 1){

            if (contador != PuertaDerecha && contador != PuertaDerecha + 1){

                Pared1.rect.setPosition(roomStartX + (70*sizeRoom) , (70*contador) + roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;

        }
        //Objetos random en el Room
        Pared1.sprite.setTexture(texturaCaja);
        Pared1.sprite.setTextureRect(sf::IntRect(0,0,72,72));

        contador = 0;
        while (contador < (sizeRoom - 1)){

            contador2 = 0;
            while (contador2 < (sizeRoom - 1)){

                tempRandom = generarRandom(RoomSpawnRate);

                //Cajas!
                if (tempRandom == 1){

                    Pared1.destruible = true;
                    Pared1.rect.setFillColor(sf::Color::Yellow);
                    Pared1.rect.setPosition(contador*70 + 70 + roomStartX , contador2*70 + 70 + roomStartY );
                    ParedArray.push_back(Pared1);

                }
                //Enemigos!
                if (tempRandom == 2){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);

                }
                if (tempRandom == 3){

                    Enemigo1.dimensionxStart = 32*0;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 100;
                    Enemigo1.maxhp = 100;
                    Enemigo1.poderAtaque = 10;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 4){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 5){

                    Enemigo1.dimensionxStart = 32*3;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 200;
                    Enemigo1.maxhp = 200;
                    Enemigo1.poderAtaque = 20;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 6){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 7){

                    Enemigo1.dimensionxStart = 32*6;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 300;
                    Enemigo1.maxhp = 300;
                    Enemigo1.poderAtaque = 30;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 8){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*0;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                if (tempRandom == 9){

                    Enemigo1.dimensionxStart = 32*9;
                    Enemigo1.dimensionyStart = 35*4;
                    Enemigo1.hp = 400;
                    Enemigo1.maxhp = 400;
                    Enemigo1.poderAtaque = 50;
                    Enemigo1.rect.setPosition((contador*70) + 70 + roomStartX , (contador2*70) + 70 +roomStartY);
                    EnemigoArray.push_back(Enemigo1);
                }
                contador2++;
            }
            contador++;
        }
        //Pasto del Piso
        contador = 0;
        while (contador <= sizeRoom+5)
        {
            contador2 = 0;
            while(contador2 <= sizeRoom+5)
            {
                ground1.sprite.setPosition(60*contador + roomStartX , 60*contador2 + roomStartY );
                groundArray.push_back(ground1);
                contador2++;
            }

            contador++;
        }

        //ROOM BOSS
        sizeRoom = 20;
        PuertaDerecha = 100;
        PuertaIzquierda = 3;
        PuertaArriba = 100;
        PuertaAbajo = 100;
        roomStartX = 10*70 + 10*70 + 10*70 + 20*70;
        roomStartY = -1*10*70;
        Pared1.destruible = false;
        Pared1.sprite.setTexture(texturaPared);
        //Pared de Arriba
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaArriba && contador != PuertaArriba + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;
        }
        //Pared Izquierda
        contador = 0;
        while(contador < sizeRoom){

            if (contador !=PuertaIzquierda && contador !=PuertaIzquierda + 1){

                Pared1.rect.setPosition(roomStartX , 70 * contador + roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared de Abajo
        contador = 0;
        while(contador < sizeRoom){

            if (contador != PuertaAbajo && contador != PuertaAbajo + 1){

                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY + (70*sizeRoom));
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //Pared Derecha
        contador = 0;
        while(contador < sizeRoom + 1){

            if (contador != PuertaDerecha && contador != PuertaDerecha + 1){

                Pared1.rect.setPosition(roomStartX + (70*sizeRoom) , (70*contador) + roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;

        }
        //Pasto del Piso!
        contador = 0;
        while (contador <= sizeRoom+3){

            contador2 = 0;
            while(contador2 <= sizeRoom+3){

                ground1.sprite.setPosition(60*contador + roomStartX , 60*contador2 + roomStartY );
                groundArray.push_back(ground1);
                contador2++;
            }

            contador++;
        }

        //Tienda!
        sizeRoom = 10;
        PuertaDerecha = 100;
        PuertaIzquierda = 100;
        PuertaArriba = 3;
        PuertaAbajo = 100;
        roomStartX = 0;
        roomStartY = 10 * 70;
        Pared1.destruible = false;
        Pared1.sprite.setTexture(texturaPared);
        //horizontal Pared
        contador = 0;
        while(contador < sizeRoom)
        {
            if (contador != PuertaArriba && contador != PuertaArriba + 1)
            {
                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //vertical Pared
        contador = 0;
        while(contador < sizeRoom)
        {
            if (contador !=PuertaIzquierda && contador !=PuertaIzquierda + 1)
            {
                Pared1.rect.setPosition(roomStartX , 70 * contador + roomStartY);
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //horizontal bottom Pared
        contador = 0;
        while(contador < sizeRoom)
        {
            if (contador != PuertaAbajo && contador != PuertaAbajo + 1)
            {
                Pared1.rect.setPosition(70 * contador + roomStartX , roomStartY + (70*sizeRoom));
                ParedArray.push_back(Pared1);
            }
            contador++;
        }
        //vertical Pared right
        contador = 0;
        while(contador < sizeRoom + 1)
        {
            if (contador != PuertaDerecha && contador != PuertaDerecha + 1)
            {
                Pared1.rect.setPosition(roomStartX + (70*sizeRoom) , (70*contador) + roomStartY);
                ParedArray.push_back(Pared1);

            }
            contador++;

        }
        //Pasto del Piso
        contador = 0;
        while (contador <= sizeRoom+1){

            contador2 = 0;
            while(contador2 <= sizeRoom+1){

                ground1.sprite.setPosition(60*contador + roomStartX, 60*contador2 + roomStartY);
                groundArray.push_back(ground1);
                contador2++;
            }

            contador++;
        }
        //Items
        //TRIPLE FIRE
        Item1.costo = 20;
        Item1.text.setString("FUEGO TRIPLE\nCosto: 20 RINGS\n(0 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = true;
        Item1.isAtaqueNova = false;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
        Item1.rect.setPosition(200, 10*70+7*70);
        ItemArray.push_back(Item1);

        //NOVA ATTACK
        Item1.costo = 20;
        Item1.text.setString("ATAQUE NOVA\nCosto: 20 RINGS\n(0 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = false;
        Item1.isAtaqueNova = true;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
        Item1.rect.setPosition(500, 10*70+7*70);
        ItemArray.push_back(Item1);
        Item1.inTienda = false;

        //Erupcion!
        Item1.costo = 25;
        Item1.text.setString("ERUPCION\nCosto: 25 RINGS\n(100 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = false;
        Item1.isAtaqueNova = false;
        Item1.isErupcion = true;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(32*7, 32*7, 32, 32));
        Item1.rect.setPosition(500, 10*70+7*70+2*70);
        ItemArray.push_back(Item1);
        Item1.inTienda = false;

        //Mas HP
        Item1.costo = 25;
        Item1.text.setString("MAS HP\nCosto: 25 RINGS\n(30 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = false;
        Item1.isAtaqueNova = false;
        Item1.isErupcion = false;
        Item1.isMasHP = true;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(32*4, 32*7, 32, 32));
        Item1.rect.setPosition(200, 10*70+7*70-2*70);
        ItemArray.push_back(Item1);
        Item1.inTienda = false;

        //Mas Poder
        Item1.costo = 25;
        Item1.text.setString("MAS PODER\nCosto: 25 RINGS\n(50 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = false;
        Item1.isAtaqueNova = false;
        Item1.isErupcion = false;
        Item1.isMasHP = false;
        Item1.isMasPoder = true;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(32*7, 32*6, 32, 32));
        Item1.rect.setPosition(200, 10*70+7*70+2*70);
        ItemArray.push_back(Item1);
        Item1.inTienda = false;

        //Mas Velocidad
        Item1.costo = 25;
        Item1.text.setString("MAS VELOCIDAD\nCosto: 25 RINGS\n(50 KILLS)");
        Item1.isRing = false;
        Item1.isFuegoTriple = false;
        Item1.isAtaqueNova = false;
        Item1.isErupcion = false;
        Item1.isMasHP = false;
        Item1.isMasPoder = false;
        Item1.isMasVelocidad = true;
        Item1.inTienda = true;
        Item1.sprite.setTexture(texturaPoderes);
        Item1.sprite.setTextureRect(sf::IntRect(32*5, 32*5, 32, 32));
        Item1.rect.setPosition(500, 10*70+7*70-2*70);
        ItemArray.push_back(Item1);
        Item1.inTienda = false;

    //*************************************************GAME**************************************************************************************

        while(window.isOpen()){
            //Hacer funcionar el boton para salir de la ventana
            Event event;
            while(window.pollEvent(event)){

                if(event.type==Event::Closed){

                    window.close();

                }
            }
            //Crear un boton para salir del juego
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || Jugador1.hp <= 0){

                system("cls");
                window.close();

            }

            text.setPosition(Jugador1.rect.getPosition().x - window.getSize().x/2 , Jugador1.rect.getPosition().y - window.getSize().y/2);
            text2.setPosition(Jugador1.rect.getPosition().x - window.getSize().x/2 + 200, Jugador1.rect.getPosition().y - window.getSize().y/2);
            text3.setPosition(Jugador1.rect.getPosition().x - window.getSize().x/2 + 400, Jugador1.rect.getPosition().y - window.getSize().y/2);
            text4.setPosition(Jugador1.rect.getPosition().x - window.getSize().x/2 + 600, Jugador1.rect.getPosition().y - window.getSize().y/2);
            text5.setPosition(Jugador1.rect.getPosition().x - window.getSize().x/2 + 800, Jugador1.rect.getPosition().y - window.getSize().y/2);




            //update the Jugador's position, as well as the rect's.
            Jugador1.update();
            if(elapsed5.asSeconds() >= 0.1){

                clock5.restart();
                Jugador1.updateMovimiento();

            }

            // Spawnear mas Enemigos
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){

                Enemigo1.rect.setPosition(generarRandom(window.getSize().x) , generarRandom(window.getSize().y));
                EnemigoArray.push_back(Enemigo1);

            }

             //Disparar al presionar Espacio
            if(elapsed1.asSeconds() >= 0.2){

                clock.restart();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    soundDisparo.play();

                if (Jugador1.FuegoTriple == true){

                    if (Jugador1.direccion == 1){ // ARRIBA

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 25);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                    }
                    if (Jugador1.direccion == 2){ //ABAJO

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 25);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);
                    }
                    if (Jugador1.direccion == 3){ //IZQUIERDA

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 25 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);
                    }
                    if (Jugador1.direccion == 4){ //DERECHA

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 25 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);
                    }
                }
                    else if (Jugador1.AtaqueNova == true){

                            Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                      Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                            Disparo1.direccion = 1;
                            DisparoArray.push_back(Disparo1);

                            Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                      Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                            Disparo1.direccion = 2;
                            DisparoArray.push_back(Disparo1);

                            Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                      Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                            Disparo1.direccion = 3;
                            DisparoArray.push_back(Disparo1);

                            Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                      Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                            Disparo1.direccion = 4;
                            DisparoArray.push_back(Disparo1);
                    }
                    else if (Jugador1.Erupcion == true){

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 25);
                        Disparo1.direccion = 1;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                        Disparo1.direccion = 1;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                        Disparo1.direccion = 1;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 25);
                        Disparo1.direccion = 2;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = 2;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = 2;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 25 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = 3;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                     Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                        Disparo1.direccion = 3;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                        Disparo1.direccion = 3;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 25 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = 4;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                        Disparo1.direccion = 4;
                        DisparoArray.push_back(Disparo1);

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                        Disparo1.direccion = 4;
                        DisparoArray.push_back(Disparo1);


                    }
                    else if(Jugador1.FuegoTriple == false && Jugador1.AtaqueNova == false && Jugador1.Erupcion == false){ //ATAQUE NORMAL

                        Disparo1.rect.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                  Jugador1.rect.getPosition().y + Jugador1.rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                        Disparo1.direccion = Jugador1.direccion;
                        DisparoArray.push_back(Disparo1);
                    }
                }
            }

            //Limpiar la ventana
           window.clear();

           //Clock
           elapsed1 = clock.getElapsedTime();
           elapsed2 = clock2.getElapsedTime();
           elapsed3 = clock3.getElapsedTime();
           elapsed4 = clock4.getElapsedTime();
           elapsed5 = clock5.getElapsedTime();
           elapsed6 = clock6.getElapsedTime();
           elapsed7 = clock7.getElapsedTime();
           elapsed8 = clock8.getElapsedTime();

            //Piso
            contador = 0;
            for(iter11 = groundArray.begin(); iter11 != groundArray.end(); iter11++){

                window.draw(groundArray[contador].sprite);
                contador++;

            }

            //Arboles
            contador = 0;
            for(iter9 = ParedArray.begin(); iter9 != ParedArray.end(); iter9++){

                window.draw(ParedArray[contador].sprite);
                ParedArray[contador].update();
                contador++;
            }

            //Items
            contador = 0;
            for(iter7 = ItemArray.begin(); iter7 != ItemArray.end(); iter7++){

                ItemArray[contador].update();
                if(ItemArray[contador].inTienda == true){

                    window.draw(ItemArray[contador].text);

                }


               if(elapsed3.asSeconds() >= 0){
                 clock3.restart();
                 if(ItemArray[contador].isRing == true){

                     ItemArray[contador].updateMovimiento();

                 }
             }
            window.draw(ItemArray[contador].sprite);
            contador++;
            }

            //Proyectiles
            contador=0;
            for(iter=DisparoArray.begin(); iter!=DisparoArray.end(); iter++){

                DisparoArray[contador].updatePosition();
                if(elapsed4.asSeconds() >= 0.1){

                    clock4.restart();
                    DisparoArray[contador].update();
                }
                window.draw(DisparoArray[contador].sprite);
                contador++;
            }
            //Enemigos!
            contador=0;
            for(iter2=EnemigoArray.begin(); iter2!=EnemigoArray.end(); iter2++){
                EnemigoArray[contador].update();
                EnemigoArray[contador].text.setString(text1.to_string(EnemigoArray[contador].hp) + "/" + text1.to_string(EnemigoArray[contador].maxhp));
                EnemigoArray[contador].text.setPosition(EnemigoArray[contador].rect.getPosition().x , EnemigoArray[contador].rect.getPosition().y - EnemigoArray[contador].rect.getSize().y);
                if (elapsed6.asSeconds() >= 0){

                    clock6.restart();
                    EnemigoArray[contador].updateMovimiento();
                }
                window.draw(EnemigoArray[contador].sprite);
                window.draw(EnemigoArray[contador].text);
                contador++;
            }

            //Colision - Jugador
            contador = 0;
            for (iter9 = ParedArray.begin(); iter9 != ParedArray.end(); iter9++){

                if (Jugador1.rect.getGlobalBounds().intersects(ParedArray[contador].rect.getGlobalBounds())){

                     if (Jugador1.direccion == 1){ //ARRIBA

                        Jugador1.IrArriba = false;
                        Jugador1.rect.move(0,1);
                     }
                     if (Jugador1.direccion == 2){ //ABAJO

                        Jugador1.IrAbajo = false;
                        Jugador1.rect.move(0,-1);
                     }
                     if (Jugador1.direccion == 3){ //IZQUIERDA

                        Jugador1.IrIzquierda = false;
                        Jugador1.rect.move(1,0);
                     }
                     if (Jugador1.direccion == 4){ //DERECHA

                        Jugador1.IrDerecha = false;
                        Jugador1.rect.move(-1,0);
                    }

                }
                contador++;
            }

            //Colision - Enemigos
            contador = 0;
            for(iter2=EnemigoArray.begin(); iter2!=EnemigoArray.end(); iter2++){
                contador2 = 0;
                for (iter9 = ParedArray.begin(); iter9 != ParedArray.end(); iter9++){
                    if (EnemigoArray[contador].rect.getGlobalBounds().intersects(ParedArray[contador2].rect.getGlobalBounds())){
                        if (EnemigoArray[contador].direccion == 1){ //ARRIBA

                            EnemigoArray[contador].IrArriba = false;
                            EnemigoArray[contador].rect.move(0,1);
                        }
                        else if (EnemigoArray[contador].direccion == 2){ //ABAJO

                            EnemigoArray[contador].IrAbajo = false;
                            EnemigoArray[contador].rect.move(0,-1);
                        }
                        else if (EnemigoArray[contador].direccion == 3){ //IZQUIERDA

                            EnemigoArray[contador].IrIzquierda = false;
                            EnemigoArray[contador].rect.move(1,0);
                        }
                        else if (EnemigoArray[contador].direccion == 4){ //DERECHA

                            EnemigoArray[contador].IrDerecha = false;
                            EnemigoArray[contador].rect.move(-1,0);
                        }
                    }
                    contador2++;
                }

              contador++;
            }

            //Colision - Proyectiles y Cajas
            contador = 0;
            for(iter=DisparoArray.begin(); iter!=DisparoArray.end(); iter++){
                contador2 = 0;
                for (iter9 = ParedArray.begin(); iter9 != ParedArray.end(); iter9++){

                    if (DisparoArray[contador].rect.getGlobalBounds().intersects(ParedArray[contador2].rect.getGlobalBounds())){

                        DisparoArray[contador].destruir = true;
                        if (ParedArray[contador2].destruible == true){

                            ParedArray[contador2].hp -= Jugador1.poderAtaque;
                            if (ParedArray[contador2].hp <= 0){

                                ParedArray[contador2].destruir = true;
                            }
                        }
                    }
                    contador2++;
                }
                contador++;
            }

            //Colision - Jugador y Enemigo
            if (elapsed2.asSeconds() >= 1){
                clock2.restart();
                contador = 0;
                for(iter2=EnemigoArray.begin(); iter2!=EnemigoArray.end(); iter2++){

                if(Jugador1.rect.getGlobalBounds().intersects(EnemigoArray[contador].rect.getGlobalBounds())){

                    soundJugadorHerido.play();
                    Jugador1.hp = Jugador1.hp - EnemigoArray[contador].poderAtaque;
                    //Mostrar Texto
                    text1.text.setString("-"+text1.to_string(EnemigoArray[contador].poderAtaque));
                    text1.text.setPosition(Jugador1.rect.getPosition().x - Jugador1.rect.getSize().x/2 ,
                                           Jugador1.rect.getPosition().y - Jugador1.rect.getSize().y/2);
                    TextoArray.push_back(text1);
                    Jugador1.FuegoTriple = false;
                    Jugador1.AtaqueNova = false;
                    cout<<"Tu vida es..."<<Jugador1.hp<<endl;
                }
                contador++;
                }
            }

            //Colision - Enemigo y Proyectil
            contador = 0;
            for(iter=DisparoArray.begin(); iter!=DisparoArray.end(); iter++){

                contador2 = 0;
                for(iter2=EnemigoArray.begin(); iter2!=EnemigoArray.end(); iter2++){

                    if(DisparoArray[contador].rect.getGlobalBounds().intersects(EnemigoArray[contador2].rect.getGlobalBounds())){

                        if (DisparoArray[contador].ProyectilEnemigo == false){

                            if (EnemigoArray[contador2].boss1 == false){

                                soundColision.play();
                            }

                            cout<<"Heriste a alguien!"<<endl;
                            DisparoArray[contador].destruir = true;
                            EnemigoArray[contador2].herido = true;
                            //Mostrar Texto
                            text1.text.setString("-" + text1.to_string(Jugador1.poderAtaque));
                            text1.text.setPosition(EnemigoArray[contador2].rect.getPosition().x - EnemigoArray[contador2].rect.getSize().x/2 ,
                                                   EnemigoArray[contador2].rect.getPosition().y - EnemigoArray[contador2].rect.getSize().y/2);
                            TextoArray.push_back(text1);
                            EnemigoArray[contador2].hp = EnemigoArray[contador2].hp - Jugador1.poderAtaque;
                            if(EnemigoArray[contador2].hp <= 0){

                                EnemigoArray[contador2].vivo = false;
                            }
                        }
                    }
                    contador2++;
                }
                contador++;
            }


            //Colision - Jugador y Proyectil
            contador = 0;
            for (iter = DisparoArray.begin(); iter != DisparoArray.end(); iter++){

                if (DisparoArray[contador].ProyectilEnemigo == true){

                    if (DisparoArray[contador].rect.getGlobalBounds().intersects(Jugador1.rect.getGlobalBounds())){

                        Jugador1.hp = Jugador1.hp - EnemigoArray[contador].poderAtaque;
                        //Mostrar Texto
                        text1.text.setString("-"+text1.to_string(EnemigoArray[contador].poderAtaque));
                        text1.text.setPosition(Jugador1.rect.getPosition().x + Jugador1.rect.getSize().x/2, Jugador1.rect.getPosition().y - Jugador1.rect.getSize().y/2);
                        TextoArray.push_back(text1);

                        DisparoArray[contador].destruir = true;
                    }
                }

                contador++;
            }

            //Colison - Jugador e Items
            contador = 0;
            for(iter7 = ItemArray.begin(); iter7 != ItemArray.end(); iter7++){

                if(ItemArray[contador].rect.getGlobalBounds().intersects(Jugador1.rect.getGlobalBounds())){

                        if(ItemArray[contador].inTienda == true){

                           if (Jugador1.rings >= ItemArray[contador].costo){

                               soundRing.play();

                                if(ItemArray[contador].isFuegoTriple == true){

                                    Jugador1.FuegoTriple = true;
                                    Jugador1.AtaqueNova = false;
                                    Jugador1.Erupcion = false;
                                    Jugador1.rings -= ItemArray[contador].costo;
                                    ItemArray[contador].destruir = true;
                                }
                                if(ItemArray[contador].isAtaqueNova == true){

                                    Jugador1.FuegoTriple = false;
                                    Jugador1.AtaqueNova = true;
                                    Jugador1.Erupcion = false;
                                    Jugador1.rings -= ItemArray[contador].costo;
                                    ItemArray[contador].destruir = true;
                                }
                                if(Jugador1.kills>=100){

                                    if(ItemArray[contador].isErupcion == true){

                                        Jugador1.FuegoTriple = false;
                                        Jugador1.AtaqueNova = false;
                                        Jugador1.Erupcion = true;
                                        Jugador1.rings -= ItemArray[contador].costo;
                                        ItemArray[contador].destruir = true;
                                    }
                                }
                                if(Jugador1.kills>=30){

                                    if(ItemArray[contador].isMasHP == true){

                                        Jugador1.hp += ItemArray[contador].valorMasHP;
                                        Jugador1.rings -= ItemArray[contador].costo;
                                        ItemArray[contador].destruir = true;
                                    }
                                }
                                if(Jugador1.kills>=50){

                                    if(ItemArray[contador].isMasPoder == true){

                                        Jugador1.poderAtaque += ItemArray[contador].valorMasPoder;
                                        Jugador1.rings -= ItemArray[contador].costo;
                                        ItemArray[contador].destruir = true;
                                    }
                                }
                                if(Jugador1.kills>=50){

                                    if(ItemArray[contador].isMasVelocidad == true){

                                        Jugador1.velocidad += ItemArray[contador].valorMasVelocidad;
                                        Jugador1.rings -= ItemArray[contador].costo;
                                        ItemArray[contador].destruir = true;
                                    }
                                }
                           }
                        }

                        if(ItemArray[contador].inTienda == false){

                            soundRing.play();
                            if(ItemArray[contador].isRing == true){

                                Jugador1.rings += ItemArray[contador].valorRing;
                                Jugador1.hp += 4;
                            }
                            if(ItemArray[contador].isFuegoTriple == true){

                                Jugador1.FuegoTriple = true;
                                Jugador1.AtaqueNova = false;
                            }
                            if(ItemArray[contador].isAtaqueNova == true){

                                Jugador1.FuegoTriple = false;
                                Jugador1.AtaqueNova = true;
                            }
                            ItemArray[contador].destruir = true;
                    }
                }
                contador++;
            }

            //IA Enemiga
            contador = 0;
            for (iter2 = EnemigoArray.begin(); iter2 != EnemigoArray.end(); iter2++){

                if (EnemigoArray[contador].herido == true){

                    if (elapsed7.asSeconds() >= 1){

                        clock7.restart();
                        int tempRand = generarRandom(3);
                        if (tempRand == 1){ //Enemigo dispara y busca al Jugador

                            if (EnemigoArray[contador].boss1 == true){

                                //Dispara hacia ARRIBA
                                soundGroudon.play();
                                Disparo1.ProyectilEnemigo = true;
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                          EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 25);
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                          EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                              EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia ABAJO
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 25);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 + 50 , EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 -
                                Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 - 50 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia la IZQUIERDA
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 - 25 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2, EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia DERECHA
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 + 25 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);
                                Disparo1.ProyectilEnemigo = false;
                            }
                            else if (EnemigoArray[contador].boss2 == true){

                                //Dispara hacia ARRIBA
                                soundKyogre.play();
                                Disparo1.ProyectilEnemigo = true;
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 ,
                                                          EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 25);
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 + 50 ,
                                                          EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2 - 50 ,
                                              EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 );
                                Disparo1.direccion = 1;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia ABAJO
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 25);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 + 50 , EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 -
                                Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 - 50 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 2;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia la IZQUIERDA
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 - 25 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2, EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                                Disparo1.direccion = 3;
                                DisparoArray.push_back(Disparo1);

                                //Dispara hacia DERECHA
                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 + 25 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 + 50);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);

                                Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 -
                                Disparo1.rect.getSize().x/2 , EnemigoArray[contador].rect.getPosition().y +
                                EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2 - 50);
                                Disparo1.direccion = 4;
                                DisparoArray.push_back(Disparo1);
                                Disparo1.ProyectilEnemigo = false;
                            }

                            if (EnemigoArray[contador].boss1 == false && EnemigoArray[contador].boss2 == false){
                                //Jugador a la Derecha
                                if ((Jugador1.rect.getPosition().x < EnemigoArray[contador].rect.getPosition().x) && (abs(Jugador1.rect.getPosition().y - EnemigoArray[contador].rect.getPosition().y) <= 40)){

                                     soundDisparo.play();
                                     Disparo1.ProyectilEnemigo = true;
                                     Disparo1.direccion = 3;
                                     Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2,EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                     DisparoArray.push_back(Disparo1);
                                     Disparo1.ProyectilEnemigo = false;
                                     EnemigoArray[contador].direccion = 3;

                                }
                                //Jugador a la Izquierda
                                if ((Jugador1.rect.getPosition().x > EnemigoArray[contador].rect.getPosition().x) && (abs(Jugador1.rect.getPosition().y - EnemigoArray[contador].rect.getPosition().y) <= 40)){

                                    soundDisparo.play();
                                    Disparo1.ProyectilEnemigo = true;
                                    Disparo1.direccion = 4;
                                    Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2,EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                    DisparoArray.push_back(Disparo1);
                                    Disparo1.ProyectilEnemigo = false;
                                    EnemigoArray[contador].direccion = 4;

                                }

                                //Jugador hacia Arriba
                                if ((Jugador1.rect.getPosition().y < EnemigoArray[contador].rect.getPosition().y) && (abs(Jugador1.rect.getPosition().x - EnemigoArray[contador].rect.getPosition().x) <= 40)){

                                    soundDisparo.play();
                                    Disparo1.ProyectilEnemigo = true;
                                    Disparo1.direccion = 1;
                                    Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2,EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                    DisparoArray.push_back(Disparo1);
                                    Disparo1.ProyectilEnemigo = false;
                                    EnemigoArray[contador].direccion = 1;
                                }

                                //Jugador hacia Abajo
                                if ((Jugador1.rect.getPosition().y > EnemigoArray[contador].rect.getPosition().y) && (abs(Jugador1.rect.getPosition().x - EnemigoArray[contador].rect.getPosition().x) <= 40)){

                                    soundDisparo.play();
                                    Disparo1.ProyectilEnemigo = true;
                                    Disparo1.direccion = 2;
                                    Disparo1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + EnemigoArray[contador].rect.getSize().x/2 - Disparo1.rect.getSize().x/2,EnemigoArray[contador].rect.getPosition().y + EnemigoArray[contador].rect.getSize().y/2 - Disparo1.rect.getSize().y/2);
                                    DisparoArray.push_back(Disparo1);
                                    Disparo1.ProyectilEnemigo = false;
                                    EnemigoArray[contador].direccion = 2;

                                }
                            }
                        }
                        else if (tempRand == 2){ //Enemigo busca Jugador
                            if (Jugador1.rect.getPosition().y < EnemigoArray[contador].rect.getPosition().y){

                                EnemigoArray[contador].direccion = 1;
                            }
                            else if (Jugador1.rect.getPosition().y > EnemigoArray[contador].rect.getPosition().y){

                                EnemigoArray[contador].direccion = 2;
                            }
                            else if (Jugador1.rect.getPosition().x < EnemigoArray[contador].rect.getPosition().x){

                                EnemigoArray[contador].direccion = 3;
                            }
                            else if (Jugador1.rect.getPosition().x > EnemigoArray[contador].rect.getPosition().x){

                                EnemigoArray[contador].direccion = 4;
                            }
                        }
                        else{ //Enemigo sigue buscando Jugador

                            if (Jugador1.rect.getPosition().x < EnemigoArray[contador].rect.getPosition().x){

                                EnemigoArray[contador].direccion = 3;
                            }
                            else if (Jugador1.rect.getPosition().x > EnemigoArray[contador].rect.getPosition().x){

                                EnemigoArray[contador].direccion = 4;
                            }
                            else if (Jugador1.rect.getPosition().y < EnemigoArray[contador].rect.getPosition().y){

                                EnemigoArray[contador].direccion = 1;
                            }
                            else if (Jugador1.rect.getPosition().y > EnemigoArray[contador].rect.getPosition().y){

                                EnemigoArray[contador].direccion = 2;
                            }
                        }

                        }
                    }
                    contador++;
                }

            //Eliminar Enemigos
            contador = 0;
            for(iter3=EnemigoArray.begin(); iter3!=EnemigoArray.end(); iter3++){

                if(EnemigoArray[contador].vivo == false){
                    cout<<"ENEMIGO ELIMINADO"<<endl;
                    Jugador1.kills += 1;

                    if (EnemigoArray[contador].boss1 == false && EnemigoArray[contador].boss2 == false){
                        //Soltar Ring
                        if (generarRandom(4) == 1){

                            Item1.isRing = true;
                            Item1.isFuegoTriple = false;
                            Item1.isAtaqueNova = false;
                            Item1.sprite.setTexture(texturaRing);
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition());
                            ItemArray.push_back(Item1);
                        }
                        //Soltar Fuego Triple
                        if (generarRandom(8) == 1){

                            Item1.isRing = false;
                            Item1.isFuegoTriple = true;
                            Item1.isAtaqueNova = false;
                            Item1.sprite.setTexture(texturaPoderes);
                            Item1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition());
                            ItemArray.push_back(Item1);
                        }
                        //Soltar Ataque Nova
                        if (generarRandom(30) == 1){
                            Item1.isRing = false;
                            Item1.isFuegoTriple = false;
                            Item1.isAtaqueNova = true;
                            Item1.sprite.setTexture(texturaPoderes);
                            Item1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition());
                            ItemArray.push_back(Item1);
                        }
                    }
                    else{
                        Item1.isRing = true;
                        Item1.sprite.setTexture(texturaRing);
                        Item1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

                        contador3 = 0;
                        while (contador3 <= 10){

                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x - generarRandom(30),EnemigoArray[contador].rect.getPosition().y - generarRandom(30));
                            ItemArray.push_back(Item1);
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + generarRandom(30),EnemigoArray[contador].rect.getPosition().y + generarRandom(30));
                            ItemArray.push_back(Item1);
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x - generarRandom(30),EnemigoArray[contador].rect.getPosition().y + generarRandom(30));
                            ItemArray.push_back(Item1);
                            Item1.rect.setPosition(EnemigoArray[contador].rect.getPosition().x + generarRandom(30),EnemigoArray[contador].rect.getPosition().y - generarRandom(30));
                            ItemArray.push_back(Item1);

                            contador3++;
                        }
                    }


                    EnemigoArray.erase(iter3);
                    break;
                }
                contador++;
            }
            //Eliminar Proyectiles
            contador = 0;
            for(iter4=DisparoArray.begin(); iter4 != DisparoArray.end(); iter4++){
                if(DisparoArray[contador].destruir == true){
                    cout<<"Piu piu piu!"<<endl;
                    DisparoArray.erase(iter4);
                    break;
                }
                contador++;
            }
            //Eliminar Texto
            contador = 0;
            for(iter6=TextoArray.begin(); iter6 != TextoArray.end(); iter6++){

                if (TextoArray[contador].destruir == true){
                    cout<<"Texto y mas texto"<<endl;
                    TextoArray.erase(iter6);
                    break;
                }
                contador++;
            }
            //Eliminar Items
            contador = 0;
            for(iter8=ItemArray.begin(); iter8 != ItemArray.end(); iter8++){

                if (ItemArray[contador].destruir == true){

                    cout<<"Mas Rings!"<<endl;
                    ItemArray.erase(iter8);
                    break;
                }
                contador++;
            }
            //Soltar Items
            contador = 0;
            for (iter10 = ParedArray.begin(); iter10 != ParedArray.end(); iter10++){

                if (ParedArray[contador].destruir == true){

                    cout<<"Rings!"<<endl;
                    //Soltar Ring
                    if (generarRandom(4) == 1){

                        Item1.isRing = true;
                        Item1.isFuegoTriple = false;
                        Item1.isAtaqueNova = false;
                        Item1.sprite.setTexture(texturaRing);
                        Item1.rect.setPosition(ParedArray[contador].rect.getPosition());
                        ItemArray.push_back(Item1);

                    }
                    //Soltar Fuego Triple
                    if (generarRandom(8) == 1){

                        Item1.isRing = false;
                        Item1.isFuegoTriple = true;
                        Item1.isAtaqueNova = false;
                        Item1.sprite.setTexture(texturaPoderes);
                        Item1.sprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
                        Item1.rect.setPosition(ParedArray[contador].rect.getPosition());
                        ItemArray.push_back(Item1);

                    }
                    //Soltar Ataque Nova
                    if (generarRandom(30) == 1){

                        Item1.isRing = false;
                        Item1.isFuegoTriple = false;
                        Item1.isAtaqueNova = true;
                        Item1.sprite.setTexture(texturaPoderes);
                        Item1.sprite.setTextureRect(sf::IntRect(32*5, 32*7, 32, 32));
                        Item1.rect.setPosition(ParedArray[contador].rect.getPosition());
                        ItemArray.push_back(Item1);

                    }

                    ParedArray.erase(iter10);
                    break;
                }
                contador++;
            }

            //Dibujar al Jugador
            window.draw(Jugador1.sprite);
            //Ajustar la vista del jugador
            window.setView(vista1);
            vista1.setCenter(Jugador1.rect.getPosition());

            //Mostar texto de danio
            contador = 0;
            for(iter5 = TextoArray.begin(); iter5 != TextoArray.end(); iter5++){

                TextoArray[contador].update();
                window.draw(TextoArray[contador].text);
                contador++;

            }

            //Mostrar Rings
            text.setString("RINGS: " + text1.to_string(Jugador1.rings));
            window.draw(text);
            //Mostrar HP
            text2.setString("HP: " + text1.to_string(Jugador1.hp));
            window.draw(text2);
            //Mostrar Kills
            text3.setString("KILLS: " + text1.to_string(Jugador1.kills));
            window.draw(text3);
            //Motrar Poder
            text4.setString("PODER: " + text1.to_string(Jugador1.poderAtaque));
            window.draw(text4);
            //Mostrar Score
            text5.setString("SCORE: " + text1.to_string(4*(Jugador1.rings + Jugador1.kills)));
            window.draw(text5);

            window.display();

        }

        system("cls");
        GameOver();

}
