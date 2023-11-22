#pragma once
#include<cstring>
#include "Fecha.h"
#include "Persona.h"

class Usuario: public Persona  {
private:
	char _nick[20];
	char _password[20];
	int _legajo;
	bool _estado;
	int _nivel;

public:
	Usuario(int legajo = 000, bool estado=true) { _legajo = legajo, _estado=estado; }
	//sets
	void setNick(std::string n);
	void setPassword(std::string pass);;
	void setLegajo(int l);
	void setEstado(bool e);
	void setNivel(int n);
	//gets

	std::string getNick() const;
	const char* getContraseña() { return _password; }
	//std::string getPassword() const;
	int getLegajo() const;
	bool getEstado() const;
	int getNivel() const;

	//acciones
	void cargar();
	void mostrar();
	
};