#include <iostream>
#include "ConfiguracionesManager.h"
#include "ConfigSingleton.h"
#include "FuncionesGlobales.h"


void ConfiguracionesManager::ConsultaHorarios()
{
	system("cls");
	ConfigSingleton& config = ConfigSingleton::getInstance();
	system("cls");
	std::cout << "CONSULTA DE HORARIOS PROVEEDORES" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Ingresos de proveedores permitidos desde: " << config.getConfig().getDesde().toString() << std::endl;
	std::cout << "Ingresos de proveedores permitidos hasta: " << config.getConfig().getHasta().toString() << std::endl;
	system("pause");
}

void ConfiguracionesManager::ConfiguracionHorarios()
{
	system("cls");
	ConfigSingleton& config = ConfigSingleton::getInstance();
	
	system("cls");
	std::cout << "MODIFICACION DE HORARIOS PROVEEDORES" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++" << std::endl;

	config.getConfig().setDesde(ingresarHorario("desde"));
	config.getConfig().setHasta(ingresarHorario("hasta"));

	if (_archivoConfiguraciones.Modificar(config.getConfig())) {
		std::cout << "Registro editado correctamente." << std::endl;
	}
	else {
		std::cout << "Error al guardar." << std::endl;
	}


	system("pause");
}

void ConfiguracionesManager::CantidadUnidades() {
	ConfigSingleton& config = ConfigSingleton::getInstance();
	Configuracion c = config.getConfig();
	int x = c.getCantUnidades();
	system("cls");
	std::cout << "CANTIDAD DE UNIDADES" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Cantidad maxima de unidades/lotes: " << x << std::endl;
	system("pause");
}