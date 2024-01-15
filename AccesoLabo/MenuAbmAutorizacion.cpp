#include "MenuAbmAutorizacion.h"
#include <iostream>
using namespace std;
void MenuAbmAutorizacion::Mostrar()
{
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     ABM     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Alta" << endl;
        cout << "2 - edicion" << endl;
        cout << "3 - baja" << endl;
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
        case 0:
            return;
            break;
        }
    }
}
