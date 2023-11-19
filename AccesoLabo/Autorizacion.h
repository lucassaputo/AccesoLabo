#pragma once
#include <iostream>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"
class Autorizacion
{
private:
	int _id;
	int _idPersona;
	int _idUnidad;
	FechaHorario _hasta;
	bool _estado;
public:
	//sets
	void setId(int id);
	void  setIdPersona(int id); 
	void  setIdUnidad(int u);
	void  setHasta(FechaHorario f);
	void setEstado(bool e);
	
	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	FechaHorario getHasta();
	bool getEstado();
	
	//acciones
	void cargar();
	void mostrar();
};
