#include <iostream>
#include<cstdio>
using namespace std;
#include <string>
#include "App.h"
#include "UserSingleton.h"
#include "ConfigSingleton.h"

// Inicializaci�n est�tica de la instancia como nullptr
UserSingleton* UserSingleton::instance = nullptr;
ConfigSingleton* ConfigSingleton::instance = nullptr;

int main() {	
	App app;
	app.Ejecutar();

	return 0;
}


