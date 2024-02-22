#pragma once
#include <iostream>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"

class ReporteRegistro
{
private:
	int _idUnidad;
	std::string _nombre;
	std::string _apellido;
	int _dni;
	std::string _nombreTipo;
	FechaHorario _fechaIngreso;
	FechaHorario _fechaEgreso;

public:
	//sets
	void setIdUnidad(int u);
	void setNombre(std::string a);
	void setApellido(std::string a);
	void setDni(int d);
	void setNombreTipo(std::string n);
	void setFechaIngreso(FechaHorario f);
	void setFechaEgreso(FechaHorario f);

	//gets
	int getIdUnidad();
	std::string getNombre();
	std::string getApellido();
	int getDni();
	std::string getNombreTipo();
	FechaHorario getFechaIngreso();
	FechaHorario getFechaEgreso();

	//acciones
	void mostrar();
	void mostrarReporte();
};

