#include <stdio.h>
#include <windows.h>
#include "Jugador.h"
#include "Arma.h"
#include "Funciones.h"
#include "Game.h"

void Inicializar();

void PressAnyButton(){

    cout << "\n" << endl;
    system("pause");
    system("cls");

}

void StartScreen(){

    cout << "\t                              " << endl;
    cout << "\t   R)rrrrr  P)ppppp    G)gggg  " << endl;
    cout << "\t   R)    rr P)    pp  G)       " << endl;
    cout << "\t   R)  rrr  P)ppppp  G)  ggg   " << endl;
    cout << "\t   R) rr    P)       G)    gg  " << endl;
    cout << "\t   R)   rr  P)        G)   gg  " << endl;
    cout << "\t   R)    rr P)         G)ggg   " << endl;
    cout << "\t                               " << endl;

    Sleep(500);

}

void GameOver(){

    cout << "                                                                             " << endl;
    cout << "     G)gggg                                O)oooo                            " << endl;
    cout << "    G)                                    O)    oo                           " << endl;
    cout << "   G)  ggg  a)AAAA   m)MM MMM  e)EEEEE    O)    oo v)    VV e)EEEEE  r)RRR   " << endl;
    cout << "   G)    gg  a)AAA  m)  MM  MM e)EEEE     O)    oo  v)  VV  e)EEEE  r)   RR  " << endl;
    cout << "    G)   gg a)   A  m)  MM  MM e)         O)    oo   v)VV   e)      r)       " << endl;
    cout << "     G)ggg   a)AAAA m)      MM  e)EEEE     O)oooo     v)     e)EEEE r)       " << endl;
    cout << "                                                                             " << endl;

    Sleep(2000);
    system("cls");

}

jugador chooseClase(){

    int claseChoice;
    cout << "Elige una clase.\n\n" << "[1] Caballero - balanceado\n\n[2] Asesino - agil\n\n[3] Mago - fuerte\n\n>> ";
    cin >> claseChoice;
    system("cls");
    switch(claseChoice){

    case 1:
        cout << "Un caballero! Eso quiere decir que eres habil con cualquier tipo de arma!" <<
        "... \nBlandir cualquier tipo de espada, quiza... Ademas llevas una gran armadura! " <<
        "Suerte en tu viaje!";
        return jugador ("Caballero", 50, 12, 12, 0.99, 50, 1);
        break;

    case 2:
        cout << "Asi que eres un asesino, eh? Bueno, no tiene tanta fuerza como las demas clases..." <<
        " \npero no debes de preocuparte por nada ya que posees una \nprecision increible. Ademas eres capaz " <<
        "de esquivar con facilidad los ataques enemigos \ny mucho mas!";
        return jugador("Asesino", 40, 12, 16, 0.80, 55, 1);
        break;

    case 3:
        cout << "Magia! Puedes usar todo tipo de conjuros, si senior.\n" <<
        "Pero aqui en este humilde pueblo todos deben usar armas, sin embargo " <<
        "seras capaz de concentrar toda tu \nmagia en tus armas!";
        return jugador("Mago", 45, 15, 11, 0.90, 50, 1);
        break;

    case 1234567:
        cout << "Has escogido ... Saiyan. Tu fuerza no tiene limites!!!";
        return jugador("Saiyan", 10000, 500, 500, 0.99, 10000, 4);
        break;

    default:
        cout << "Ingresa una opcion valida.\n\n";
        PressAnyButton();
        return chooseClase();

    }
}

arma chooseArma(){

    cout << "Por favor, elige un arma.\n\n[1]Espada\n\n[2]Espada Larga\n\n[3]Hoz\n\n" <<
    "[4]Arco\n\n[5]Pistolas\n\n[6]Clarinete\n\n>> ";
    int armaChoice;
    cin >> armaChoice;
    system("cls");
    switch(armaChoice){

        case 1:
            cout << "Una Espada, que tierno.";
            return arma("Espada", 1, 0);
            break;

        case 2:
            cout << "Una Espada Larga, en serio puedes cargarla?";
            return arma("Espada Dual", 1, 1);
            break;

        case 3:
            cout << "Una Hoz, senior de la muerte.";
            return arma("Hoz", 2, 0);
            break;

        case 4:
            cout << "Un Arco, y tus flechas?.";
            return arma("Arco", 1, 1);
            break;

        case 5:
            cout << "Unas Pistolas, donde guardas la municion?";
            return arma("Pistolas", 2, 0);
            break;

        case 6:
            cout << "Un Clarinete... no se que decirte, tu lo elegiste...";
            return arma("Clarinete", 0, 0);
            break;

        case 1234567:
            cout << "Eres un Saiyan... Tu poder no conoce los limites!";
            return arma("Ki", 4, 4);

        default:
            cout << "Ingresa una opcion valida.\n\n";
            PressAnyButton();
            return chooseArma();

    }
}

void Menu(){

    StartScreen();
    cout << endl;
	cout<<"\t\t 1. Comenzar..."<<endl;
	Sleep(100);
	cout<<"\t\t 2. Informacion..."<<endl;
	Sleep(100);
	cout<<"\t\t 3. Salir..."<<endl;

	cout<<"\n";
	Sleep(100);

	cout<<"\t Selecciona una opcion: ";
	int opcion;
	cin>>opcion;

	switch(opcion){

        case 1:{

            Inicializar();

        }
        case 2:{

            system("cls");
            cout << endl << endl;
            printf("\tHecho por Rodrigo Jesus Ali Guevara!\n");
            PressAnyButton();
            Menu();

        }

        case 3:{

            system("cls");
            GameOver();
            exit(0);

        }

        default:{

            system("cls");
            cout << endl << endl;
            cout << "\t\tIngresa una opcion valida.\n\n";
            PressAnyButton();
            Menu();

        }

	}

}
