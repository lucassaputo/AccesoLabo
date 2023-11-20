#include <iostream>
#include <cstring>
#include "Unidad.h"

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

//acciones
void Unidad::cargar(){	
	string familia, observaciones;
	cout << "Ingrese numero de unidad: ";
	cin >> _id;
	cout << "Ingrese telefono: ";
	cin >> _telefono;
	cout << "Ingrese nombre de la familia: ";
	cin.ignore();
	getline(cin, familia);
	setFamilia(familia);
	//cin.ignore();
	cout << "Observaciones: " << endl;
	getline(cin, observaciones);
	setObservaciones(observaciones);
	_estado = true;
}

void Unidad::mostrar() {
	cout << "Numero: " << _id << endl;
	cout << "Telefono: " << _telefono << endl;
	cout << "Familia: " << _familia << endl;
	cout << "Observaciones: " << _observaciones << endl;
}




