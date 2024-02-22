#pragma once
#include "ArchivoAutorizacion.h"
#include "ArchivoProveedores.h"
#include "ArchivoPersona.h"
#include "ArchivoResidente.h"
#include "ArchivoUnidad.h"
#include "ArchivoRegistro.h"
#include "FuncionesGlobales.h"

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
	ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizaciones.dat");
	ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
	ArchivoResidente _archivoResidente = ArchivoResidente("Residentes.dat");
	ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");



};


