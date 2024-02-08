#include "Usuario.h"
#include<iostream>
#include <cstring>
#include "FuncionesGlobales.h"

using namespace std;


//sets
void Usuario::setNick(std::string n) { strcpy(_nick, n.c_str()); }
void Usuario::setPassword(std::string pass) { strcpy(_password, pass.c_str()); }
void Usuario::setLegajo(int l) { _legajo = l;}
void Usuario::setNivel(int n) { _nivel = n; }
void Usuario::setEstado(bool b) { _estado = b; }


//gets
std::string Usuario::getNick() { return _nick; }
std::string Usuario::getPassword() { return _password; }
int Usuario::getLegajo() const { return _legajo; };
int Usuario::getNivel() const { return _nivel; };
bool Usuario::getEstado() { return _estado; };
//acciones
void Usuario::cargar()
{
	string nick,password;
	int dni;
	Persona::cargarPersona();	
	Persona::setDni(cargarDni());
	setNivel(ingresarNivel());

	std::cout << "Nick: " << endl;
	std::cin >> nick;
	strcpy(_nick, nick.c_str());
	std::cout << "Pasword: " << std::endl;
	std::cin >> password;
	strcpy(_password, password.c_str());
	_estado = true;
}

void Usuario::editar()
{
	string nick, password;
	int dni;
	Persona::editarPersona();
	std::cout << "Ingrese el DNI: " << std::endl;
	std::cin >> dni;
	std::cout << "Ingrese el nivel: " << std::endl;
	std::cin >> _nivel;
	Persona::setDni(dni);
	std::cout << "Nick: " << endl;
	std::cin >> nick;
	strcpy(_nick, nick.c_str());
	std::cout << "Pasword: " << std::endl;
	std::cin >> password;
	strcpy(_password, password.c_str());
}

void Usuario::mostrar() {
	Persona::mostrar();
	std::cout << "Nick : " << _nick << std::endl;	
	std::cout << "Legajo: " << _legajo << std::endl;
	std::cout << "Nivel: " << _nivel << std::endl;	
	std::cout << "estado: " <<  _estado 
		<< std::endl;
}

int Usuario::ingresarNivel() {
	string aux;
	bool valido = false;
	int i = 0;
	while (!valido) {
		if (i == 0) {
			std::cout << "Ingrese el nivel (1-Administrador || 2-Vigilador): " << std::endl;
		}
		else {
			std::cout << "Nivel invalido (1-Administrador || 2-Vigilador). Ingrese el nivel: " << std::endl;		
		}
		std::cin >> aux;
		i++;
		if (aux == "1" || aux == "2") {
			valido = true;
		}
	}
	return std::stoi(aux);
}

