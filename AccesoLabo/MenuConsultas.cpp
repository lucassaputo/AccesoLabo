#include <iostream>
using namespace std;
#include "MenuConsultas.h"


void MenuConsultas::Mostrar() {
    while (true) {
        system("cls");
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "**************     CONSULTAS     *************" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Consulta de autorizados por Unidad" << endl;
        cout << "2 - Consulta de autorizados por Apellido" << endl;
        cout << "3 - Consulta de residentes por Unidad" << endl;
        cout << "4 - Consulta de residentes por Apellido" << endl;
        cout << "5 - Consulta de proveedores por Razon Social" << endl;
        cout << "6 - Consulta de Proveedores por DNI" << endl;
        cout << "7 - Consulta de unidades por Nombre" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Volver" << endl;
      
        int opcion = ingresarOpcionMenu(7);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(7);
        }

        switch (opcion) {
        case 1:
            _manager.ConsultaAutorizadosxUnidad();
            break;
        case 2:
            _manager.ConsultaAutorizadosxApellido();
            break;
        case 3:
            _manager.ConsultaResidentesxUnidad();
            break;
        case 4:
            _manager.ConsultaResidentesxApellido();
            break;
        case 5:
            _manager.ConsultaProveedoresxRazonSocial();
            break;
       
        case 6:
            _manager.ConsultaProveedoresxCUIT();
            break;
        case 7:
            
            _manager.ConsultaUnidadesxNombre();
            break;         
                
        case 0:
            return;
            break;
        }
    }
}