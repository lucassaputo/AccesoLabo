#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "MenuRegistros.h"
#include "MenuListado.h"
#include "MenuConsultas.h"
#include "MenuAbmAutorizacion.h"
#include "MenuAbmPersonas.h"
#include "MenuAbmUnidades.h"
#include "MenuInformes.h"
#include "MenuConfiguraciones.h"
#include "MenuExportacion.h"
#include "MenuUsuarios.h"
#include "FuncionesGlobales.h"
#include "LogIn.h"
#include "UserSingleton.h"

void MenuPrincipal::Mostrar() {
    UserSingleton& s = UserSingleton::getInstance();
    if (s.getUsuario().getNivel() == 1) { //nivel Admin
        while (true) {
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
            cout << "10 - Usuarios" << endl;
            cout << "11 - Creditos" << endl;
            cout << "*******************************" << endl;
            cout << "0 - Salir del programa" << endl;

            int opcion = ingresarOpcionMenu(11);
            while (opcion == -1) {
                opcion == ingresarOpcionMenu(11);
            }

            switch (opcion) {
                case 1:
                {
                    MenuRegistros menu;
                    menu.Mostrar();
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
                    MenuAbmAutorizacion menu;
                    menu.Mostrar();
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
                    MenuConsultas menu;
                    menu.Mostrar();
                }
                break;
                case 7:
                {
                    MenuInformes menu;
                    menu.Mostrar();
                }
                break;
                case 8:
                {
                    MenuConfiguraciones menu;
                    menu.Mostrar();
                }
                break;
                case 9:
                {
                    MenuExportacion menu;
                    menu.Mostrar();
                }
                break;
                case 10:
                {
                    MenuUsuarios menu;
                    menu.Mostrar();
                }
                break;
                case 11:
                {
                    Creditos();
                }
                break;
                case 0: {
                    return;
                    break;
                }
                default:
                    break;
            }
        }
    }
    else if (s.getUsuario().getNivel() == 2) { //nivel vigilador
        while (true) {
            system("cls");//limpia cuando vuelve de un submenu
            cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "*********     CONTROL DE ACCESOS     *********" << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "1 - Movimientos" << endl;
            cout << "2 - ABM Personas" << endl;
            cout << "3 - Listados" << endl;
            cout << "4 - Consultas" << endl;
            cout << "5 - Creditos" << endl;
            cout << "*******************************" << endl;
            cout << "0 - Salir del programa" << endl;

            int opcion = ingresarOpcionMenu(11);
            while (opcion == -1) {
                opcion == ingresarOpcionMenu(11);
            }

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
                MenuListado menu;
                menu.Mostrar();
            }
            break;
            case 4:
            {
                MenuConsultas menu;
                menu.Mostrar();
            }
            break;
            case 5:
            {
                Creditos();
            }
            break;
            case 0: {
                return;
                break;
            }
            }
        }
    }
    else {
        cout << "Error con usuario.";
        system("pause");
        return;
    }
}
    