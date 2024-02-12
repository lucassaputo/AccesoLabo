#pragma once
#include "ArchivoUnidad.h"

class ExportacionManager
{
private:
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
	ArchivoUnidad _archivoUnidadesBackup = ArchivoUnidad("UnidadesBackup.dat");

public:
	void CopiadeSeguridad();
	void RestaurarCopia();

};

