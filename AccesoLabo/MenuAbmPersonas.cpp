#include "MenuAbmPersonas.h"
#include <iostream>
using namespace std;

void MenuAbmPersonas::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     ABM     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "* - Proveedores" << endl;
        cout << "       1- Alta." << endl;
        cout << "       2- Modificar." << endl;
        cout << "       3- Baja." << endl;
        cout << "* - Visitas" << endl;
        cout << "       4- Alta." << endl;
        cout << "       5- Modificar." << endl;
        cout << "       6- Baja." << endl;
        cout << "* - Residentes" << endl;
        cout << "       7- Alta." << endl;
        cout << "       8- Modificar." << endl;
        cout << "       9- Baja." << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            _manager.AltaProveedor();
            break;
        case 2:
            _manager.EditarProveedor();
            break;
        case 3:
            _manager.BajaProveedor();
            break;       
        case 4:
            _manager.AltaVisita();
            break;
        case 5:
            _manager.EditarVisita();
            break;
        case 6:
            _manager.BajaVisita();
            break;
        case 7:
            _manager.AltaResidente();
            break;
        case 8:
            _manager.EditarResidente();
            break;
        case 9:
            _manager.BajaResidente();
            break;
        case 0:
            return;
            break;
        }
    }
}