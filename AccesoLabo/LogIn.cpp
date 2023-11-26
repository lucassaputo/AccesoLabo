#include "LogIn.h"
#include "Singleton.h"
#include "Usuario.h"
#include "ArchivoUsuario.h"
#include "FuncionesGlobales.h"
#include <iostream>
#include <cstring>


void LogIn::Mostrar() {
	int opc;
	int pos = 0;
	int legajo;
	while (true)
	{
		system("cls");
			Singleton& s = Singleton::getInstance();

		std::cout << "**Log In**" << std::endl;
		std::cout << "**Legajo: " << s.getUsuario().getLegajo() << std::endl; //muestra usuario logeado - si se cierra/no hay sesion legajo =0
		std::cout << "**ESTADO: " << s.getUsuario().getEstado() << std::endl; 
		if (s.getUsuario().getLegajo() != 0) {
			std::cout << s.getUsuario().getNombres() << " " << s.getUsuario().getApellidos() << std::endl;
		}
		std::cout << "1 - Iniciar Sesion" << std::endl;
		std::cout << "2 - Cerrar Sesion" << std::endl;
		std::cout << "3 - Alta Usuario" << std::endl;
		std::cout << "4 - Baja Usuario" << std::endl;
		std::cout << "5 - PRUEBA LISTAR REGISTROS" << std::endl;
		std::cout << "0 - Salir del Programa" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case 1: // iniciar sesion
		{	
			std::string pasword;
			Usuario reg;
			ArchivoUsuario archUsuario("Usuarios.dat");
			system("cls");
			std::cout << "Ingrese su numero de legajo:" << std::endl;
			std::cin >> legajo;
			pos = archUsuario.Buscar(legajo);
			if (pos < 0 && s.getUsuario().getEstado()==false) {
				std::cout << "Legajo inexistente" << std::endl;
				system("pause");
			}
			else {
					reg = archUsuario.Leer(pos);
					s.setMiClase(reg);
				std::cout << "ingrese la contraseña" << std::endl;
				std::cin >> pasword;
			}if (strcmp(pasword.c_str(), s.getUsuario().getContraseña()) == 0) {
					MenuPrincipal menu;
					menu.Mostrar();
				}
				else {
					std::cout << "Contraseña incorrecta" << std::endl;
					s.ReiniciarClase();
					system("pause");
				}			
								
		}				
		break;
		case 2: //cerrar sesion
		{
			system("pause");
			std::cout << "Cerrar Sesion" << std::endl;
			s.ReiniciarClase();
			system("pause");
		}
		break;
		case 3: // alta usuario
		{
			system("cls");
			std::cout << "ALTA USUARIO" << std::endl;
			Usuario reg;
			ArchivoUsuario arch("usuarios.dat");
			reg.cargar();
			if (arch.Guardar(reg) == true) {
				std::cout << "registro guardado con exito" << std::endl;
			}
			system("pause");
		}
		break;
		case 4: //baja usuario
		{	
			int legajoAnterior = legajo;
			char seguro;
			std::cout << "BAJA USUARIO" << std::endl;
			Usuario reg;
			ArchivoUsuario arch("usuarios.dat");
			std::cout << "Ingrese el numero de legajo:" << std::endl;
			std::cin >> legajo;
			pos = arch.Buscar(legajo);
			if (pos < 0 ) {
				std::cout << "Legajo inexistente" << std::endl;
				system("pause");
			}
			else {
				reg = arch.Leer(pos);
				s.setMiClase(reg);
				s.getUsuario().mostrar();
				std::cout << "Esta seguro(s/n)" << std::endl;
				std::cin >> seguro;
				if (seguro == 's' || seguro == 'S') {
					//s.getUsuario().setEstado(false);
					arch.Guardar(s.getUsuario());
					std::cout << "usuario borrado" << std::endl;
					system("pause");
					
				}
			}
			pos = arch.Buscar(legajoAnterior);
			reg = arch.Leer(pos);
			s.setMiClase(reg);
			}
			break;
		case 5:
		{
			ArchivoUsuario arch("usuarios.dat");
			arch.ListarUsuarios();
			system("pause");
		}
			break;
		case 0:
			return;
			break;
	}
	}
	}


