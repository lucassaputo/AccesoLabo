#pragma once
#include "ArchivoAutorizacion.h"
#include "ArchivoProveedores.h"
#include "ArchivoResidente.h"
#include "ArchivoUnidad.h"
#include "ArchivoRegistro.h"

class ConsultasManager{
public:
	void ConsultaAutorizadosxUnidad(); // punto 1
	void ConsultaAutorizadosxApellido(); // punto 2
	void ConsultaResidentesxUnidad(); // punto 3
	void ConsultaResidentesxApellido(); // punto 4
	void ConsultaProveedoresxRazonSocial(); // punto 5
	void ConsultaProveedoresxCUIT(); // punto 6
	void ConsultaUnidadesxNombre(); // punto 7

private:
	ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizados.dat");
	ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");




};


