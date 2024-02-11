#pragma once
#include "ArchivoUsuario.h"

class LogIn
{ 
private:
	ArchivoUsuario _archivoUsuario = ArchivoUsuario("Usuario.dat");
public:
	void Mostrar();
};


