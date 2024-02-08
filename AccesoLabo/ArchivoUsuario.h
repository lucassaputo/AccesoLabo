#pragma once
#include "Usuario.h"
class ArchivoUsuario
{

    public:
        ArchivoUsuario(std::string nombreArchivo);
        bool Guardar(Usuario reg);
        bool Guardar(Usuario reg, int nroRegistro);
        int ContarRegistros();
        Usuario Leer(int nroRegistro);
        int Buscar(int legajo);
        bool ListarUsuarios();
        Usuario BuscarObj(int id);
        int BuscarPos(int id);
        bool Modificar(Usuario reg);
    private:
        std::string _nombreArchivo;
};

