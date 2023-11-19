#include "MenuAbmPersonas.h"
#include <iostream>
using namespace std;

void MenuAbmPersonas::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     ABM     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Proveedores" << endl;
        cout << "2 - Visitas" << endl;
        cout << "3 - Residentes" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            _manager.AltaProveedor();
            break;
        case 2:
            _manager.AltaVisita();
            break;
        case 3:
            _manager.AltaResidente();
            break;       
        case 0:
            return;
            break;
        }
    }
}