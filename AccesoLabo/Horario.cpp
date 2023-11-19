#include "horario.h"
#include <ctime>

//constructores
Horario::Horario() {
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _segundo = (*f).tm_sec; // Indirecciona f y accede a tm_mday
    _minuto = f->tm_min; // Indirecciona f y accede a tm_mon
    _hora = f->tm_hour;
}
Horario::Horario(int Segundo, int minuto, int hora) {
    setSegundo(Segundo);
    setMinuto(minuto);
    setHora(hora);
}

//sets
void Horario::setSegundo(int segundo) { _segundo = segundo; }
void Horario::setMinuto(int minuto) { _minuto = minuto; }
void Horario::setHora(int hora) { _hora = hora; }
//gets
int Horario::getSegundo() { return _segundo; }
int Horario::getMinuto() { return _minuto; }
int Horario::getHora() { return _hora; }

//acciones
std::string Horario::toString() {
    std::string valorADevolver;
    valorADevolver = std::to_string(_hora) + ":" + std::to_string(_minuto) + ":" + std::to_string(_segundo);
    return valorADevolver;
}
void Horario::cargar(int seg, int minuto, int hora) {
    setSegundo(seg);
    setMinuto(minuto);
    setHora(hora);
}