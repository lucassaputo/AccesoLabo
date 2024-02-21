#include "horario.h"
#include <ctime>
#include <sstream>
#include <iostream>

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
//void Horario::cargar(int seg, int minuto, int hora) {
//    setSegundo(seg);
//    setMinuto(minuto);
//    setHora(hora);
//}
bool Horario::cargar(int seg, int minuto, int hora) {
    if (seg > -1 && seg < 61 && minuto>-1 && minuto < 61 && hora >-1 && hora<25) {
        _segundo = seg;
        _minuto = minuto;
        _hora = hora;
        return true;
    }
    return false;
}
bool Horario::ingresarHorario() {
    std::string horarioStr;
    // Pedir al usuario que ingrese la fecha
    std::cout << "Ingrese horario (HH:mm): ";
    std::cin >> horarioStr;

    // Crear un objeto stringstream para analizar la cadena
    std::istringstream horarioStream(horarioStr);

    // Variables para almacenar el día, mes y año
    int min, hora;

    // Extraer los valores de día, mes y año de la cadena
    char delim1;
    horarioStream >> hora >> delim1 >> min;

    // Verificar si el formato es correcto y no hay errores de extracción
    if (horarioStream.fail() || delim1 != ':' || horarioStream.rdbuf()->in_avail() != 0) {
        std::cerr << "Formato de horario incorrecto. Asegúrese de que el horario tenga el formato HH:mm." << std::endl;
        return false;
    }
    else {
        if (!(cargar(0,min,hora))) {
            return false;
        }
    }
    return true;
}