#pragma once
#include "ArchivoAutorizacion.h"

class ConsultasManager{
public:
	void ConsultaAutorizados();
	void ConsultaResidentes();
	void ConsultaProveedores();
	void ConsultaEmpleados();
	void ConsultaUnidades();

private:
	ArchivoAutorizacion _archivo = ArchivoAutorizacion("Autorizados.dat");
};


