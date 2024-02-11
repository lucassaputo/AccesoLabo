#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Residente.h"
#include <iostream>
#include "FuncionesGlobales.h"
using namespace std;

void Residente::setUnidad(int unidad) { _unidad = unidad; }
void Residente::setFechaIngreso(Fecha f) { _fechaIngreso = f; }
void Residente::setPropietarioInquilino(bool es) { _propietario_inquilino = es; }

int Residente::getUnidad() const { return _unidad;}
Fecha Residente::getFechaIngreso() { return _fechaIngreso;}
bool Residente::getPropietarioInquilino() const { return _propietario_inquilino;}

void Residente::cargarResidente() {
    cargarPersona();
    setUnidad(ingresarUnidad("de residencia").getId());
    bool propie;
    Fecha aux;
    Fecha hoy;
    cout << "Ingrese fecha de ingreso (DD/MM/AA): ";
    while (true) {
        while (aux.ingresarFecha() == false) {
            cout << "Formato invalido, ingrese DD/MM/AA";
            cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
        }
        if (aux > hoy) {
            cout << "La fecha ingresada debe ser menor a hoy. Ingrese fecha: " << endl;
        }
        else {
            cout << "OKFecha" << endl;
            break;
        }
    }
    setFechaIngreso(aux);

    cout << "Ingrese 1 si es Residente , Ingrese 0 si es Inquilino: ";
    cin >> propie;
    setPropietarioInquilino(propie);
}

void Residente::editarResidente() {
    bool propie;
    Fecha aux;
    Fecha hoy;
    editarPersona();
    cout << "Unidad actual: " << _unidad << endl;
    setUnidad(stoi(ingresarIdUnidad()));
    cout << "Fecha de ingreso actual: " << _fechaIngreso.toString() << endl;
    cout << "Ingrese fecha de ingreso (DD/MM/AA): ";
    while (true) {
        while (aux.ingresarFecha() == false) {
            cout << "Formato invalido, ingrese DD/MM/AA";
            cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
        }
        if (aux > hoy) {
            cout << "La fecha ingresada debe ser menor a hoy. Ingrese fecha: ";
        }
        else {
            cout << "OKFecha" << endl;
            break;
        }
    }
    setFechaIngreso(aux);
    cout << "Condicion actual: " << _propietario_inquilino << endl;
    cout << "Ingrese 1 si es Residente , Ingrese 0 si es Inquilino: ";
    cin >> propie;
    setPropietarioInquilino(propie);
}
void Residente::mostrar() {     
    Persona::mostrar();
    cout << "Unidad: " << _unidad << endl;
    cout << "Desde: " << _fechaIngreso.toString() << endl;
    cout << "Propietario/Inquilino: " << _propietario_inquilino << endl;
}

string Residente::mostrarResidentestring() {
    //string retornar = mostrarPersonastring();
   /*  string retornar = "dasdas";

     if (getPropietarioInquilino()) {

         retornar += "Unidad del Residente : " + to_string(getUnidad()) + "\n"
             + " Fecha de Ingreso del Residente : " + getFechaIngreso();
     }
     else {
         retornar += "Unidad del Inquilino : " + to_string(getUnidad()) + "\n"
             + " Fecha de Ingreso del Inquilino : " + getFechaIngreso();
     }
     return retornar;
     */
    return "";
}