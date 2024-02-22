#include <iostream>
using namespace std;
#include "MenuConfiguraciones.h"
#include "FuncionesGlobales.h"


void MenuConfiguraciones::Mostrar()
{
    while (true) {
        system("cls");
        cout << "----- CONFIGURACIONES -----" << endl;
        cout << "1 - Consultar horarios" << endl;
        cout << "2 - Configurar horarios" << endl;
        cout << "3 - Consultar de unidades" << endl;
        cout << "4 - Modificar cantidad de unidades" << endl;
        cout << "0 - Volver" << endl;

        int opcion = ingresarOpcionMenu(4);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(4);
        }

        switch (opcion) {
        case 1:
            _manager.ConsultaHorarios();
            break;
        case 2:
            _manager.ConfiguracionHorarios();
            break;
        case 3:
            _manager.CantidadUnidades();
            break;
        case 4:
            _manager.ModificarCantUnidades();
            break;
        case 0:        
            return;        
            break;
        default:
            break;
        }
    }
}