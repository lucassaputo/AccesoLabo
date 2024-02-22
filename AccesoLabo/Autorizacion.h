#pragma once
#include <iostream>
#include <iomanip>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"
class Autorizacion
{
private:
	int _id;
	int _idPersona;
	int _idUnidad;
	int _tipo; // 1 - Visitas || 2 - Proveedor
	Fecha _hasta;
	bool _estado;
public:
	//sets
	void setId(int id);
	void  setIdPersona(int id); 
	void  setIdUnidad(int u);
	void  setTipo(int t);
	void  setHasta(Fecha f);
	void setEstado(bool e);
	
	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	int getTipo();
	Fecha getHasta();
	bool getEstado();
	
	//acciones
	void cargar();
	void mostrar();
};
