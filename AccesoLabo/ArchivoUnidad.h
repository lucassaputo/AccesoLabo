#pragma once
#include <iostream>
#include "Unidad.h"
class ArchivoUnidad
{
private:
	std::string _nombreArchivo;
public:
	ArchivoUnidad(std::string nombreArchivo);
	int BuscarPos(int id);
	Unidad BuscarObj(int id);
	Unidad Leer(int nroRegistro);
	int ContarRegistros();
	bool CrearArchivo(Unidad reg);
	bool Guardar(Unidad reg);
	bool Guardar(Unidad reg, int pos);
	bool Modificar(Unidad reg);
};
