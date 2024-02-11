#pragma once
#include <iostream>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"
class ReporteAutorizaciones
{
private:
	int _id;
	int _idPersona;
	int _idUnidad;
	int _tipo; // 1 - Visitas || 2 - Proveedor
	Fecha _hasta;
	std::string _apellido;
	std::string _nombreTipo;


public:
	//sets
	void setId(int id);
	void  setIdPersona(int id);
	void  setIdUnidad(int u);
	void  setTipo(int t);
	void  setHasta(Fecha f);
	void setApellido(std::string a);
	void setNombreTipo(std::string n);

	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	int getTipo();
	Fecha getHasta();
	std::string getApellido();
	std::string getNombreTipo();

	//acciones
	void mostrar();
};
