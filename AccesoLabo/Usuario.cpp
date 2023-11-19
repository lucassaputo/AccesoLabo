#include "Usuario.h"
#include<iostream>

using namespace std;


//sets
void Usuario::setNick(std::string n) { strcpy(_nick, n.c_str()); }
void Usuario::setPassword(std::string pass) { strcpy(_password, pass.c_str()); }
void Usuario::setNivel(int n) { _nivel = n; }

//gets
std::string Usuario::getNick() const { return _nick; }
std::string Usuario::getPassword() const { return _password; }
int Usuario::getNivel() const { return _nivel; };


//acciones

void Usuario::mostrar() {
	Persona::mostrar();
	cout << "Nick : " << _nick << endl;	
}
