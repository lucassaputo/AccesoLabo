#pragma once
#include <string>
#include "Fecha.h"

class Fecha {

private:
    int _dia, _mes, _anio;
    int _diaSemana;

public:
    //constructores
    Fecha();
    Fecha(int dia, int mes, int anio);
    //sets
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    //gets
    int getDia();
    int getMes();
    int getAnio();
    std::string getNombreDia();
    //acciones
    bool ingresarFecha();
    bool cargar(int dia, int mes, int  anio);
    std::string toString();
    bool operator>(Fecha& fechaActual);
    bool operator>=(Fecha& fechaActual);
    bool operator<(Fecha& fechaActual);
    bool operator<=(Fecha& fechaActual);
    bool operator==(Fecha& fechaActual);
};
