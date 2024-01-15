#pragma once
#include "ArchivoUsuario.h"
#include "Usuario.h"
class UsuarioManager
{
private:
	ArchivoUsuario _archivoUsuario = ArchivoUsuario("Usuario.dat");
public:
	void Cargar();
	void Editar();
	void Eliminar();	
};