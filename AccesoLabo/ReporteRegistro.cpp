#include "ReporteRegistro.h"

using namespace std;
//sets
void ReporteRegistro::setIdUnidad(int u) { _idUnidad = u; }
void ReporteRegistro::setNombre(std::string a) { _nombre = a; }
void ReporteRegistro::setApellido(std::string a) { _apellido = a; }
void ReporteRegistro::setDni(int d) { _dni = d; }
void ReporteRegistro::setNombreTipo(std::string n) { _nombreTipo = n; }
void ReporteRegistro::setFechaIngreso(FechaHorario f) { _fechaIngreso = f; }
void ReporteRegistro::setFechaEgreso(FechaHorario f) { _fechaEgreso = f; }
//gets
int ReporteRegistro::getIdUnidad() { return _idUnidad; }
std::string ReporteRegistro::getNombre() { return _nombre; }
std::string ReporteRegistro::getApellido() { return _apellido; }
int ReporteRegistro::getDni() { return _dni; }
std::string ReporteRegistro::getNombreTipo() { return _nombreTipo; }
FechaHorario ReporteRegistro::getFechaIngreso() { return _fechaIngreso; }
FechaHorario ReporteRegistro::getFechaEgreso() { return _fechaEgreso; }

//acciones

void ReporteRegistro::mostrar()
{
    cout << "idUnidad: " << _idUnidad << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "NombreTipo: " << _nombreTipo << endl;
}

void ReporteRegistro::mostrarReporte()
{
    cout << left;
    cout << setw(9) << _idUnidad;
    cout << setw(20) << _nombre;
    cout << setw(20) << _apellido;
    cout << setw(12) << _dni;
    cout << setw(16) << _nombreTipo;
    cout << setw(15) << _fechaIngreso.toString() << endl;
    cout << setw(15) << _fechaEgreso.toString() << endl;

}