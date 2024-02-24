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
        cout << "3 - Historial de Movimientos Mensuales" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion = ingresarOpcionMenu(3);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(3);
        }

        switch (opcion) {
        case 1:
            _manager.UnidadesMas50();
            break;
        case 2:
            _manager.InformeProveedores();
            break;
        case 3:
            _manager.MovimientosPorUnidad();
            break;       
        case 0:
            return;
            break;
        default:
            break;
        }
    }


}

