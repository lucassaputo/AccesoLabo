#include <cstring>
#include "Persona.h"
#include "Empleado.h"
#include<iostream>

using namespace std;



void Empleado::setTipo(char tipo) {
	_tipo = tipo;
}

void Empleado::setCategoria(char categoria) {
	_categoria = categoria;
}

void Empleado::setLegajo(int legajo) {
	_legajo = legajo;
}

void Empleado::setDescripcion(const string descripcion) {
	strcpy(_descripcion, descripcion.c_str());

}


char Empleado::getTipo() const {
	return _tipo;
}

char Empleado::getCategoria() const {
	return _categoria;
}

int Empleado::getLegajo() const {
	return _legajo;
}

string Empleado::getDescripcion() const {
	string retornar = _descripcion;
	return retornar;


}

void Empleado::CargarEmpleado() {

	int legajo;
	char tipo;
	char categoria;
	string descripcion;


	cargarPersona(); // ACA CARGA LO CORRESPONDIENTE A PERSONA .


	cout << "Ingrese el legajo: ";
	cin >> legajo;
	setLegajo(legajo);
	cout << "Ingrese el tipo: ";
	cin >> tipo;
	setTipo(tipo);

	cout << "Ingrese la categoría: ";
	cin >> categoria;
	setCategoria(categoria);



	cin.ignore();
	cout << "Ingrese descripción: ";
	getline(cin, descripcion);
	setDescripcion(descripcion);


}
// Comentado - por que String?? 
/*
string Empleado::MostrarEmpleadostring() {
	string retornar = mostrarPersonastring();
	retornar += " Legajo empleado : " + to_string(getLegajo()) + "\n" +
		"Tipo  : " + getTipo() + "\n" +
		"Categoria : " + getCategoria() + "\n" +
		"Descripcion : " + getDescripcion() + "\n";

	return retornar;


}*/
void Empleado::mostrar() {

	//mostrarPersona();
	cout << " Legajo empleado : " << to_string(getLegajo()) << endl;
	cout << "Tipo  : " << getTipo()  << endl;
	cout << "Categoria : " << getCategoria()  << endl;
	cout << "Descripcion : " << getDescripcion() << endl;

}