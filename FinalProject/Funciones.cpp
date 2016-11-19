#include "Funciones.h"

void PressAnyButton(){

    cout << "\n" << endl;
    system("pause");
    system("cls");

}

void StartScreen(){

    cout << "\t               Un              " << endl;
    cout << "\t   R)rrrrr  P)ppppp    G)gggg  " << endl;
    cout << "\t   R)    rr P)    pp  G)       " << endl;
    cout << "\t   R)  rrr  P)ppppp  G)  ggg   " << endl;
    cout << "\t   R) rr    P)       G)    gg  " << endl;
    cout << "\t   R)   rr  P)        G)   gg  " << endl;
    cout << "\t   R)    rr P)         G)ggg   " << endl;
    cout << "\t           O algo asi          " << endl;

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

void Menu(){

    StartScreen();
    cout << endl;
	cout<<"\t\t 1. Jugar..."<<endl;
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

            system("cls");
            Game();

        }
        case 2:{

            system("cls");
            cout << endl << endl;
            cout << "\t Hecho por Rodrigo Jesus Ali Guevara!\n";
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

