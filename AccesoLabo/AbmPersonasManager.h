#pragma once
#include "ArchivoAutorizacion.h"
#include "ArchivoProveedores.h"
#include "ArchivoPersona.h"
#include "ArchivoResidente.h"

class AbmPersonasManager {
public:
	void AltaProveedor();
	void EditarProveedor();
	void BajaProveedor();
	void AltaVisita();
	void EditarVisita();
	void BajaVisita();
	void AltaResidente();
	void EditarResidente();
	void BajaResidente();

private:
	ArchivoAutorizacion _archivo = ArchivoAutorizacion("Autorizados.dat");
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
	ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
	ArchivoResidente _archivoResidentes = ArchivoResidente("Residentes.dat");
};