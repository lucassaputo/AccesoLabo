#include <iostream>
using namespace std;
#include "MenuConfiguraciones.h"


void MenuConfiguraciones::Mostrar()
{
    while (true)
    {
    system("cls");
        cout << "----- CONFIGURACIONES -----" << endl;
        cout << "1 - Configuracion de Contraseñas" << endl;
        cout << "2 - Configuracion de Horarios" << endl;
        cout << "0 - Volver" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
        {
            system("cls");
            _manager.ConfiguracionContraseña();
            system("pause");

        }
        break;
        case 2:
        {
            system("cls");
            _manager.ConfiguracionHorarios();
            system("pause");
        }
        break;

        case 0:
        {
            return;
        }
        break;
        }
    }
}