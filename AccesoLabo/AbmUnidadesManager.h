#pragma once
#include "ArchivoUnidad.h"

class AbmUnidadesManager {
public:
	void Alta();
	void Baja();
	void Editar();
	std::string ingresarId();

private:
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
};