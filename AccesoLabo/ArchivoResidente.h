#pragma once
#include <iostream>
#include "Residente.h"
#include <cstring>
class ArchivoResidente
{
public:
    ArchivoResidente(std::string nombreArchivo);
    bool Guardar(Residente reg);
    bool Guardar(Residente reg, int nroRegistro);
    int ContarRegistros();
    Residente Leer(int nroRegistro);
    int Buscar(int dni);

private:
    std::string _nombreArchivo;
};

