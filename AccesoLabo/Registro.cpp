#include <iostream>
#include <cstring>
#include "Fecha.h"
#include "Registro.h"
using namespace std;

Registro::Registro() {
    setEstado(true);
}

//sets
void Registro::setIdUnidad(int u){_idUnidad = u;}
void Registro::setIdPersona(int p){_idPersona = p;}
void Registro::setTipoPersona(int t) { _tipoPersona = t; }
void Registro::setFecha(Fecha f){_fecha = f;}
void Registro::setSentido(int e){_sentido = e;}
void Registro::setObservaciones(std::string obs){strcpy(_observaciones,obs.c_str()); }
void Registro::setTipoAutorizacion(int aut) { _tipoAutorizacion=aut; }
void Registro::setIdUser(int id) { _idUser = id; }
void Registro::setEstado(bool e){_estado = e;}

//gets
int Registro::getIdUnidad() { return _idUnidad; }
int Registro::getIdPersona() { return _idPersona; }
int Registro::getTipoPersona() { return _tipoPersona; }
Fecha Registro::getFecha() { return _fecha; }
int Registro::getSentido() { return _sentido; }
std::string Registro::getObservaciones() { return _observaciones; }
int Registro::getTipoAutorizacion() { return _tipoAutorizacion; }
int Registro::getIdUser() { return _idUser; }
bool Registro::getEstado() { return _estado; }

//acciones

void Registro::mostrar()
{
    cout << "Persona: " << _idPersona << endl;
    cout << "Unidad: " << _idUnidad << endl;
    cout << _fecha.toString() << endl;
    cout << "Sentido: " << _sentido << endl;
    cout << "Observaciones: " << _observaciones << endl;
    cout << "Tipo Autorizacion: " << _tipoAutorizacion << endl;
}
void Registro::operator =(Proveedor p) {
    Fecha aux;
    _idPersona = p.getId();    
    _fecha = aux;
}
