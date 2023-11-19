#pragma once

#include <cstring>
#include "Persona.h"
class Empleado :public Persona {
public:
    void setTipo(char tipo);
    void setCategoria(char categoria);
    void setLegajo(int legajo);
    void setDescripcion(const std::string descripcion);
    char getTipo() const;
    char getCategoria() const;
    int getLegajo() const;
    std::string getDescripcion() const;
    void CargarEmpleado();
    std::string MostrarEmpleadostring();
    void mostrar();
private:
    char _tipo;
    char _categoria;
    int _legajo;
    char _descripcion[100];
};