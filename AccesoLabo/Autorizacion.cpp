#include "Autorizacion.h"
using namespace std;
//sets
void Autorizacion::setId(int id) { _id = id; }
void Autorizacion::setIdPersona(int id) {_idPersona = id; }
void Autorizacion::setIdUnidad(int u) { _idUnidad = u; }
void Autorizacion::setTipo(int t) { _tipo = t; }
void Autorizacion::setHasta(Fecha f) { _hasta = f; }
void Autorizacion::setEstado(bool e) { _estado = e; }
//gets
int Autorizacion::getId() { return _id; }
int Autorizacion::getIdPersona() { return _idPersona; }
int Autorizacion::getIdUnidad() { return _idUnidad; }
int Autorizacion::getTipo() { return _tipo; }
Fecha Autorizacion::getHasta() { return _hasta; }
bool Autorizacion::getEstado() { return _estado; }

//acciones
void Autorizacion::cargar(){ 
    int d, m, a;
    setEstado(true);
    cout << "Ingrese el ID: " << endl;
    cin >> _id;
    //poner resto datos
    cin >> d >> m >> a;
    //_hasta.cargar(d, m, a);
}

void Autorizacion::mostrar()
{
    cout << left;
    cout << setw(2) << _id ;
    cout << setw(2) << _idPersona ;
    cout << setw(2) << _idUnidad ;
    cout << setw(2) << _tipo ;
    cout << setw(2) << _hasta.toString() ;
    cout << setw(2) << _estado << endl;
}