#pragma once
#include "ArchivoConfiguraciones.h"
class ConfiguracionesManager
{
	private:
		ArchivoConfiguraciones _archivoConfiguraciones = ArchivoConfiguraciones("Configuraciones.dat");
	public:
		void ConsultaHorarios();
		void ConfiguracionHorarios();
		void CantidadUnidades();
		void ModificarCantUnidades();
};

