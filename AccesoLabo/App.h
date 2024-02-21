#pragma once
#include "ArchivoConfiguraciones.h"
class App
{
	public:
		void Ejecutar();
	private:
		ArchivoConfiguraciones _archivoConfiguracion = ArchivoConfiguraciones("Configuraciones.dat");
};

