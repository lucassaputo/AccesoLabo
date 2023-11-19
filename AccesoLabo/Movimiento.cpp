#include <iostream>
#include <cstring>
#include "Movimiento.h"
using namespace std;

Persona Movimiento::getPersona()
{
    return _persona;
}

Unidad Movimiento::getUnidad()
{
    return _unidad;
}

Fecha Movimiento::getFecha()
{
    return _fecha;
}

int Movimiento::getSentido()
{
    return _sentido;
}

std::string Movimiento::getObservaciones()
{
    return _observaciones;
}

std::string Movimiento::getTipoAutorizacion()
{
    return _tipoAutorizacion;
}

bool Movimiento::getEstado()
{
    return _estado;
}

void Movimiento::setPersona(Persona p)
{
    _persona = p;
}

void Movimiento::setUnidad(Unidad u)
{
    _unidad = u;
}

void Movimiento::setFecha(Fecha f)
{
    _fecha = f;
}

void Movimiento::setObservaciones(std::string obs)
{
    _observaciones = obs;

}

void Movimiento::setTipoAutorizacion(std::string aut)
{
    _tipoAutorizacion = aut;
}

void Movimiento::setEstado(bool e)
{
    _estado = e;
}

void Movimiento::cargar()
{
    int d, m, a;
    setEstado(true);
    string Observaciones, TipoAutorizacion;
    _persona.cargarPersona();
    _unidad.cargar();
    cout << "Ingrese fecha (dd/mm/aaaa)" << endl;
    cin >> d >> m >> a;
    _fecha.cargar(d,m,a);
    cout << "ingrese el sentido" << endl;
    cin >> _sentido;
    cout << "ingrese el tipo de autorizacion" << endl;
    getline(cin, TipoAutorizacion);
    setTipoAutorizacion(TipoAutorizacion);
    cout << "Observaciones" << endl;
    getline(cin, Observaciones);
    setObservaciones(Observaciones);
}

void Movimiento::mostrar()
{
  //  _persona.mostrarPersonastring();
    _persona.mostrar();
    _unidad.mostrar();
    _fecha.toString();
    cout << "Sentido: " << _sentido << endl;
    cout << "Tipo Autorizacion: " << _tipoAutorizacion << endl;
    cout << "Observaciones: " << _observaciones << endl;
}
