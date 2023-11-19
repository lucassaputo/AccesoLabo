#include <cstring>
#include "Persona.h"
#include "Visita.h"
#include<iostream>


using namespace std;

void Visita::setUnidad(int unidad) {
	_unidad = unidad;
}

void Visita::setFamiliar(bool es) {
	_familiar = es;
}

int Visita::getUnidad()const {
	return _unidad;
}
bool Visita::getFamiliar()const {
	return _familiar;
}

string Visita::mostrarvisitastring() {

	//string retornar = mostrarPersonastring();
	string retornar = "ASDASD";
	string familia;
	if (_familiar) {
		familia = " Posee familia dentro del recinto. ";
	}
	else {

		familia = "No posee familia dentro del recinto.";
	}

	retornar += " Numero unidad de la visita : " + to_string(_unidad) + "\n"
		+ "La visita " + familia;

	return retornar;
}

void Visita::mostrar() {

	cout << "Nombre: " << getNombres() << endl;
	cout << "Apellido: " << getApellidos() << endl;
	cout << "Documento: " << getDni() << endl;
}
void Visita::cargarvisita() {


}
void Visita::cargarvisita(int dni) {


}