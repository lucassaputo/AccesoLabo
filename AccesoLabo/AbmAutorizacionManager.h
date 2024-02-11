#pragma once
#include "ArchivoAutorizacion.h"
#include "ArchivoPersona.h"
#include "ArchivoProveedores.h"
class AbmAutorizacionManager
{
public:
	void Alta();
	void Baja();
	void Editar();
	void altaAutorizacion(int idPersona, int motivo, int unidad);
	void editarAutorizacion(int idPersona, int motivo, int unidad);
	void bajaAutorizacion(int idPersona, int motivo, int unidad);

private:
	ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizaciones.dat");
	ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
};

