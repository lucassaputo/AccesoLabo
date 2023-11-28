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
	int _tipo; // 1 visita || 2 proveedor
public:
	//sets
	void setId(int id);
	void  setIdPersona(int id); 
	void  setIdUnidad(int u);
	void  setTipo(int t);
	void  setHasta(FechaHorario f);
	void setEstado(bool e);
	
	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	int getTipo();
	FechaHorario getHasta();
	bool getEstado();
	
	//acciones
	void cargar();
	void mostrar();
};
