
#include <iostream>
#include "Empresa.h"
#include <cstring>
#include <string>

using namespace std;

int Empresa::getCuit() const {

	return _cuit;
}
string  Empresa::getRazonSocial() {
	string retornar = _razonSocial;
	return retornar;
}
string Empresa::getDescripcion()  {
	string retornar = _descripcion;
	return retornar;
}

void Empresa::setCuit(int cuit) {
	_cuit = cuit;
}
void Empresa::setRazonSocial(string razonSocial) {
	strcpy(_razonSocial, razonSocial.c_str());
}
void Empresa::setDescripcion(string descripcion) {
	strcpy(_descripcion, descripcion.c_str());


}
void Empresa::cargar() {
	string razon, descripcion;
	int cuit;
	cout << "Ingrese Nro de cuit de la Empresa " << endl;
	cin >> cuit;
	setCuit(cuit);
	cin.ignore();

	cout << "Ingrese razon social de la misma " << endl;

	getline(cin, razon);

	setRazonSocial(razon);

	cout << "Ingrese una breve descripcion de la empresa" << endl;
	getline(cin, descripcion);
	setDescripcion(descripcion);



}

string Empresa::mostrarempresastring() {
	string retornar;
	retornar = " Cuit : " + to_string(_cuit) + "\n" + " Razon Social : " + getRazonSocial() + "\n" + " Descripcion : " + getDescripcion();

	return retornar;
}
void Empresa::mostrar() {
	cout << " Cuit : " << to_string(_cuit) << endl;
	cout << " Razon Social : " << getRazonSocial() << endl;
	cout << " Descripcion : " << getDescripcion() << endl;

}
int  Empresa::getId() {
	return _cuit;
}