#include<iostream>
#include "Fecha_horario.h"
#include "Fecha.h"
#include "Horario.h"

using namespace std;

FechaHorario::FechaHorario()
{
    _fecha = Fecha();
    _horario = Horario();
}

FechaHorario::FechaHorario(int seg, int minuto, int hora, int dia, int mes, int anio) {
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    _horario.setSegundo(seg);
    _horario.setMinuto(minuto);
    _horario.setHora(hora);
}

FechaHorario::FechaHorario(Fecha fecha, Horario horario) {
    setHorario(horario);
    setFecha(fecha);
}
//sets
void FechaHorario::setFecha(Fecha fecha) {
    _fecha.setDia(fecha.getDia());
    _fecha.setMes(fecha.getMes());
    _fecha.setAnio(fecha.getAnio());
}

void FechaHorario::setHorario(Horario horario) {
    _horario.cargar(horario.getSegundo(), horario.getMinuto(), horario.getHora());
}
//gets
Fecha FechaHorario::getFecha() { return _fecha; }
Horario FechaHorario::getHorario() { return _horario; }

//acciones
std::string FechaHorario::toString() {
    string fecha, horario, devolver;

    fecha = _fecha.toString();
    horario = _horario.toString();
    devolver = "LA FECHA ES " + fecha + "  Y LA HORA ES : " + horario;
    return devolver;

}

void FechaHorario::setFecha(int dia, int mes, int anio) {
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}

void FechaHorario::setHorario(int seg, int minuto, int hora) {
    _horario = Horario(seg, minuto, hora);
}


