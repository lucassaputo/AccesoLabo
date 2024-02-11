#include <cstdio>
#include <cstring>
#include<iostream>
#include "Configuracion.h"

using namespace std;


//sets
void Configuracion::setDesde(Horario h) { _desde = h; }
void Configuracion::setHasta(Horario h) { _hasta = h; }
//gets
Horario Configuracion::getDesde() { return _desde; }
Horario Configuracion::getHasta() { return _hasta; }

//acciones
void Configuracion::cargar(int dni) {

}
void Configuracion::mostrar() {

}

