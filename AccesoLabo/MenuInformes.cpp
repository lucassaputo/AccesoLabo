#include <iostream>
#include "MenuInformes.h"
using namespace std;
void MenuInformes::Mostrar() {


    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     INFORMES     **************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Unidades con mas de 50 movimientos" << endl;
        cout << "2 - Informe Proveedores Ingresados" << endl;
        cout << "3 - Historial de Movimientos de Unidades" << endl;
        cout << "4 - Historial de Movimientos Mensuales" << endl;
        cout << "5 -" << endl;
        cout << "6 - " << endl;
        cout << "7 - " << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 0:
            return;
            break;
        }
    }


}

