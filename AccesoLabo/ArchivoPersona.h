#pragma once
#include "Persona.h"
#include <string>

class ArchivoPersona {
public:
    ArchivoPersona(std::string nombreArchivo);
    bool Guardar(Persona reg);
    bool Guardar(Persona reg, int nroRegistro);
    int ContarRegistros();
    Persona Leer(int nroRegistro);
    int Buscar(int dni);
    int BuscarId(int id);
    Persona BuscarObj(int dni);
    Persona BuscarObjApellido(std::string apellido);
    bool Modificar(Persona reg);

private:
    std::string _nombreArchivo;
};