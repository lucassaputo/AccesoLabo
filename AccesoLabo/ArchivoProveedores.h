#pragma once
#include "Proveedor.h"
#include <string>

class ArchivoProveedores {
public:
    ArchivoProveedores(std::string nombreArchivo);
    bool Guardar(Proveedor reg);
    bool Guardar(Proveedor reg, int nroRegistro);
    int ContarRegistros();
    Proveedor Leer(int nroRegistro);
    int Buscar(int dni);
    Proveedor BuscarObj(int dni);
    bool Modificar(Proveedor reg);

private:
    std::string _nombreArchivo;
};