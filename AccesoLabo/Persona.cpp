#pragma once
#include<iostream>
#include <cstring>
#include "Persona.h"
#include "FuncionesGlobales.h"
using namespace std;

Persona::Persona() {}

//sets
void Persona::setId(int id) { _id = id; }
void Persona::setNombres(string nombres) { strcpy(_nombres, nombres.c_str()); }
void Persona::setApellidos(string apellidos) { strcpy(_apellidos, apellidos.c_str()); }
void  Persona::setDni(int dni) {
	if (dni > 1000000) {
		_dni = dni;
	}
}
void  Persona::setNacimiento(Fecha fecha) { _nacimiento = fecha; }
void  Persona::setEstado(bool estado) { _estado = estado; }
//gets
int  Persona::getId() { return _id; }
string Persona::getNombres() { return _nombres; }
string Persona::getApellidos() { return _apellidos;}
int  Persona::getDni() { return _dni; }
string  Persona::getNacimiento() { return _nacimiento.toString(); }
bool  Persona::getEstado() { return _estado; }
string Persona::getApellidosyNombres() {
	string nombrecompleto = _apellidos;	nombrecompleto += _nombres;
	return nombrecompleto;
}

void  Persona::cargarPersona() {
	Fecha aux;
	Fecha hoy;
	cin.ignore();
	setNombres(cargarString("Nombre"));
	setApellidos(cargarString("Apellido"));
	//setNacimiento(02, 11, 2000);
	cout << "Ingrese fecha de nacimiento: " << endl;
	while (true) {
		while (aux.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		break;
	}
	setNacimiento(aux);

	_estado = true;

	//string nombres, apellidos;
	/*cout << "Nombre/s: ";
	cin.ignore();
	getline(cin, nombres);
	//strcpy(_nombres, nombres.c_str());
	while (!(soloLetras(nombres))) {
		cout << "Nombre/s: ";
		cin.ignore();
		getline(cin, nombres);
	}*/	
	/*cout << "Apellido/s: ";
	cin.ignore();
	getline(cin, apellidos);*/
	//strcpy(_apellidos, apellidos.c_str());
}

void  Persona::editarPersona() {
	Fecha aux;
	cin.ignore();
	cout << "Nombre/s actuales: " << _nombres << endl;
	setNombres(cargarString("Nombre"));
	cout << "Apellido/s actuales: " << _apellidos << endl;
	setApellidos(cargarString("Apellido"));	
	//setNacimiento(02, 11, 2000);
	cout << "Fecha de nacimiento actual: " << _nacimiento.toString() << endl;
	cout << "Ingrese fecha de nacimiento: " << endl;
	while (true) {
		while (aux.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		break;
	}
	cout << "dia: " << aux.getDia() << endl;
	cout << "mes: " << aux.getMes() << endl;
	cout << "anio: " << aux.getAnio() << endl;
	setNacimiento(aux);
	_estado = true;
}

void Persona::mostrar()
{
	cout << "id: " << _id << endl;
	cout << "Nombre: " << _nombres << endl;
	cout << "Apellido: " << _apellidos << endl;
	cout << "Documento: " << _dni << endl;
	cout << "Estado: " << _estado << endl;
}
void Persona::mostrarX()
{
	cout << "Nombre: " <<  endl;
}

