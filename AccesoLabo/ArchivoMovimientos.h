#pragma once
#include "Movimiento.h"
#include <string>

class ArchivoMovimientos {
public:
    int Buscar(int dni);
        Movimiento Leer(int nroRegistro);
        int ContarRegistros();
        bool Guardar(Movimiento reg);
        ArchivoMovimientos(std::string nombreArchivo);
private:
    std::string _nombreArchivo;
};
