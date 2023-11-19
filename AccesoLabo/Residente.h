#pragma once
#include <cstring>
#include "Persona.h"


class Residente : public Persona {


public:

    int getUnidad() const;
    std::string getFechaIngreso();
    bool getPropietarioInquilino() const;


    void setUnidad(int unidad);
    void setFechaIngreso(int dia, int mes, int anio);
    void setPropietarioInquilino(bool es);
    void cargarResidente();
    std::string mostrarResidentestring();
    void mostrar();
private:
    int _unidad;
    Fecha _fechaIngreso;
    bool _propietario_inquilino;

};