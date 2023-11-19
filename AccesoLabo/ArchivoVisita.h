#pragma once
#include "Visita.h"
class ArchivoVisita
{
public:
	ArchivoVisita();
    bool Guardar(Visita reg);
    bool Guardar(Visita reg, int nroRegistro);
    int ContarRegistros();
    Visita Leer(int nroRegistro);
    int Buscar(int dni);

private:
	char _nombre[30];
};

