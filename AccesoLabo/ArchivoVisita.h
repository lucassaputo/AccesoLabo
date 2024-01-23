#pragma once
#include "Visita.h"
class ArchivoVisita
{
public:
	ArchivoVisita(std::string nombreArchivo);
    bool Guardar(Visita reg);
    bool Guardar(Visita reg, int nroRegistro);
    int ContarRegistros();
    Visita Leer(int nroRegistro);
    int Buscar(int dni);
    int Buscar(const char* a);
    int BuscarxID(int id);

private:
	std::string _nombreArchivo;
};

