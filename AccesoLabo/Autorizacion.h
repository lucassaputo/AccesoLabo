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
	Fecha _hasta;
	bool _estado;
public:
	//sets
	void setId(int id);
	void  setIdPersona(int id); 
	void  setIdUnidad(int u);
	void  setHasta(Fecha f);
	void setEstado(bool e);
	
	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	Fecha getHasta();
	bool getEstado();
	
	//acciones
	void cargar();
	void mostrar();
};
