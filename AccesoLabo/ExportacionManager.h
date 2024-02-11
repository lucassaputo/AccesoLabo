#pragma once
#include "RegistrosManager.h"
class ExportacionManager
{
	/*
		std::cout << "1 - Copia de Seguridad" << std::endl;
	std::cout << "2 - Exportar listado" << std::endl;
	std::cout << "3 - Exportar Consulta" << std::endl;
	*/
public:
	void CopiadeSeguridad();
	void ExportarListado();
	void ExportarConsulta();
private:
	RegistrosManager _manager;
};

