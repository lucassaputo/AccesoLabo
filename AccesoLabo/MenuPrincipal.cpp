#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "MenuRegistros.h"
#include "MenuListado.h"
#include "MenuConsultas.h"
#include "MenuAbmPersonas.h"
#include "MenuAbmUnidades.h"
#include "MenuInformes.h"
#include "MenuConfiguraciones.h"
#include "MenuExportacion.h"
#include "FuncionesGlobales.h"



void MenuPrincipal::Mostrar() {
    while (true) {
    system("color 40");
        system("cls");//limpia cuando vuelve de un submenu
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "*********     CONTROL DE ACCESOS     *********" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "1 - Movimientos" << endl;
        cout << "2 - ABM Personas" << endl;
        cout << "3 - ABM Autorizaciones" << endl;
        cout << "4 - ABM Unidades" << endl;
        cout << "5 - Listados" << endl;
        cout << "6 - Consultas" << endl;
        cout << "7 - Informes" << endl;
        cout << "8 - Configuraciones" << endl;
        cout << "9 - Backups" << endl;
        cout << "10 - Creditos" << endl;

        cout << "*******************************" << endl;
        cout << "0 - Salir del programa" << endl;

        int opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
        {
            MenuRegistros menu;
            menu.Mostrar();
            //test
        }
        break;
        case 2:
        {
            MenuAbmPersonas menu;
            menu.Mostrar();
        }
        break;
        case 3:
        {
            //autorizaciones
        }
        break;

        case 4:
        {
            MenuAbmUnidades menu;
            menu.Mostrar();
        }
        break;
        case 5:
        {
            MenuListado menu;
            menu.Mostrar();
        }
        break;
        case 6:
        {
            MenuInformes menu;
            menu.Mostrar();
        }
        break;
        case 7:
        {
            MenuConfiguraciones menu;
            menu.Mostrar();
        }
        break;
        case 8:
        {
            MenuExportacion menu;
            menu.Mostrar();
        }
        break;

        case 9:
        
            
            
           Creditos();
            break;
        
        case 0: {
            return;
            break;
        }
        }
    }
}
    