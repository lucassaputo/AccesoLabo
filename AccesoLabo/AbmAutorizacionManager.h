#pragma once
#include "ArchivoAutorizacion.h"
class AbmAutorizacionManager
{
public:
	void Alta();
	void Baja();
	void Editar();

private:
	ArchivoAutorizacion _archivo = ArchivoAutorizacion("Autorizados.dat");
};

