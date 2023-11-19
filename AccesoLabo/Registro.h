#pragma once
#include <iostream>
#include "Fecha.h"
#include "Proveedor.h"
class Registro
{
private:
	int _idUnidad;
	int _idPersona;
	Fecha _fecha;
	int _sentido;
	char _observaciones[50];
	int _tipoAutorizacion;
	int _idUser;
	bool _estado;

public:
	Registro();
	Registro(int idPersona, int idUnidad, Fecha fecha, int sentido, std::string observacion, int tipoAutorizacion);
	
	//sets
	void setIdUnidad(int u);
	void setIdPersona(int p);
	void setFecha(Fecha f);
	void setSentido(int s);
	void setObservaciones(std::string obs);
	void setTipoAutorizacion(int aut);
	void setIdUser(int id);
	void setEstado(bool e);

	//gets
	int getIdUnidad();
	int getIdPersona();
	Fecha getFecha();
	int getSentido();
	std::string getObservaciones();
	int getTipoAutorizacion();
	int getIdUser();
	bool getEstado();
	
	//acciones
	void mostrar();
	void operator=(Proveedor p);
};


