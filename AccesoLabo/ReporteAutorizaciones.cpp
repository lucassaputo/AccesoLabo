#include "ReporteAutorizaciones.h"

using namespace std;
//sets
void ReporteAutorizaciones::setId(int id) { _id = id; }
void ReporteAutorizaciones::setIdPersona(int id) { _idPersona = id; }
void ReporteAutorizaciones::setIdUnidad(int u) { _idUnidad = u; }
void ReporteAutorizaciones::setTipo(int t) { _tipo = t; }
void ReporteAutorizaciones::setHasta(Fecha f) { _hasta = f; }
void ReporteAutorizaciones::setNombre(std::string a) { _nombre = a; }
void ReporteAutorizaciones::setApellido(std::string a) { _apellido = a; }
void ReporteAutorizaciones::setNombreTipo(std::string n) { _nombreTipo = n; }
//gets
int ReporteAutorizaciones::getId() { return _id; }
int ReporteAutorizaciones::getIdPersona() { return _idPersona; }
int ReporteAutorizaciones::getIdUnidad() { return _idUnidad; }
int ReporteAutorizaciones::getTipo() { return _tipo; }
Fecha ReporteAutorizaciones::getHasta() { return _hasta; }
std::string ReporteAutorizaciones::getNombre() { return _nombre; }
std::string ReporteAutorizaciones::getApellido() { return _apellido; }
std::string ReporteAutorizaciones::getNombreTipo() { return _nombreTipo; }

//acciones

void ReporteAutorizaciones::mostrar()
{
    cout << "ID: " << _id << endl;
    cout << "idPersona: " << _idPersona << endl;
    cout << "idUnidad: " << _idUnidad << endl;
    cout << "idTipo: " << _tipo << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "NombreTipo: " << _nombreTipo << endl;
    cout << "Autorizado hasta: " << _hasta.toString() << endl;
}

void ReporteAutorizaciones::mostrarReporte()
{
    cout << left;
    //cout << setw(4) << _id;
    //cout << setw(10) << _idPersona;
    cout << setw(20) << _nombre;
    cout << setw(20) << _apellido;
    cout << setw(16) << _nombreTipo;
    cout << setw(9) << _idUnidad;
    cout << setw(15) << _hasta.toString() << endl;
}

/*
void ReporteAutorizaciones::mostrar2()
{
    cout << "-----------------------------" << endl;
    cout << "ID: " << _id << " || idPersona: " << _idPersona << " || idUnidad: " << _idUnidad;
    cout << " || idTipo: " << _tipo << " || Apellido: " << _apellido;
    cout << " || NombreTipo: " << _nombreTipo << " || Autorizado hasta: " << _hasta.toString() << endl;
    cout << "-----------------------------" << endl;
} 
 */