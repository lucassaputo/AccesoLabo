#pragma once
#include "Autorizacion.h"
#include <string>

class ArchivoAutorizacion {
public:
    ArchivoAutorizacion(std::string nombreArchivo);
    bool Guardar(Autorizacion reg);
    bool Guardar(Autorizacion reg, int nroRegistro);
    int ContarRegistros();
    Autorizacion Leer(int nroRegistro);
    int Buscar(int dni);

private:
    std::string _nombreArchivo;
};