#pragma once
#include "ArchivoAutorizacion.h"

class ConsultasManager{
public:
	void ConsultaAutorizadosxUnidad();
	void ConsultaAutorizadosxApellido();
	void ConsultaResidentesxUnidad();
	void ConsultaResidentesxApellido();
	void ConsultaProveedoresxRazonSocial();
	void ConsultaProveedoresxCuit();
	void ConsultaUnidadesxNombre();

private:
	ArchivoAutorizacion _archivo = ArchivoAutorizacion("Autorizados.dat");
};


