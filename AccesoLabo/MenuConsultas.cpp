#include <iostream>
using namespace std;
#include "MenuConsultas.h"


void MenuConsultas::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     CONSULTAS     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Consulta de autorizados" << endl;
        cout << "2 - Consulta de residentes" << endl;
        cout << "3 - Consulta de proveedores" << endl;
        cout << "4 - Consulta de empleados" << endl;
        cout << "5 - Consulta de unidades" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;/*
        switch (opcion) {//
        case 1:
            _manager.ConsultaAutorizados();
            break;
        case 2:
            _manager.ConsultaResidentes();
            break;
        case 3:
            _manager.ConsultaProveedores();
            break;
        case 4:
            _manager.ConsultaEmpleados();
            break;
        case 5:
            _manager.ConsultaUnidades();
            break;
        case 0:
            return;
            break;
        }*/
    }
}