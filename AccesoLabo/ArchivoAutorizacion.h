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
    int Buscar(int id); // busca por id
    int Buscar(const char* a);
    int BuscarxUnidad(int u); // busca por unidad

private:
    std::string _nombreArchivo;
};