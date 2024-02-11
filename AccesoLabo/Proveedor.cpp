#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Proveedor.h"
#include<iostream>

using namespace std;


//sets
void Proveedor::setTipo(char tipo) {_tipo = tipo;}
void Proveedor::setArt(int dia, int mes, int anio) {_art.cargar(dia, mes, anio);}
void Proveedor::setArt(Fecha fecha) {_art = fecha;}
void Proveedor::setEmpresa(std::string empresa) {strcpy(_empresa, empresa.c_str());}
//gets
char Proveedor::getTipo() const { return _tipo; }
std::string Proveedor::getArt() { return _art.toString(); }
Fecha Proveedor::getArtFecha() { return _art; }
std::string Proveedor::getEmpresa() const { return _empresa; }

//acciones

void Proveedor::cargarProveedor(int dni) {
	Fecha aux;
	Fecha hoy;
	string empresa;
	cargarPersona();
	setDni(dni);
	cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
	while (true) {
		while (aux.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		if (!(aux > hoy)) {
			cout << "La fecha ingresada debe ser mayor a hoy. Ingrese fecha: " << endl;
		}
		else {
			cout << "OKFecha" << endl;
			break;
		}
	}
	setArt(aux);
	cin.ignore();
	cout << "Ingrese Empresa perteneciente " << endl;
	std::getline(cin, empresa);
	setEmpresa(empresa);
}

void Proveedor::editarProveedor() {
	Fecha aux;
	Fecha hoy;
	string empresa;
	Persona::editarPersona();	
	cout << "Fecha de vencimiento actual: " << _art.toString() << endl;
	cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
	while (true) {
		while (aux.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		if (!(aux > hoy)) {
			cout << "La fecha ingresada debe ser mayor a hoy. Ingrese fecha: ";
		}
		else {
			cout << "OKFecha" << endl;
			break;
		}
	}
	setArt(aux);
	cin.ignore();
	cout << "Empresa perteneciente actual: " << _empresa << endl;
	cout << "Ingrese Empresa perteneciente " << endl;
	std::getline(cin, empresa);
	setEmpresa(empresa);
}

void Proveedor::mostrar() {
	Persona::mostrar();
	cout << "Tipo Proveedor : " << to_string(getTipo()) << endl;
	cout << " Empresa perteneciente : " << getEmpresa() << endl;
	cout << "Fecha de su Art : " << getArt() << endl;
}

bool Proveedor::operator>(Fecha &fechaActual)
{
	if (_art.getAnio() > fechaActual.getAnio()) {
		return true;
	}
	else if (_art.getAnio() == fechaActual.getAnio()) {
		if (_art.getMes() > fechaActual.getMes()) {
			return true;
		}
		else if (_art.getMes() == fechaActual.getMes()) {
			if (_art.getDia() > fechaActual.getDia()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
	return false;
	}
}
bool Proveedor::vencido() {
	Fecha fechaActual;
	if (_art > fechaActual) {
		return false;
	}	
	return true;	
}
