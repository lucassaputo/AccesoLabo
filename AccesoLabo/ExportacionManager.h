#pragma once
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "ArchivoPersona.h"
#include "ArchivoResidente.h"

class ExportacionManager
{
private:
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");	
	ArchivoUnidad _archivoUnidadesBackup = ArchivoUnidad("UnidadesBackup.dat");
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
	ArchivoProveedores _archivoProveedoresBackup = ArchivoProveedores("ProveedoresBackup.dat");
	ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
	ArchivoPersona _archivoVisitasBackup = ArchivoPersona("VisitasBackup.dat");
	ArchivoResidente _archivoResidentes = ArchivoResidente("Residentes.dat");	
	ArchivoResidente _archivoResidentesBackup = ArchivoResidente("ResidentesBackup.dat");

public:
	void CopiaUnidades();
	void RestaurarUnidades();
	void CopiaProveedores();
	void RestaurarProveedoes();
	void CopiaVisitas();
	void RestaurarVisita();
	void CopiaResidentes();
	void RestaurarResidentes();


	void CopiadeSeguridad();
	void RestaurarCopia();

};

