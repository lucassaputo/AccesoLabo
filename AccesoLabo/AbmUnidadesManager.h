#pragma once
#include "ArchivoUnidad.h"

class AbmUnidadesManager {
public:
	void Alta();
	void Baja();
	void Editar();

private:
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
};