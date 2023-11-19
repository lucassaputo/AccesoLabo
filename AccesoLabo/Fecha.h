#pragma once
#include <string>
#include "Fecha.h"

class Fecha {
public:
    int getDia();
    int getMes();
    int getAnio();
    std::string getNombreDia();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void cargar(int dia, int mes, int  anio);
    Fecha();
    Fecha(int dia, int mes, int anio);
    std::string toString();
    bool operator>(Fecha& fechaActual);

private:
    int _dia, _mes, _anio;
    int _diaSemana;
};
