#include "MenuAbmUnidades.h"
#include <iostream>
using namespace std;

void MenuAbmUnidades::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     ABM     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Alta" << endl;
        cout << "2 - Edicion" << endl;
        cout << "3 - Baja" << endl;
        cout << "4 - Listar" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            _manager.Alta();
            break;
        case 2:
            _manager.Editar();
            break;
        case 3:
            _manager.Baja();
            break;
        case 4:
            _manager.Listar();
            break;
        case 0:
            return;
            break;
        }
    }
}