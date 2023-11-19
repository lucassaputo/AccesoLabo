#include <iostream>
using namespace std;
#include "MenuConfiguraciones.h"


void MenuConfiguraciones::Mostrar()
{
    cout << "----- CONFIGURACIONES -----" << endl;
    cout << " 1 - Configuracion de Contraseñas" << endl;
    cout << "2 - Configuracion de Horarios" << endl;
    cout << "0 - Volver" << endl;

    int opcion;
    cin >> opcion;
    switch (opcion) {
    case 1:
    {

    }
    break;
    case 2:
    {

    }
    break;

    case 3:
    {
        return;
    }
    break;
    }
}