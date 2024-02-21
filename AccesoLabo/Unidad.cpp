#include <iostream>
#include <cstring>
#include "Unidad.h"
#include "FuncionesGlobales.h"
#include "ArchivoUnidad.h"

using namespace std;

Unidad::Unidad() {

}
//sets
void Unidad::setId(int id){_id = id;}
void Unidad::setTelefono(std::string tel){strcpy(_telefono,tel.c_str());}
void Unidad::setFamilia(std::string fam){strcpy(_familia,fam.c_str());}
void Unidad::setObservaciones(std::string obs) { strcpy(_observaciones, obs.c_str()); }
void Unidad::setEstado(bool estado){_estado = estado;}

//gets
int Unidad::getId(){return _id;}
std::string Unidad::getTelefono(){return _telefono;}
std::string Unidad::getFamilia(){return _familia;}
std::string Unidad::getObservaciones(){return _observaciones;}
bool Unidad::getEstado(){return _estado;}

void Unidad::cargar() {
	setTelefono(cargarTelefono());
	cin.ignore();
	setFamilia(upper(cargarStringTam("Familia",50)));
	setObservaciones(upper(cargarStringTam("Observaciones",150)));
	_estado = true;
}

void Unidad::editar() {
	cout << "Telefono actual: " << getTelefono() << endl;
	setTelefono(cargarTelefono());
	cout << "Familia actual: " << getFamilia() << endl;
	cin.ignore();
	setFamilia(upper(cargarStringTam("Familia",50)));
	cout << "Observaciones actuales: " << getObservaciones() << endl;
	setObservaciones(upper(cargarStringTam("Observaciones",150)));
	_estado = true;
}



void Unidad::mostrar() {
	cout << right;
	cout << setw(3) <<"" << _id;
	cout << setw(3)  <<"" << _telefono;
	cout << setw(3)  << "" << _familia;
	cout << setw(6)  << "" << _observaciones << endl;
}



