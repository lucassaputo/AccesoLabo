#pragma once
#include <iostream>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"
class ReporteAutorizaciones
{
private:
	int _idUnidad;
	std::string _nombre;
	std::string _apellido;
	std::string _nombreTipo;
	Fecha _hasta;


public:
	//sets
	void setIdUnidad(int u);
	void setNombre(std::string a);
	void setApellido(std::string a);
	void setNombreTipo(std::string n);
	void setHasta(Fecha f);

	//gets
	int getIdUnidad();
	std::string getNombre();
	std::string getApellido();
	std::string getNombreTipo();
	Fecha getHasta();

	//acciones
	void mostrar();
	void mostrarReporte();
};
