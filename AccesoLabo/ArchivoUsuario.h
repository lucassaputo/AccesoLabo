#pragma once
#include "Usuario.h"
class ArchivoUsuario
{

    public:
        ArchivoUsuario(std::string nombreArchivo);
        bool Guardar(Usuario reg);
        int ContarRegistros();
        Usuario Leer(int nroRegistro);
        int Buscar(int legajo);
        bool ListarUsuarios();

    private:
        std::string _nombreArchivo;

};

