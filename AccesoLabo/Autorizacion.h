#pragma once
#include <iostream>
#include "Unidad.h"
#include "Fecha_horario.h"
#include "Proveedor.h"
class Autorizacion
{
private:
	int _id;
	int _idPersona; // ver si lo sacamos y dejamos solo DNI
	int _idUnidad;
	int _tipo; // 1 - Visitas || 2 - Proveedor
	int _dni;
	Fecha _hasta;
	bool _estado;
public:
	//sets
	void setId(int id);
	void  setIdPersona(int id); 
	void  setIdUnidad(int u);
	void  setTipo(int t);
	void  setDNI(int dni);
	void  setHasta(Fecha f);
	void setEstado(bool e);
	
	//gets
	int getId();
	int getIdPersona();
	int getIdUnidad();
	int getTipo();
	int getDNI();
	Fecha getHasta();
	bool getEstado();
	
	//acciones
	void cargar();
	void mostrar();
};
