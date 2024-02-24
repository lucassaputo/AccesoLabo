#include "App.h"
#include "LogIn.h"
#include "Configuracion.h"
#include "ConfigSingleton.h"
#include "Horario.h"
#include <iostream>

using namespace std;

void App::Ejecutar() {
	ConfigSingleton& config = ConfigSingleton::getInstance();	
	
	Configuracion c;
	c = _archivoConfiguracion.Leer(0);
	config.setMiClase(c);

	//Configuracion c;
	//Horario auxDesde(0, 0, 8);
	//Horario auxHasta(0, 0, 17);
	//c.setId(1);
	//c.setDesde(auxDesde);
	//c.setHasta(auxHasta);
	//c.setCantUnidades(30);

	//if (_archivoConfiguracion.Guardar(c)) {
	//	std::cout << "Registro editado correctamente." << std::endl;
	//}
	//else {
	//	std::cout << "Error al guardar." << std::endl;
	//}

	LogIn log;
	log.Mostrar();
}