#include "FuncionesGlobales.h"
#include "Fecha.h"
#include<iostream>
#include "Unidad.h"
#include "ArchivoUnidad.h"
#include "Horario.h"
#include "ConfigSingleton.h"
#include "Persona.h"
#include "Proveedor.h"
#include "ArchivoPersona.h"
#include "ArchivoProveedores.h"

using namespace std;

bool decisionExportar() {
	char r;
	cout << "Desea exportar los datos? S/N";
	cin >> r;
	while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
		cout << "Desea exportar los datos? S/N";
		cin >> r;
	}
	if (r == 'S' || r == 's') {
		return true;
	}
	else {
		return false;
	}
	return false;
}

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

string cargarStringTam(string campo, int tam) {
	string cadena = "";
	while(true){
		cout << campo + "----------: ";
		getline(cin, cadena);
		if (!(soloLetras(cadena))) {
			cout << campo + " no puede contener números. " + "Ingrese " + campo + ": ";
		}
		else if(cadena.length() > tam) {
			cout << campo + " tiene un maximo de 50 caracteres. " + "Ingrese " + campo + ": ";
		}
		else {
			return cadena;
		}


		//cin.ignore();
		//getline(cin, cadena);
	}
	return cadena;
}

string cargarTelefono() {
	string aux = "";
	cout << "Ingrese telefono: ";
	cin >> aux;
	while (soloNumeros(aux) == false || !(aux.size() < 11 && aux.size() > 6)) {
		cout << "Telefono invalido, Ingrese telefono: ";
		cin >> aux;
	}
	return aux;
}

int cargarDni() {
	string aux = "";
	cout << "Ingrese DNI: ";
	cin >> aux;
	while (soloNumeros(aux) == false || !(aux.size() < 10 && aux.size() > 6)) {
		cout << "DNI invalido, Ingrese DNI: ";
		cin.ignore();
		cin >> aux;
	}
	return std::stoi(aux);
}

string ingresarPassword() {
	string password = "nada";
	cout << "Ingrese password" << std::endl;
	cin >> password;
	cout << "password: " << password << "--" << password.length() << endl;
	while (password.length()<6 || password.length() > 12) {
		cout << "La contraseña debe ser de entre 6 y 12 caracteres. Ingresela nuevamente: ";
		cin >> password;
	}
	return password;
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
	//cin.ignore();
	cin >> opcion;
	//cout << opcion << "----------" << endl;
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
	ConfigSingleton& config = ConfigSingleton::getInstance();
	string id;
	cout << "Ingrese numero de unidad: " << endl;
	cin.ignore();
	cin >> id;
	while (true) {
		if (soloNumeros(id) == false) {
			cout << "Solo puede contener numeros, Ingrese unidad: ";
		}
		else if (std::stoi(id) > config.getConfig().getCantUnidades()) {
			cout << "La unidad debe ser menor a " << config.getConfig().getCantUnidades()+1 << ", Ingrese unidad : ";
		}
		else {
			return id;
		}
		cin.ignore();
		cin >> id;
	}
	return id;
}

