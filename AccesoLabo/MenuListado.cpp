#include <iostream>
using namespace std;
#include "MenuListado.h"
#include "ListadoManager.h"


void MenuListado::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     LISTADOS     **************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Listado de autorizados, ordenados por apellido" << endl;
        cout << "2 - Listado de autorizados, ordenados por unidad" << endl;
        cout << "3 - Listado de residentes, ordenados por unidad" << endl;
        cout << "4 - Listado de proveedores, ordenados por razon social" << endl;
        cout << "5 - Listado de proveedores, ordenados por DNI" << endl;
        cout << "6 - Listado de unidades, ordenados por numero" << endl;
        cout << "7 - Listado de unidades, ordenados por apellido familia" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            _manager.AutorizadosPorApellido();
            break;
        case 2:
            _manager.AutorizadosPorUnidad();
            break;
        case 3:
            _manager.ResidentesPorUnidad();
            break;
        case 4:
            _manager.ProveedoresPorRazon();
            break;
        case 5:
            _manager.ProveedoresPorDNI();
            break;
        case 6:
            _manager.UnidadesPorNumero();
            break;
        case 7:
            _manager.UnidadesPorFamilia();
            break;        
        case 0:
            return;
            break;
        }
    }
}