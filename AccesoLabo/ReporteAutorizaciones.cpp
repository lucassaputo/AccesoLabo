#include "ReporteAutorizaciones.h"

using namespace std;
//sets
void ReporteAutorizaciones::setIdUnidad(int u) { _idUnidad = u; }
void ReporteAutorizaciones::setNombre(std::string a) { _nombre = a; }
void ReporteAutorizaciones::setApellido(std::string a) { _apellido = a; }
void ReporteAutorizaciones::setNombreTipo(std::string n) { _nombreTipo = n; }
void ReporteAutorizaciones::setHasta(Fecha f) { _hasta = f; }
//gets
int ReporteAutorizaciones::getIdUnidad() { return _idUnidad; }
std::string ReporteAutorizaciones::getNombre() { return _nombre; }
std::string ReporteAutorizaciones::getApellido() { return _apellido; }
std::string ReporteAutorizaciones::getNombreTipo() { return _nombreTipo; }
Fecha ReporteAutorizaciones::getHasta() { return _hasta; }

//acciones

void ReporteAutorizaciones::mostrar()
{
    cout << "idUnidad: " << _idUnidad << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "NombreTipo: " << _nombreTipo << endl;
    cout << "Autorizado hasta: " << _hasta.toString() << endl;
}

void ReporteAutorizaciones::mostrarReporte()
{
    cout << left;
    cout << setw(20) << _nombre;
    cout << setw(20) << _apellido;
    cout << setw(16) << _nombreTipo;
    cout << setw(9) << _idUnidad;
    cout << setw(15) << _hasta.toString() << endl;
}