#pragma once
#include "ArchivoAutorizacion.h"

class AbmPersonasManager {
public:
	void AltaProveedor();
	void AltaVisita();
	void AltaResidente();

private:
	ArchivoAutorizacion _archivo = ArchivoAutorizacion("Autorizados.dat");
};