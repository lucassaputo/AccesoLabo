#include "FuncionesGlobales.h"
#include "Fecha.h"
#include<iostream>
using namespace std;

void cargarCadena(char* pal, int tam) {
	int i;
	fflush(stdin);
	for (i = 0; i < tam; i++)
	{
		pal[i] = cin.get();
		if (pal[i] == '\n') break;
	}
	pal[i] = '\0';
	fflush(stdin);
}

string cargarNombre() {
	string nombre = "";
	cout << "Nombre/s: ";
	cin.ignore();
	getline(cin, nombre);
	//strcpy(_nombres, nombres.c_str());
	while (!(soloLetras(nombre))) {
		cout << "El Nombre no puede contener números//   Nombre / s: ";
		cin.ignore();
		getline(cin, nombre);
	}
	return nombre;
}

string cargarString(string campo) {
	string cadena = "";
	cout << campo + ": ";
	//cin.ignore();
	getline(cin, cadena);
	//strcpy(_nombres, nombres.c_str());
	while (!(soloLetras(cadena))) {
		cout << campo + " no puede contener números. " + "Ingrese " + campo + ": ";
		cin.ignore();
		getline(cin, cadena);
	}
	return cadena;
}

int cargarTelefono() {
	string aux = "";
	cout << "Ingrese telefono: ";
	cin >> aux;
	while (soloNumeros(aux) == false || !(aux.size() < 14 && aux.size() > 6)) {
		cout << "Telefono invalido, Ingrese telefono: ";
		//cin.ignore();
		cin >> aux;
	}
	return std::stoi(aux);
}

int cargarDni() {
	string aux = "";
	cout << "Ingrese DNI: ";
	//cin.ignore();
	cin >> aux;
	while (soloNumeros(aux) == false || !(aux.size() < 10 && aux.size() > 6)) {
		cout << "DNI invalido, Ingrese DNI: ";
		cin.ignore();
		cin >> aux;
	}
	return std::stoi(aux);
}

bool soloNumeros(string x) {
	bool esNumero = true;
	for (char c : x) {
		if (!isdigit(c)) {
			esNumero = false;
			break;
		}
	}
	return esNumero;
}

bool soloLetras(string x) {
	bool esLetra = true;
	for (char c : x) {
		if (isdigit(c)) {
			esLetra = false;
			break;
		}
	}
	return esLetra;
}

string ingresarLegajo() {
	string legajo;
	cout << "Ingrese legajo: " << endl;
	//cin.ignore();
	cin >> legajo;
	while (!(soloNumeros(legajo))) {
		cout << "Solo puede contener numeros, ingrese legajo: ";
		cin.ignore();
		cin >> legajo;
	}
	return legajo;
}

string ingresarIdUnidad() {
	string id;
	cout << "Ingrese numero de unidad: " << endl;
	cin.ignore();
	cin >> id;
	while (soloNumeros(id) == false) {
		cout << "Solo puede contener numeros, Ingrese unidad: ";
		cin.ignore();
		cin >> id;
	}
	return id;
}

void Creditos() {
	system("cls");
	cout << "----- CREDITOS -----" << endl;
	cout << "Coll Benegas, Pablo" << endl;
	cout << "Saputo, Lucas" << endl;
	system("pause");
}

