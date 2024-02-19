#include <iostream>
#include "MenuUsuarios.h"
#include "FuncionesGlobales.h"
using namespace std;

void MenuUsuarios::Mostrar() {
    while (true) {
        system("cls");//limpia cuando vuelve de un submenu
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "*********     USUARIOS     *********" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Alta usuario" << endl;
        cout << "2 - Editar usuario" << endl;
        cout << "3 - Baja usuario" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion = ingresarOpcionMenu(3);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(3);
        }

        switch (opcion) {
        case 1:
            _manager.Cargar();
            break;
        case 2:
            _manager.Editar();
            break;
        case 3:
            _manager.Eliminar();
            break;
        case 0:
             return;
             break;
        default:
            break;
        }
    }
}