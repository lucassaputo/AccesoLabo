#include "Usuario.h"
#include<iostream>
#include <cstring>
#include "FuncionesGlobales.h"

using namespace std;


//sets
void Usuario::setNick(std::string n) { strcpy(_nick, n.c_str()); }
void Usuario::setPassword(std::string pass) { strcpy(_password, pass.c_str()); }
void Usuario::setLegajo(std::string l) { strcpy(_legajo, l.c_str());
	;}
void Usuario::setNivel(int n) { _nivel = n; }
void Usuario::setEstado(bool b) { _estado = b; }


//gets
std::string Usuario::getNick() { return _nick; }
std::string Usuario::getPassword() { return _password; }
std::string Usuario::getLegajo() const { return _legajo; };
int Usuario::getNivel() const { return _nivel; };
bool Usuario::getEstado() { return _estado; };
//acciones
void Usuario::cargar()
{
	string password;
	Persona::cargarPersona();	
	Persona::setDni(cargarDni());
	setNivel(ingresarNivel());
	setNick(cargarString("Nick"));	
	std::cout << "Pasword: " << std::endl;
	std::cin >> password;
	strcpy(_password, password.c_str());
	_estado = true;
}

void Usuario::editar()
{
	string password;
	Persona::editarPersona();
	//Persona::cargarPersona();
	cout << "DNI actual: " << getDni() << endl;
	Persona::setDni(cargarDni());
	cout << "Nivel actual: " << _nivel << endl;
	setNivel(ingresarNivel());
	cout << "Nick actual: " << _nick << endl;
	setNick(cargarString("Nick"));
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
		cin.ignore();
	}
	return std::stoi(aux);
}

