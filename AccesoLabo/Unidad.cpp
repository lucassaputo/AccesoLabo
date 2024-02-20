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
void Unidad::setTelefono(int tel){_telefono = tel;}
void Unidad::setFamilia(std::string fam){strcpy(_familia,fam.c_str());}
void Unidad::setObservaciones(std::string obs) { strcpy(_observaciones, obs.c_str()); }
void Unidad::setEstado(bool estado){_estado = estado;}

//gets
int Unidad::getId(){return _id;}
int Unidad::getTelefono(){return _telefono;}
std::string Unidad::getFamilia(){return _familia;}
std::string Unidad::getObservaciones(){return _observaciones;}
bool Unidad::getEstado(){return _estado;}

void Unidad::cargar() {
//	_id = _archivoUnidad.ContarRegistros() + 1;
	setTelefono(cargarTelefono());
	cin.ignore();
	setFamilia(cargarString("Familia"));
	setObservaciones(cargarString("Observaciones"));
	_estado = true;
}

void Unidad::editar() {
	cout << "Telefono actual: " << getTelefono() << endl;
	setTelefono(cargarTelefono());
	cout << "Familia actual: " << getFamilia() << endl;
	cin.ignore();
	setFamilia(cargarString("Familia"));
	cout << "Observaciones actuales: " << getObservaciones() << endl;
	setObservaciones(cargarString("Observaciones"));
	_estado = true;
}
/*
void Unidad::mostrar() {
	cout << "|*| Numero ID: " << _id << endl;
	cout << "|*| - Telefono: " << _telefono << endl;
	cout << "|*| - Familia: " << _familia << endl;
	cout << "|*| - Observaciones: " << _observaciones << endl;
	cout << "          *   *   *           " << endl;
}

*/




/*

*/
void Unidad::mostrar() {
	
	//cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Numero ID: " << _id << " | Telefono: " << _telefono << " | Familia: " << _familia << " | Observaciones: " << _observaciones << " | " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

