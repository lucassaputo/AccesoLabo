#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Residente.h"
#include <iostream>
using namespace std;


int Residente::getUnidad() const {
    return _unidad;
}

string Residente::getFechaIngreso() {
    string retornar = _fechaIngreso.toString();
    return retornar;
}

bool Residente::getPropietarioInquilino() const {
    return _propietario_inquilino;
}


void Residente::setUnidad(int unidad) {
    _unidad = unidad;
}

void Residente::setFechaIngreso(int dia, int mes, int anio) {
    _fechaIngreso.cargar(dia, mes, anio);
}

void Residente::setPropietarioInquilino(bool es) {
    _propietario_inquilino = es;
}

void Residente::cargarResidente() {
    cargarPersona();
    int unidad;
    int dia, mes, anio;
    bool propie;
    cout << "Ingrese Unidad correspondiente : " << endl;
    cin >> unidad;
    setUnidad(unidad);
    cout << "Ingrese dia de Ingreso : " << endl;
    cin >> dia;
    cout << "Ingrese mes de Ingreso : " << endl;
    cin >> mes;
    cout << "Ingrese anio de Ingreso  : " << endl;
    cin >> anio;

    setFechaIngreso(dia, mes, anio);

    cout << "Ingrese 1 si es Residente , Ingrese 0 si es Inquilino " << endl;
    cin >> propie;

    setPropietarioInquilino(propie);


}
string Residente::mostrarResidentestring() {
    //string retornar = mostrarPersonastring();
    string retornar = "dasdas";

    if (getPropietarioInquilino()) {

        retornar += "Unidad del Residente : " + to_string(getUnidad()) + "\n"
            + " Fecha de Ingreso del Residente : " + getFechaIngreso();
    }
    else {
        retornar += "Unidad del Inquilino : " + to_string(getUnidad()) + "\n"
            + " Fecha de Ingreso del Inquilino : " + getFechaIngreso();


    }
    return retornar;

}
void Residente::mostrar() {
     
   // mostrarPersona();

    if (getPropietarioInquilino()) {

        cout << "Unidad del Residente : " << to_string(getUnidad()) << endl;
        cout <<  " Fecha de Ingreso del Residente : " << getFechaIngreso() << endl;
    }
    else {
        cout << "Unidad del Inquilino : " << to_string(getUnidad()) << endl;
        cout << "Fecha de Ingreso del Inquilino : " << getFechaIngreso() << endl;


    }

    
}