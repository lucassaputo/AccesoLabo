#pragma once
#include "Persona.h"

class Usuario: public Persona  {
private:
	char _nick[20];
	char _password[20];
	int _legajo;
	int _nivel;
	bool _estado;

public:
	Usuario(int legajo = 000) { _legajo = legajo; }
	
	//sets
	void setNick(std::string n);
	void setPassword(std::string pass);;
	void setLegajo(int l);
	void setNivel(int n);
	void setEstado(bool b);
	
	//gets
	std::string getNick();
	std::string getPassword();
	int getLegajo() const;
	int getNivel() const;
	bool getEstado();

	//acciones
	void cargar();
	void editar();
	void mostrar();	
	int ingresarNivel();
};