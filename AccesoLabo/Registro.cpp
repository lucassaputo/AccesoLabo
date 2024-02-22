#include <iostream>
#include <cstring>
#include "Fecha.h"
#include "Registro.h"
using namespace std;

Registro::Registro() {
    setEstado(true);
}

//sets
void Registro::setId(int u) { _id = u; }
void Registro::setIdUnidad(int u){_idUnidad = u;}
void Registro::setIdPersona(int p){_idPersona = p;}
void Registro::setTipoPersona(int t) { _tipoPersona = t; }
void Registro::setFechaIngreso(FechaHorario f){_fechaIngreso = f;}
void Registro::setFechaEgreso(FechaHorario f) { _fechaEgreso = f; }
void Registro::setAdentro(bool a){_adentro = a;}
void Registro::setTipoAutorizacion(int aut) { _tipoAutorizacion=aut; }
void Registro::setIdUser(int id) { _idUser = id; }
void Registro::setEstado(bool e){_estado = e;}

//gets
int Registro::getId() { return _id; }
int Registro::getIdUnidad() { return _idUnidad; }
int Registro::getIdPersona() { return _idPersona; }
int Registro::getTipoPersona() { return _tipoPersona; }
FechaHorario Registro::getFechaIngreso() { return _fechaIngreso; }
FechaHorario Registro::getFechaEgreso() { return _fechaEgreso; }
bool Registro::getAdentro() { return _adentro; }
int Registro::getTipoAutorizacion() { return _tipoAutorizacion; }
int Registro::getIdUser() { return _idUser; }
bool Registro::getEstado() { return _estado; }

//acciones

void Registro::mostrar()
{
    cout << "Persona: " << _idPersona << endl;
    cout << "Unidad: " << _idUnidad << endl;
    cout << "Tipo persona: " << _tipoPersona << endl;
    cout << _fechaIngreso.toString() << endl;
    cout << "Adentro: " << _adentro << endl;
    cout << "Tipo Autorizacion: " << _tipoAutorizacion << endl;
    cout << "Estado: " << _estado << endl;
}
void Registro::mostrarReporte()
{

}
void Registro::operator =(Proveedor p) {
    FechaHorario aux;
    _idPersona = p.getId();    
    _fechaIngreso = aux;
}
void Registro::operator =(Persona p) {
    FechaHorario aux;
    _idPersona = p.getId();
    _fechaIngreso = aux;
}