int ingresarCantUnidades() {
	string aux;
	std::cout << "Ingrese cantidad maxima de unidades/lotes: ";
	cin.ignore();
	cin >> aux;
	while (true) {
		if (soloNumeros(aux) == false) {
			cout << "Solo puede contener numeros, Ingrese unidad: ";
		}else if (std::stoi(aux) > 1000) {
			cout << "Cantidad maxima permitida 1000, Ingrese unidad: ";
		}
		else {
			return std::stoi(aux);
		}
		cin.ignore();
		cin >> aux;
	}
	return std::stoi(aux);
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

Persona BuscarenVisita(int id)
{
	
	ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
	Persona reg;
	int pos = _archivoVisitas.BuscarId(id);
	reg = _archivoVisitas.Leer(pos);
	return reg;
}

Proveedor BuscarenProveedor(int id)
{
	ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
	Proveedor reg;
	int pos = _archivoProveedores.Buscar(id);
	reg = _archivoProveedores.Leer(pos);
	return reg;
}

bool ingresarPropInq() {
	string aux;
	while (true) {
		cout << "Ingrese 1 si es Residente 0 si es Inquilino: ";
		cin >> aux;
		if (aux == "1"){
			return true;
		}
		else if (aux == "0") {
			return false;
		}
		else {
			cout << "Opcion ingresada no valida." << endl;
		}
	}
	return false;
}

Fecha ingresarFechaAutorizacion() {
	Fecha hasta;
	cout << "Ingrese fecha autorizacion hasta DD/MM/AAAA): ";
	while (true) {
		while (hasta.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AAAA";
			cout << "Ingrese fecha autorizacion hasta (DD/MM/AAAA): ";
		}
		break;
	}
	return hasta;
}

Fecha ingresarFechaIngreso() {
	Fecha hoy;
	Fecha auxIngreso;
	cout << "Ingrese fecha de ingreso (DD/MM/AA): ";
	while (true) {
		while (auxIngreso.ingresarFecha() == false) {
			cout << "Ingrese fecha de ingreso (DD/MM/AA): ";
		}
		if (auxIngreso > hoy) {
			cout << "La fecha ingresada debe ser menor a hoy. Ingrese fecha: " << endl;
		}
		else {
			break;
		}
	}
	return auxIngreso;
}

Fecha ingresarFechaHasta() {
	Fecha hoy;
	Fecha auxHasta;
	cout << "Ingrese fecha de finalizacion del contrato (DD/MM/AA): ";
	while (true) {
		while (auxHasta.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha de finalizacion del contrato (DD/MM/AA): ";
		}
		if (auxHasta < hoy) {
			cout << "La fecha ingresada debe ser mayor a hoy. Ingrese fecha: " << endl;
		}
		else {
			break;
		}
	}
	return auxHasta;
}

string upper(string cadena) {
	// Convertir la cadena a mayúsculas
	for (char& c : cadena) {
		c = toupper(static_cast<unsigned char>(c));
	}
	return cadena;
}

Horario ingresarHorario(std::string campo) {
	Horario aux;
	cout << "Ingrese el horario " << campo << " el que se encuentran habilitados los ingresos de proveedores HH:mm 24hs: ";
	while (true) {
		while (aux.ingresarHorario() == false) {
			cout << "Formato invalido o fuera de rango ingrese HH:mm" << endl;
			cout << "Ingrese el horario " << campo << " el que se encuentran habilitados los ingresos de proveedores HH:mm 24hs: ";
		}
		return aux;
	}
	return aux;
}
string dosDigitos(int n) {
	string aux = to_string(n);
	if (n < 10) {
		aux = "0" + to_string(n);		
	}
	return aux;
}

void cabeceraAutorizados() {
	cout << left;
	cout << setw(20) << "|Nombre";
	cout << setw(20) << "|Apellido";
	cout << setw(16) << "|Motivo";
	cout << setw(9) << "|Unidad";
	cout << setw(15) << "|Autorizado hasta" << endl;
}

void cabeceraProveedores() {
	cout << left;
	cout << setw(20) << "|Nombre";
	cout << setw(20) << "|Apellido";
	cout << setw(12) << "|DNI";
	cout << setw(20) << "|Empresa";
	cout << setw(15) << "|ART" << endl;
}

void caberaUnidades() {
	cout << left;
	cout << setw(9) << "|Unidad";
	cout << setw(20) << "|Telefono";
	cout << setw(20) << "|Familia";
	cout << setw(30) << "|Observaciones" << endl;
}

void Creditos() {
	system("cls");
	cout << "----- CREDITOS -----" << endl;
	cout << "Coll Benegas, Pablo" << endl;
	cout << "Saputo, Lucas" << endl;
	system("pause");
}

