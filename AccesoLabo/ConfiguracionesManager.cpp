#include <iostream>
#include "ConfiguracionesManager.h"
#include "ConfigSingleton.h"

void ConfiguracionesManager::ConfiguracionHorarios()
{
	Configuracion reg;
	ConfigSingleton& config = ConfigSingleton::getInstance();
	//config.setMiClase(reg);
	std::cout << "Configuracion de Horario" << std::endl;
	std::cout << "Ingresos de proveedores permitidos desde: " << config.getConfig().getDesde().toString() << std::endl;
	std::cout << "Ingresos de proveedores permitidos hasta: " << config.getConfig().getHasta().toString() << std::endl;
	std::cout << "Configuracion de Horario" << std::endl;
}
