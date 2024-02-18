#include "FuncionesGlobales.h"
#include "Fecha.h"
#include<iostream>
#include "Unidad.h"
#include "ArchivoUnidad.h"
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

string cargarApellido() {
	string apellido = "";
	cout << "Apellidos: ";
	cin.ignore();
	getline(cin, apellido);
	while (!(soloLetras(apellido))) {
		cout << "El Apellido no puede contener números//   apellido: ";
		cin.ignore();
		getline(cin, apellido);
	}
	return apellido;
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

int ingresarOpcionMenu(int opciones) {
	string opcion;
	cin.ignore();
	cin >> opcion;
	while (true) {
		if (soloNumeros(opcion)) {
			if (stoi(opcion) <= opciones) {
				return stoi(opcion);
			}		
		}
		cout << "Opcion invalida." << endl;
		cin >> opcion;
	}	
	return -1;	
}

string ingresarLegajo() {
	string legajo;
	cout << "Ingrese legajo: " << endl;
	//cin.ignore();
	cin >> legajo;
	while (!(soloNumeros(legajo)) || !(legajo.length()<6)) {
		cout << "Solo puede contener numeros, maximo 5 numeros, ingrese legajo: ";
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

Unidad buscarUnidad(int u) {
	//cout << "FX u: " << u << endl;
	ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
	int cant = _archivoUnidades.ContarRegistros();
	Unidad uni;
	Unidad aux;
	uni.setId(-1);
	for (int i = 0;i < cant;i++) {
		aux = _archivoUnidades.Leer(i);
		if (aux.getId() == u && aux.getEstado()) {
			return aux;
		}
	}
	return uni;
}

int ingresarMotivo() {
	string motivoAux;
	cout << "(1: Visita | 2 : Proveedor)" << endl;
	cout << "Ingrese motivo de autorizacion: ";
	cin.ignore();
	cin >> motivoAux;
	while (soloNumeros(motivoAux) == false || !(motivoAux == "1" || motivoAux == "2")) {
		cout << "Motivo invalido." << endl;
		cout << "Ingrese motivo de autorizacion:   (1: Visita | 2: Proveedor) ";
		cin >> motivoAux;
	}
	return std::stoi(motivoAux);
}

Unidad ingresarUnidad(string mensaje) {
	string unidadAux;
	Unidad uni;
	uni.setId(-1);
	while (true) {
		cout << "Ingrese unidad " << mensaje << ": ";
		cin.ignore();
		cin >> unidadAux;
		while (soloNumeros(unidadAux) == false) {
			cout << "Solo puede contener numeros, Ingrese unidad destino: ";
			cin.ignore();
			cin >> unidadAux;
		}
		uni = buscarUnidad(std::stoi(unidadAux));
		if (uni.getId() >= 0) {
			return uni;
		}
		else {
			cout << "La unidad ingresada no existe." << endl;
		}
	}
	return uni;
}

Fecha ingresarFechaAutorizacion() {
	Fecha hasta;
	cout << "Ingrese fecha desde (DD/MM/AA): ";
	while (true) {
		while (hasta.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		break;
	}
	return hasta;
}

string upper(string cadena) {
	// Convertir la cadena a mayúsculas
	for (char& c : cadena) {
		c = toupper(static_cast<unsigned char>(c));
	}
	return cadena;
}

void Creditos() {
	system("cls");
	cout << "----- CREDITOS -----" << endl;
	cout << "Coll Benegas, Pablo" << endl;
	cout << "Saputo, Lucas" << endl;
	system("pause");
}

