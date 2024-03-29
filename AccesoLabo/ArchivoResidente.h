#pragma once
#include "Residente.h"
class ArchivoResidente
{
    public:
        ArchivoResidente(std::string nombreArchivo);
        bool Guardar(Residente reg);
        bool Guardar(Residente reg, int nroRegistro);
        int ContarRegistros();
        Residente Leer(int nroRegistro);
        int Buscar(int dni);
        Residente BuscarObj(int dni);
        bool Modificar(Residente reg);

    private:
        std::string _nombreArchivo;
   


};

