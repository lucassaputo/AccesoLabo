#pragma once
#include <iostream>
#include <string>

class Unidad {
private:
	int _id, _telefono;
	char _familia[50];
	char _observaciones[50];
	bool _estado;

public:
	Unidad();
	//sets
	void setId(int id);
	void setTelefono(int tel);	
	void setFamilia(std::string fam);
	void setObservaciones(std::string obs);
	void setEstado(bool estado);
	//gets
	int getId();
	int getTelefono();
	std::string getFamilia();
	std::string getObservaciones();
	bool getEstado();

	//acciones
	void cargar();
	void editar();
	void mostrar();
};




