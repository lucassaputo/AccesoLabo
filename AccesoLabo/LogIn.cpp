#include "LogIn.h"
#include "UserSingleton.h"
#include "Usuario.h"
#include "ArchivoUsuario.h"
#include "FuncionesGlobales.h"
#include "MenuPrincipal.h"
#include <iostream>
#include <cstring>

void LogIn::Mostrar() {
	UserSingleton& user = UserSingleton::getInstance();
	std::string pasword, legajo;
	Usuario u;
	std::cout << "BIENVENIDO" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
	legajo = ingresarLegajo();
	u = _archivoUsuario.BuscarObj(legajo);
	//std::cout << "eeee:     " << u.getLegajo();
	//u.mostrar();	
	while (true) {
		if (u.getLegajo() != "-1") {
			if (u.getEstado()) {
				//u.mostrar();
				std::cout << "Ingrese password" << std::endl;
				std::cin >> pasword;
				if (strcmp(pasword.c_str(), u.getPassword().c_str()) == 0) {
					user.setMiClase(u);
					MenuPrincipal menu;
					menu.Mostrar();
				}
				else {
					std::cout << "Password incorrecto" << std::endl;
					//user.ReiniciarClase();
					
				}
			}
			else {
				std::cout << "Legajo inexistente" << std::endl;
			}
		}
		else {
			std::cout << "Legajo inexistente" << std::endl;
		}
		system("pause");
		system("cls");
		std::cout << "BIENVENIDO" << std::endl;
		std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
		legajo = ingresarLegajo();
		u = _archivoUsuario.BuscarObj(legajo);
		std::cout << "eeee:     " << u.getLegajo();
	//	u.mostrar();
	}
	//system("pause");
}
	


