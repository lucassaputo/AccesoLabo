#pragma once
#include "Configuracion.h"
#include <string>
class ArchivoConfiguraciones
{
private:
    std::string _nombreArchivo;
public:
    ArchivoConfiguraciones(std::string nombreArchivo);
    bool Guardar(Configuracion reg);
    bool Guardar(Configuracion reg, int nroRegistro);
    int ContarRegistros();
    Configuracion Leer(int nroRegistro);
    int Buscar(int dni);
    bool Modificar(Configuracion reg);
};

