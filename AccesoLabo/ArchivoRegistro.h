#pragma once
#include "Registro.h"
#include <string>

class ArchivoRegistro {
public:
    ArchivoRegistro(std::string nombreArchivo);
    bool Guardar(Registro reg);
    bool Guardar(Registro reg, int nroRegistro);
    int ContarRegistros();
    Registro Leer(int nroRegistro);
    int Buscar(int dni);
    bool Modificar(Registro reg);

private:
    std::string _nombreArchivo;
};
