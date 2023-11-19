#pragma once
#include<cstring>
#include "Fecha.h"
#include "Persona.h"

class Usuario : public Persona {
private:
	char _nick[20];
	char _password[20];
	int _nivel;
public:
	//sets
	void setNick(std::string n);
	void setPassword(std::string pass);;
	void setNivel(int n);

	//gets
	std::string getNick() const;
	std::string getPassword() const;
	int getNivel() const;

	//acciones
	void mostrar();
};