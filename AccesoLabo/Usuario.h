#pragma once
#include "Persona.h"

class Usuario: public Persona  {
private:
	char _nick[20];
	char _password[20];
	char _legajo[5];
	int _nivel;
	bool _activo;

public:
	Usuario(std::string legajo = "-1") { strcpy(_legajo, legajo.c_str());
	}
	
	//sets
	void setNick(std::string n);
	void setPassword(std::string pass);;
	void setLegajo(std::string l);
	void setNivel(int n);
	void setActivo(bool b);
	
	//gets
	std::string getNick();
	std::string getPassword();
	std::string getLegajo() const;
	int getNivel() const;
	bool getActivo();

	//acciones
	void cargar();
	void editar();
	void mostrar();	
	int ingresarNivel();
};