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
void  Persona::setNacimiento(int dia, int mes, int anio) {
	_nacimiento.cargar(dia, mes, anio);
}
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
	cin.ignore();
	setNombres(cargarString("Nombre"));
	setApellidos(cargarString("Apellido"));
	setNacimiento(02, 11, 2000);
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
	cin.ignore();
	cout << "Nombre/s actuales: " << _nombres << endl;
	setNombres(cargarString("Nombre"));
	cout << "Apellido/s actuales: " << _apellidos << endl;
	setApellidos(cargarString("Apellido"));	
	setNacimiento(02, 11, 2000);
	_estado = true;
}

void Persona::mostrar()
{
	cout << "id: " << _id << endl;
	cout << "Nombre: " << _nombres << endl;
	cout << "Apellido: " << _apellidos << endl;
	cout << getDni() << endl;
}
void Persona::mostrarX()
{
	cout << "Nombre: " <<  endl;
}