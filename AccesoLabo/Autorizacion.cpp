#include "Autorizacion.h"
using namespace std;
//sets
void Autorizacion::setId(int id) { _id = id; }
void Autorizacion::setIdPersona(int id) {_idPersona = id; }
void Autorizacion::setIdUnidad(int u) { _idUnidad = u; }
void Autorizacion::setHasta(FechaHorario f) { _hasta = f; }
void Autorizacion::setEstado(bool e) { _estado = e; }
//gets
int Autorizacion::getId() { return _id; }
int Autorizacion::getIdPersona() { return _idPersona; }
int Autorizacion::getIdUnidad() { return _idUnidad; }
FechaHorario Autorizacion::getHasta() { return _hasta; }
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
    cout << "ID: " << _id << endl;
    cout << "Autorizado hasta: " << endl;
    _hasta.toString();
}