#pragma once
#include "fecha.h"
#include "horario.h"

class FechaHorario {
private:
    Fecha _fecha;
    Horario _horario;
public:
    //constructores
    FechaHorario();
    FechaHorario(Fecha fecha, Horario horario);
    FechaHorario(int dia, int mes, int anio, int segundo, int minuto, int hora);
    //sets
    void setFecha(Fecha fecha);
    void setFecha(int dia, int mes, int anio);
    void setHorario(Horario horario);
    void setHorario(int segundo, int minuto, int hora);
    //gets
    Fecha getFecha();
    Horario getHorario();
    //acciones
    std::string toString();
};
