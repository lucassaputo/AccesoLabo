#pragma once
#include <iostream>
#include <string>

class Unidad {
private:
	int _id;
	char _telefono[12];
	char _familia[51];
	char _observaciones[151];
	bool _estado;

public:
	Unidad();
	//sets
	void setId(int id);
	void setTelefono(std::string tel);	
	void setFamilia(std::string fam);
	void setObservaciones(std::string obs);
	void setEstado(bool estado);
	//gets
	int getId();
	std::string getTelefono();
	std::string getFamilia();
	std::string getObservaciones();
	bool getEstado();

	//acciones
	void cargar();
	void editar();
	void mostrar();
};




