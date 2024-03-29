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
    int BuscarId(int id);
    Proveedor BuscarObj(int dni);
    Proveedor BuscarObjApellido(std::string apellido);
    bool Modificar(Proveedor reg);
    bool CrearArchivo(Proveedor reg);

private:
    std::string _nombreArchivo;
};