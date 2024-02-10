#include "MenuRegistros.h"
#include <iostream>
#include "UserSingleton.h"
using namespace std;

void MenuRegistros::Mostrar() {
    UserSingleton& s = UserSingleton::getInstance();
    if (s.getUsuario().getNivel() == 1) {
        while (true) {
            system("cls");
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "********* MOVIMIENTOS *********" << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "1 - Nuevo movimiento" << endl;
            cout << "2 - Editar movimiento" << endl;
            cout << "3 - Eliminar movimiento" << endl;
            cout << "*******************************" << endl;
            cout << "0 - Volver" << endl;

            int opcion;
            cin >> opcion;
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
            }
        }
    } else {
        while (true) {
            system("cls");
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "********* MOVIMIENTOS *********" << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "1 - Nuevo movimiento" << endl;           
            cout << "*******************************" << endl;
            cout << "0 - Volver" << endl;

            int opcion;
            cin >> opcion;
            switch (opcion) {
            case 1:
                _manager.Cargar();
                break;            
            case 0:
                return;
                break;
            }
        }

    }
}