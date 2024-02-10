#pragma once
#include "ArchivoUnidad.h"

class AbmUnidadesManager {
private:
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
public:
	void Alta();
	void Baja();
	void Editar();
};