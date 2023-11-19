#pragma once
#include <iostream>
#include "Persona.h"
#include "Unidad.h"
#include "Fecha.h"

class Movimiento
{
private:
	/*
	int _idUnidad;
	int _idPersona;
		LA CLASE MOVIMIENTOS DEBE TENER SOLO: 
											SENTIDO
											ID PERSONA
											ID UNIDAD
											FECHA
											MOTIVO 
											ESTADO

	*/
	Unidad _unidad;
	Persona _persona;
	Fecha _fecha;
	int _sentido;
	std::string _observaciones, _tipoAutorizacion;
	bool _estado;
public:
	Persona getPersona();
	Unidad getUnidad();
	Fecha getFecha();
	int getSentido();
	std::string getObservaciones();
	std::string getTipoAutorizacion();
	bool getEstado();
	void setPersona(Persona p);
	void setUnidad(Unidad u);
	void setFecha(Fecha f);
	void setSentido(int s);
	void setObservaciones(std::string obs);
	void setTipoAutorizacion(std::string aut);
	void setEstado(bool e);
	void cargar();
	void mostrar();
};


