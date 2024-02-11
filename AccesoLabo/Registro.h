#pragma once
#include <iostream>
#include "Fecha.h"
#include "Proveedor.h"
#include "Fecha_horario.h"
class Registro
{
private:
	int _id;
	int _idUnidad;
	int _idPersona;
	int _tipoPersona;
	FechaHorario _fechaIngreso;
	FechaHorario _fechaEgreso;
	bool _adentro;
	char _observaciones[50];
	int _tipoAutorizacion;
	int _idUser;
	bool _estado;

public:
	Registro();
	Registro(int idPersona, int idUnidad, Fecha fecha, int sentido, std::string observacion, int tipoAutorizacion);
	
	//sets
	void setId(int u);
	void setIdUnidad(int u);
	void setIdPersona(int p);
	void setTipoPersona(int t);
	void setFechaIngreso(FechaHorario f);
	void setFechaEgreso(FechaHorario f);
	void setAdentro(bool a);
	void setObservaciones(std::string obs);
	void setTipoAutorizacion(int aut);
	void setIdUser(int id);
	void setEstado(bool e);

	//gets
	int getId();
	int getIdUnidad();
	int getIdPersona();
	int getTipoPersona();
	FechaHorario getFechaIngreso();
	FechaHorario getFechaEgreso();
	bool getAdentro();
	std::string getObservaciones();
	int getTipoAutorizacion();
	int getIdUser();
	bool getEstado();
	
	//acciones
	void mostrar();
	void operator=(Proveedor p);
	void operator=(Persona p);
};


