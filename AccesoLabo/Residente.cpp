#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Residente.h"
#include <iostream>
#include "FuncionesGlobales.h"
using namespace std;

void Residente::setUnidad(int unidad) { _unidad = unidad; }
void Residente::setFechaIngreso(Fecha f) { _fechaIngreso = f; }
void Residente::setFechaHasta(Fecha f) { _fechaHasta = f; }
void Residente::setPropietarioInquilino(bool es) { _propietario_inquilino = es; }

int Residente::getUnidad() const { return _unidad;}
Fecha Residente::getFechaIngreso() { return _fechaIngreso;}
Fecha Residente::getFechaHasta() { return _fechaHasta; }
bool Residente::getPropietarioInquilino() const { return _propietario_inquilino;}

void Residente::cargarResidente() {
    cargarPersona();
    setUnidad(ingresarUnidad("de residencia").getId());
    bool propie;
    
    propie = ingresarPropInq();
    setPropietarioInquilino(propie);  
    //system("pause");
    setFechaIngreso(ingresarFechaIngreso());
    if (!propie) {
        setFechaHasta(ingresarFechaHasta());
    }
    else {
        Fecha auxHasta;
        auxHasta.setAnio(2000);
        auxHasta.setMes(1);
        auxHasta.setDia(1);
        setFechaHasta(auxHasta);
    }
}

void Residente::editarResidente() {
    bool propie;
    string prop = "";
    editarPersona();
    cout << "Unidad actual: " << _unidad << endl;
    setUnidad(stoi(ingresarIdUnidad()));
    if (_propietario_inquilino) {
        prop = "Propietario";
    }
    else {
        prop = "Inquilino";
    }
    cout << "Condicion actual: " << prop << endl;
    
    propie = ingresarPropInq();
    setPropietarioInquilino(propie);

    cout << "Fecha de ingreso actual: " << _fechaIngreso.toString() << endl;    
    setFechaIngreso(ingresarFechaIngreso());
    if (!propie) {
        setFechaHasta(ingresarFechaHasta());
    }
    else {
        Fecha auxHasta;
        auxHasta.setAnio(2000);
        auxHasta.setMes(1);
        auxHasta.setDia(1);
        setFechaHasta(auxHasta);
    }
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