#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Proveedor.h"
#include<iostream>

using namespace std;


//sets
void Proveedor::setTipo(char tipo) {_tipo = tipo;}
void Proveedor::setArt(int dia, int mes, int anio) {_art.cargar(dia, mes, anio);}
void Proveedor::setEmpresa(std::string empresa) {strcpy(_empresa, empresa.c_str());}
//gets
char Proveedor::getTipo() const { return _tipo; }
std::string Proveedor::getArt() { return _art.toString(); }
Fecha Proveedor::getArtFecha() { return _art; }
std::string Proveedor::getEmpresa() const { return _empresa; }

//acciones

void Proveedor::cargarProveedor(int dni) {
	Fecha aux;
	cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
	while (aux.ingresarFecha()==false) {
		cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
	}

	//cout << "Formato de fecha incorrecto. Asegúrese de que la fecha tenga el formato DD/MM/AA.";

	/*cargarPersona();
	setDni(dni);
	setTipo('R');

	setArt(10, 10, 2023);
	setEmpresa("talali");
	*/
	/*char tipo;
	string empresa;
	int dia, mes, anio;
	setDni(dni);
	cout << "Ingrese Tipo del proveedor " << endl;
	cin >> tipo;
	setTipo(tipo);
	cin.ignore();
	cout << "Ingrese Empresa perteneciente " << endl;
	getline(cin, empresa);
	setEmpresa(empresa);
	cout << "Ingrese dia de su Art " << endl;
	cin >> dia;
	cout << "Ingrese mes de su Art " << endl;
	cin >> mes;
	cout << "Ingrese anio  de su Art" << endl;
	cin >> anio;
	setArt(dia, mes, anio);*/
}


void Proveedor::mostrar() {
	Persona::mostrar();
	cout << "Tipo Proveedor : " << to_string(getTipo()) << endl;
	//cout << " Empresa perteneciente : " << getEmpresa() << endl;
	//cout << "Fecha de su Art : " << getArt() << endl;
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
		return true;
	}
	else
	{
		return false;
	}
}
