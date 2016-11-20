#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Jugador.h"
#include "Arma.h"
#include "Funciones.h"
#include "Game.h"

jugador chooseClase();
arma chooseArma();
void GameOver();
void PressAnyButton();

void Inicializar(){

    char son;
    int newOro;
    int newVida;
    int newFuerza;
    int newAgilidad;
    int experiencia = 0;
    system("cls");

    jugador tuPersonaje = chooseClase();
    PressAnyButton();
    arma tuArma = chooseArma();
    PressAnyButton();

    cout << "Y antes de comenzar en tu aventura, cual es tu nombre?\n\n>> ";
    string nombre;
    cin >> nombre;
    system("cls");


    while(tuPersonaje.getVida()>0){

        if(experiencia > 100 && tuPersonaje.getNivel() < 2){

            cout << "Subiste de nivel! Ahora eres nivel 2! Bien hecho, sigue asi!" << endl;
            tuPersonaje.addNivel();
            PressAnyButton();

        }
        if(experiencia > 700 && tuPersonaje.getNivel() < 3){

            cout << "Subiste de nivel! Ahora eres nivel 3! Bien hecho, sigue asi!" << endl;
            tuPersonaje.addNivel();
            PressAnyButton();

        }
        if(experiencia > 2000 && tuPersonaje.getNivel() < 4){

            cout << "Felicitaciones!!! Alcanzaste el nivel 6!!! Eres el mejor!!!" << endl;
            tuPersonaje.addNivel();
            PressAnyButton();

        }

        cout << "A que lugar quisieras ir?\n\n[1]La Armeria\n\n[2]El Coliseo\n\n[3]Tienda de Pociones\n\n[4]Tus Stats\n\n[5]Salir\n\n>> ";
        int menuSeleccion;
        srand(time(0));
        cin >> menuSeleccion;
        system("cls");
        switch(menuSeleccion){

            case 1:{

                system("cls");
                cout << "Bienvenido a la Armeria\n";
                cout << "Actualmente tienes " << tuPersonaje.getOro() << " de oro.\n\n";
                cout << "Que quisieras hacer?\n\n[1]Mejorar Ataque Principal - 50g\n\n[2]Mejorar Ataque Secundario - 25g\n\n[3]Salir\n\n>> ";
                int elecArmeria;
                cin >> elecArmeria;
                system("cls");
                switch(elecArmeria){

                    case 1:{

                        if(tuPersonaje.getOro()>49){

                            tuArma.mejorarAtaquePrincipal();
                            newOro = tuPersonaje.getOro()-50;
                            tuPersonaje.setOro(newOro);
                            cout << "Ataque Principal Potenciado!";
                            PressAnyButton();
                            break;

                        }
                        else{
                            cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                            PressAnyButton();
                            break;

                        }
                    }
                    case 2:{

                        if(tuArma.getAtaqueSecundario()>0){

                            if(tuPersonaje.getOro()>24){

                                tuArma.mejorarAtaqueSecundario();
                                newOro = tuPersonaje.getOro()-25;
                                tuPersonaje.setOro(newOro);
                                cout << "Ataque Secundario Mejorado!";
                                PressAnyButton();
                                break;

                            }
                            else{

                                cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                                PressAnyButton();
                                break;

                            }
                        }
                        else{

                            cout << "Tu Arma no posee Ataque Secundario.";
                            PressAnyButton();
                            break;

                        }
                    }
                    case 3:{

                        break;

                    }
                    default:{

                        cout << "Ingresa una opcion valida.\n\n";
                        PressAnyButton();
                    }
                }
                break;

            }
            case 2:{

                int elecColiseo;
                if(tuPersonaje.getNivel()<4){

                    cout << "BIENVENIDO AL COLISEO\nElige tu camino al campo de batalla:\n\n[1] Camino Rocoso\n\n[2] Camino Soleado\n\n[3] Camino Nebuloso\n\n[4] Camino Oscuro\n\n>> ";
                    cin >> elecColiseo;

                }
                if(tuPersonaje.getNivel()==4){

                    cout <<"Hay una nota en la entrada del Coliseo. \"" << nombre << "...\nVeo que has superado todas las pruebas y alcanzado un gran poder." <<
                    " Te estare esperando en el patio central del\nCastillo. Estare ansioso de luchar contra ti.\"\n\n" <<
                    "Quieres ir al Castillo?\n[S]i o [N]o?\n\n>> ";
                    cin >> son;

                }

                int elecCombate;
                int danio;
                int actualVida;
                system("cls");

                if(tuPersonaje.getNivel() == 1)
                switch(elecColiseo){

                    case 1:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 50, 10, 10, 0, 40, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                            case 1:{

                                if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                    danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                    cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                    actualVida=Demonio.getVida()-danio;
                                    Demonio.setVida(actualVida);

                                    if(Demonio.getVida() <= 0){

                                        cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                        <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                        newOro = tuPersonaje.getOro()+Demonio.getOro();
                                        tuPersonaje.setOro(newOro);
                                        experiencia = experiencia + Demonio.getFuerza();
                                        Demonio.setVida(0);

                                    }
                                }
                                else{

                                    cout << "El Demonio ha esquivado tu ataque!\n\n";

                                }

                                if(Demonio.getVida() > 0){

                                    if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                        danio=Demonio.getFuerza()*0.90;
                                        danio=danio*tuPersonaje.getArmadura();
                                        cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                        actualVida=tuPersonaje.getVida()-danio;
                                        tuPersonaje.setVida(actualVida);

                                    }
                                    else{

                                        cout << "Has esquivado el ataque del Demonio!";

                                    }
                                }
                                PressAnyButton();
                                break;

                            }
                            case 2:{

                                if((rand()%3) == 1){

                                    cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                    PressAnyButton();
                                    Demonio.setVida(0);
                                    break;

                                }
                                else{

                                    cout << "Que equivocacion... El Demonio te asesino!";
                                    Sleep(3000);
                                    system("cls");
                                    tuPersonaje.setVida(0);
                                    Demonio.setVida(0);
                                    break;

                                }
                                break;

                            }
                            default:{

                                cout << "Ingresa una opcion valida.\n\n";
                                PressAnyButton();

                            }

                        }
                        if(tuPersonaje.getVida()<=0){

                            cout << "Has sido asesinado!";
                            Sleep(1700);
                            system("cls");
                            break;

                        }
                    }
                    break;
                }
                    case 2:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 70, 15, 15, 0, 50, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 3:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 90, 20, 20, 0, 60, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 4:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 111, 30, 30, 0, 70, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    default:{

                        cout << "Ingresa una opcion valida.";
                        PressAnyButton();
                    }
                }
                if(tuPersonaje.getNivel() == 2)
                switch(elecColiseo){

                    case 1:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 70, 50, 40, 0, 50, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 2:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 90, 60, 50, 0, 60, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 3:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 100, 70, 70, 0, 70, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 4:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 150, 90, 80, 0, 80, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    default:{

                        cout << "Ingresa una opcion valida.";
                        PressAnyButton();
                    }
                }
                if(tuPersonaje.getNivel() == 3)
                switch(elecColiseo){

                    case 1:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 100, 100, 100, 0, 60, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 2:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 120, 110, 100, 0, 70, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 3:{

                        cout << "Un Demonio ha entrado al Coliseo.\n";
                        jugador Demonio("Demonio", 140, 120, 110, 0, 80, 0);
                        while(Demonio.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%17))>(Demonio.getAgilidad()+(rand()%17))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Demonio.getVida()-danio;
                                        Demonio.setVida(actualVida);

                                        if(Demonio.getVida() <= 0){

                                            cout << "Has asesinado al Demonio y recibes " << Demonio.getOro()
                                            <<" de oro y " << Demonio.getFuerza() << " de experiencia!";
                                            newOro = tuPersonaje.getOro()+Demonio.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia + Demonio.getFuerza();
                                            Demonio.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "El Demonio ha esquivado tu ataque!\n\n";

                                    }

                                    if(Demonio.getVida() > 0){

                                        if((Demonio.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Demonio.getFuerza()*0.90;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El Demonio te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque del Demonio!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;

                                }
                                case 2:{

                                    if((rand()%3) == 1){

                                        cout << "El Demonio te perdono la vida y se fue del Coliseo.\n";
                                        PressAnyButton();
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que equivocacion... El Demonio te asesino!";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Demonio.setVida(0);
                                        break;

                                    }
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }

                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    case 4:{

                        cout << "Un "<<tuPersonaje.getClase() << " ha entrado al Coliseo.\n";
                        Sleep(2000);
                        system("cls");
                        cout << "Mientras el " << tuPersonaje.getClase() << " se va acercando a ti, te das cuenta que no es un oponente cualquiera...\n";
                        Sleep(2500);
                        cout << "Eres tu, " << nombre << "!";
                        PressAnyButton();
                        cout << "Como puede ser esto posible?";
                        Sleep(2200);
                        system("cls");
                        jugador Doppelganger("Doppelganger", tuPersonaje.getVida(), tuPersonaje.getFuerza(), tuPersonaje.getAgilidad(), 0, tuPersonaje.getOro(), 0);

                        while(Doppelganger.getVida()>0){

                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%11))>(Doppelganger.getAgilidad()+(rand()%11))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Has hecho un danio de: " << danio << "!\n\n";
                                        actualVida=Doppelganger.getVida()-danio;
                                        Doppelganger.setVida(actualVida);

                                        if(Doppelganger.getVida() <= 0){

                                            cout << "Has acabado contigo y recibes " << Doppelganger.getOro() << " de oro y " << Doppelganger.getFuerza() << " de experiencia! Aun no logras comprender que ha ocurrido...";
                                            newOro = tuPersonaje.getOro()+Doppelganger.getOro();
                                            tuPersonaje.setOro(newOro);
                                            experiencia = experiencia +Doppelganger.getFuerza();
                                            Doppelganger.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << nombre << " ha esquivado tu ataque!\n\n";

                                    }

                                    if(Doppelganger.getVida()>0){

                                        if((Doppelganger.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Doppelganger.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << nombre << " te ha hecho un danio de: " << danio << "!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Esquivaste el ataque de " << nombre <<"!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;
                                }
                                case 2:{

                                    if((rand()%3)==1){

                                        cout << "Por alguna razon, " << nombre << " te ha dejado vivir y se ha marchado...\n";
                                        PressAnyButton();
                                        Doppelganger.setVida(0);
                                        break;

                                    }
                                    else{

                                        cout << "Que hiciste... ";
                                        Sleep(3000);
                                        system("cls");
                                        tuPersonaje.setVida(0);
                                        Doppelganger.setVida(0);
                                        break;

                                    }
                                    break;
                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }
                            }

                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    default:{

                        cout << "Ingresa una opcion valida.";
                        PressAnyButton();
                    }
                }
                if(tuPersonaje.getNivel() == 4)
                switch(son){

                    case 's':{

                        cout << "Gwyn, Senior de la Ceniza, ha aparecido. ";
                        jugador Gwyn("Espadon", 700, 200, 200, 0, 0, 0);

                        while(Gwyn.getVida()>0){
                            cout << "Que deseas hacer?\n\n[1]Atacar\n\n[2]Rezar\n\n>> ";
                            cin >> elecCombate;
                            system("cls");
                            switch(elecCombate){

                                case 1:{

                                    if((tuPersonaje.getFuerza()+(rand()%11))>(Gwyn.getAgilidad()+(rand()%11))){

                                        danio=tuPersonaje.getFuerza()*(tuArma.getAtaquePrincipal()+tuArma.getAtaqueSecundario());
                                        cout << "Tu ataque hizo un danio de: " << danio << "!\n\n";
                                        actualVida=Gwyn.getVida()-danio;
                                        Gwyn.setVida(actualVida);

                                        if(Gwyn.getVida() <= 0){

                                            cout << "Has derrotado a Gwyn!\n\n";
                                            cout << "Derrotaste al Senior de la Ceniza!";
                                            Sleep (2000);
                                            system("cls");
                                            cout << "Gwyn te felicita desde el suelo... \"Bien hecho, " << nombre <<". Veo que eres demasiado fuerte " <<
                                            "te aseguro que todo el mundo te \nrecordara, y que nadie olvidara tu nombre " <<
                                            "pero esto recien ha comenzado... Entiendes eso, " << nombre <<"?\""
                                            "\n\n<<Gwyn esta detras tuyo, luchaste con una ilusion>> ";
                                            PressAnyButton();
                                            tuPersonaje.setVida(0);

                                        }
                                    }
                                    else{

                                        cout << "Gwyn ha desviado tu ataque con su espada!\n\n";

                                    }

                                    if(Gwyn.getVida()>0){

                                        if((Gwyn.getFuerza()+(rand()%11))>(tuPersonaje.getAgilidad()+(rand()%11))){

                                            danio=Gwyn.getFuerza()*4;
                                            danio=danio*tuPersonaje.getArmadura();
                                            cout << "El ataque de Gwyn te ha causado " << danio << " de danio!\n\n";
                                            actualVida=tuPersonaje.getVida()-danio;
                                            tuPersonaje.setVida(actualVida);

                                        }
                                        else{

                                            cout << "Has esquivado el ataque de Gwyn perfectamente!!!";

                                        }
                                    }
                                    PressAnyButton();
                                    break;
                                }
                                case 2:{

                                    cout << "Vaya decision... que equivocacion...\n";
                                    Sleep(1500);
                                    cout << "GWYN TE PARTE A LA MITAD!";
                                    Sleep(3000);
                                    system("cls");
                                    tuPersonaje.setVida(0);
                                    Gwyn.setVida(0);
                                    break;

                                }
                                default:{

                                    cout << "Ingresa una opcion valida.\n\n";
                                    PressAnyButton();

                                }
                            }
                            if(tuPersonaje.getVida()<=0){

                                cout << "Has sido asesinado!";
                                Sleep(1700);
                                system("cls");
                                break;

                            }
                        }
                        break;
                    }
                    default:{

                        system("cls");
                        break;
                    }
                }
                break;
            }
            case 3:{

                system("cls");
                cout << "Bienvenido a la Tienda de Pociones\n";
                cout << "Actualmente tienes " << tuPersonaje.getOro() << " de oro.\n\n";
                cout << "Que te gustaria comprar?\n\n[1]Pocion de Vida- 25g\n\n[2]Super Pocion de Vida - 45g\n\n[3]Ultra Pocion de Vida - 100g" <<
                "\n\n[4]Pocion de Fuerza - 65g\n\n[5]Pocion de Agilidad - 50g\n\n[6]Salir\n\n>> ";
                int elecArmeria;
                cin >> elecArmeria;
                system("cls");
                switch(elecArmeria){

                case 1:{

                    if(tuPersonaje.getOro()>24){

                        newVida = tuPersonaje.getVida()+20;
                        tuPersonaje.setVida(newVida);
                        newOro = tuPersonaje.getOro()-25;
                        tuPersonaje.setOro(newOro);
                        cout << "Glug, glug, glug... Has recuperado un poco de tu salud!";
                        PressAnyButton();
                        break;

                    }
                    else{

                        cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                        PressAnyButton();
                        break;

                    }
                }
                case 2:{

                    if(tuPersonaje.getOro()>44){

                        newVida = tuPersonaje.getVida()+45;
                        tuPersonaje.setVida(newVida);
                        newOro = tuPersonaje.getOro()-45;
                        tuPersonaje.setOro(newOro);
                        cout << "Glug, glug, glug... Has recuperado tu salud!";
                        PressAnyButton();
                        break;

                    }else{

                        cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                        PressAnyButton();
                        break;

                    }
                }
                case 3:{

                    if(tuPersonaje.getOro()>99){

                        newVida = tuPersonaje.getVida()+110;
                        tuPersonaje.setVida(newVida);
                        newOro = tuPersonaje.getOro()-100;
                        tuPersonaje.setOro(newOro);
                        cout << "Glug, glug, glug... Has recuperado DEMASIADA salud!";
                        PressAnyButton();
                        break;

                    }else{

                        cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                        PressAnyButton();
                        break;

                    }
                }
                case 4:{

                    if(tuPersonaje.getOro()>64){

                        newFuerza = tuPersonaje.getFuerza()+1;
                        tuPersonaje.setFuerza(newFuerza);
                        newOro = tuPersonaje.getOro()-65;
                        tuPersonaje.setOro(newOro);
                        cout << "Glug, glug, glug... Te sientes mas fuerte!";
                        PressAnyButton();
                        break;

                    }else{

                        cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                        PressAnyButton();
                        break;

                    }
                }
                case 5:{

                    if(tuPersonaje.getOro()>49){

                        newAgilidad = tuPersonaje.getAgilidad()+1;
                        tuPersonaje.setAgilidad(newAgilidad);
                        newOro = tuPersonaje.getOro()-50;
                        tuPersonaje.setOro(newOro);
                        cout << "Glug, glug, glug... Te sientes mas agil!";
                        PressAnyButton();
                        break;

                    }else{

                        cout << "Intentas enganiarnos, listillo? Vuelve cuando tengas oro!!!";
                        PressAnyButton();
                        break;

                    }
                }
                case 6:{

                    break;
                }
                default:{

                    cout << "Ingresa una opcion valida.\n\n";
                    PressAnyButton();

                }
            }
            break;
        }
            case 4:{

                cout << "Y los stats de nuestro queridisimo " << nombre << " son:" << endl << endl;
                cout << "Nivel: " << tuPersonaje.getNivel() << endl;
                cout << "Experiencia: " << experiencia << endl << endl;
                cout << "Salud: " << tuPersonaje.getVida() << endl;
                cout << "Fuerza: " << tuPersonaje.getFuerza() << endl;
                cout << "Agilidad: " << tuPersonaje.getAgilidad() << endl << endl;
                cout << "Los stats de tu arma \"" << tuArma.getNombre() << "\" son:" << endl << endl;
                cout << "Ataque Principal: " << tuArma.getAtaquePrincipal() << endl;
                cout << "Ataque Secundario: " << tuArma.getAtaqueSecundario() << endl;
                PressAnyButton();
                break;

            }
            case 5:{

                cout << "En serio quieres salir del juego?\n[S]i o [N]o?\n\n>> ";
                cin >> son;
                if(son == 's' || son == 'S')
                    tuPersonaje.setVida(0);

                system("cls");
                break;

            }
            default:{

                cout << "Ingresa una opcion valida.\n\n";
                PressAnyButton();

            }
        }
    }
    if(tuPersonaje.getVida()<=0){

        GameOver();
        cout << "Tu score es: " << experiencia;
        PressAnyButton();

    }

    cout << "Deseas jugar de nuevo?\n[S]i o [N]o?\n\n>> ";
    cin >> son;
    system("cls");

    switch(son){

        case 's':

            Inicializar();
            break;

        case 'S':

            Inicializar();
            break;

        default:

            break;
        }

}
