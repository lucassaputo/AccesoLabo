#include <iostream>
using namespace std;
#include "MenuConfiguraciones.h"
#include "FuncionesGlobales.h"


void MenuConfiguraciones::Mostrar()
{
    while (true) {
        system("cls");
        cout << "----- CONFIGURACIONES -----" << endl;
        cout << "1 - Configuracion de Horarios" << endl;
        cout << "0 - Volver" << endl;

        int opcion = ingresarOpcionMenu(1);
        while (opcion == -1) {
            opcion == ingresarOpcionMenu(1);
        }

        switch (opcion) {
        case 1:
            _manager.ConfiguracionHorarios();
            break;
        case 0:        
            return;        
            break;
        }
    }
}