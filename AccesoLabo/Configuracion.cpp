#include <cstdio>
#include <cstring>
#include<iostream>
#include "Configuracion.h"
#include "FuncionesGlobales.h"

using namespace std;


//sets
void Configuracion::setId(int id) { _id = id; }
void Configuracion::setCantUnidades(int cant) { _cantUnidades = cant; }
void Configuracion::setDesde(Horario h) { _desde = h; }
void Configuracion::setHasta(Horario h) { _hasta = h; }
//gets
int Configuracion::getId() { return _id; }
int Configuracion::getCantUnidades() { return _cantUnidades; }
Horario Configuracion::getDesde() { return _desde; }
Horario Configuracion::getHasta() { return _hasta; }

//acciones
void Configuracion::cargar() {
	Horario desde;
	Horario hasta;
	
}
void Configuracion::mostrar() {

}

