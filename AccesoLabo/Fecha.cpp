#include <ctime>
#include <iostream>
#include "fecha.h"
#include <sstream>

Fecha::Fecha() {
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
    _mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;
}
Fecha::Fecha(int dia, int mes, int anio) {
    cargar(dia, mes, anio);
    _diaSemana = -1;
}
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }
void Fecha::setDia(int dia) { _dia = dia; }
void Fecha::setMes(int mes) { _mes = mes; }
void Fecha::setAnio(int anio) { _anio = anio; }
bool Fecha::cargar(int dia, int mes, int anio) {
    if (dia > 0 && dia < 32 && mes>0 && mes < 13 && anio >0) {
        switch (mes) {
        case 1:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;
        case 2:
            if (dia <= 28 && anio % 4 != 0) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            if (anio % 4 == 0 && dia <= 29) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            return false;
        case 3:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;
        case 4:
            if (dia <= 30) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            return false;
        case 5:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;
        case 6:
            if (dia <= 30) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            return false;
        case 7:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;
        case 8:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;
        case 9:
            if (dia <= 30) {

                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            return false;
        case 10:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;

        case 11:
            if (dia <= 30) {
                _dia = dia;
                _mes = mes;
                _anio = anio;
                return true;
            }
            return false;

        case 12:
            _dia = dia;
            _mes = mes;
            _anio = anio;
            return true;

        default:            
            _dia = 01;
            _mes = 01;
            _anio = 2023;
            return true;
        }
    }
    return false;
}

std::string Fecha::toString() {
    std::string valorADevolver;
    valorADevolver = std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    return valorADevolver;
}
std::string Fecha::getNombreDia() {
    std::string nombres[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    if (_diaSemana >= 0 && _diaSemana <= 6) {
        return nombres[_diaSemana];
    }
    return "";
}

bool Fecha::ingresarFecha() {
    std::string fechaStr;
    // Pedir al usuario que ingrese la fecha
    //std::cout << "Ingrese la fecha (DD/MM/AA): ";
    std::cin >> fechaStr;

    // Crear un objeto stringstream para analizar la cadena
    std::istringstream fechaStream(fechaStr);

    // Variables para almacenar el día, mes y año
    int dia, mes, anio;

    // Extraer los valores de día, mes y año de la cadena
    char delim1, delim2;
    fechaStream >> dia >> delim1 >> mes >> delim2 >> anio;

    // Verificar si el formato es correcto y no hay errores de extracción
    if (fechaStream.fail() || delim1 != '/' || delim2 != '/' || fechaStream.rdbuf()->in_avail() != 0) {
        //std::cerr << "Formato de fecha incorrecto. Asegúrese de que la fecha tenga el formato DD/MM/AA." << std::endl;
        return false; // Salir con código de error
    }
    else {
        if (!(cargar(dia, mes, anio))) {
            return false;
        }
    }
    // Imprimir los valores por separado (puedes hacer lo que necesites con ellos)
   /* std::cout << "Día: " << dia << std::endl;
    std::cout << "Mes: " << mes << std::endl;
    std::cout << "Año: " << ano << std::endl;*/    

    return true; // Salir sin errores
}

bool Fecha::operator>(Fecha& fechaActual)
{
    // MODIFICACION PARA QUE DUEVUELVA TRUE SOLO SI ES MAYOR (DEVOLVIA TRUE SI ERA MAYORT O IGUAL)   
    if (this->getAnio() > fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() > fechaActual.getMes()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() == fechaActual.getMes() && this->getDia() > fechaActual.getDia()) {
        return true;
    }

    return false;   
   
    /*
 if (this->getAnio() > fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio()) {
        if (this->getMes() > fechaActual.getMes()) {
            return true;
        }
        else if (this->getMes() == fechaActual.getMes()) {
            if (this->getDia() >= fechaActual.getDia()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
 */
    
}

bool Fecha::operator>=(Fecha& fechaActual)
{
    if (this->getAnio() > fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() > fechaActual.getMes()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() == fechaActual.getMes() && this->getDia() >= fechaActual.getDia()) {
        return true;
    }

    return false;
}

bool Fecha::operator<(Fecha& fechaActual)
{
    // MODIFICACION PARA QUE DUEVUELVA TRUE SOLO SI ES MENOR (DEVOLVIA TRUE SI ERA MENOR O IGUAL)   
    if (this->getAnio() < fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() < fechaActual.getMes()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() == fechaActual.getMes() && this->getDia() < fechaActual.getDia()) {
        return true;
    }

    return false;
    
    /*
 
    return false;
    if (this->getAnio() > fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio()) {
        if (this->getMes() > fechaActual.getMes()) {
            return true;
        }
        else if (this->getMes() == fechaActual.getMes()) {
            if (this->getDia() >= fechaActual.getDia()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
 */
}

bool Fecha::operator<=(Fecha& fechaActual)
{
    if (this->getAnio() < fechaActual.getAnio()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() < fechaActual.getMes()) {
        return true;
    }
    else if (this->getAnio() == fechaActual.getAnio() && this->getMes() == fechaActual.getMes() && this->getDia() <= fechaActual.getDia()) {
        return true;
    }

    return false;
}

bool Fecha::operator==(Fecha& fechaActual)
{
    if (this->getAnio() == fechaActual.getAnio() && this->getMes() == fechaActual.getMes() && this->getDia() == fechaActual.getDia()) {
        return true;
    }
    else {
        return false;
    }
    }
