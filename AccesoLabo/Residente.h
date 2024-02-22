#pragma once
#include <cstring>
#include "Persona.h"

class Residente : public Persona {
private:
    int _unidad;
    Fecha _fechaIngreso;
    Fecha _fechaHasta;
    bool _propietario_inquilino;

public:
    void setUnidad(int unidad);
    void setFechaIngreso(Fecha f);
    void setFechaHasta(Fecha f);
    void setPropietarioInquilino(bool es);

    int getUnidad() const;
    Fecha getFechaIngreso();
    Fecha getFechaHasta();
    bool getPropietarioInquilino() const;
    
    void cargarResidente();
    void editarResidente();
    //std::string mostrarResidentestring();
    void mostrar();
};