#include "MenuRegistros.h"
#include <iostream>
#include "UserSingleton.h"
#include "FuncionesGlobales.h"
using namespace std;

void MenuRegistros::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "********* MOVIMIENTOS *********" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Nuevo movimiento" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion = ingresarOpcionMenu(1);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(1);
        }

        switch (opcion) {
        case 1:
            _manager.Cargar();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}