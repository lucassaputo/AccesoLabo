#pragma once
#include <iostream>
#include "Unidad.h"
class ArchivoUnidad
{
private:
	std::string _nombreArchivo;
public:
	ArchivoUnidad(std::string nombreArchivo);
	int Buscar(int id);
	Unidad Leer(int nroRegistro);
	int ContarRegistros();
	bool Guardar(Unidad reg);
};
