#include "App.h"
#include "LogIn.h"
#include "Configuracion.h"
#include "ConfigSingleton.h"
#include "Horario.h"

using namespace std;

void App::Ejecutar() {
	ConfigSingleton& config = ConfigSingleton::getInstance();	
	Configuracion c;
	Horario auxDesde(00, 8, 10);
	Horario auxHasta(00, 18, 11);
	c.setDesde(auxDesde);
	c.setHasta(auxHasta);
	config.setMiClase(c);
	LogIn log;
	log.Mostrar();
}