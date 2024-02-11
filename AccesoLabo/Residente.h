#pragma once
#include <cstring>
#include "Persona.h"

class Residente : public Persona {
private:
    int _unidad;
    Fecha _fechaIngreso;
    bool _propietario_inquilino;

public:
    void setUnidad(int unidad);
    void setFechaIngreso(Fecha f);
    void setPropietarioInquilino(bool es);

    int getUnidad() const;
    Fecha getFechaIngreso();
    bool getPropietarioInquilino() const;
    
    void cargarResidente();
    void editarResidente();
    std::string mostrarResidentestring();
    void mostrar();
};