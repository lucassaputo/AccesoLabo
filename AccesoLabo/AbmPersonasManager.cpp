#include "AbmPersonasManager.h"
#include "FuncionesGlobales.h"
#include <iostream>
using namespace std;

void AbmPersonasManager::AltaProveedor() {
	system("cls");
	Proveedor p;
	cout << "***********  Alta Proveedor  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	int dni = cargarDni();
	p = _archivoProveedores.BuscarObj(dni);
	p.mostrar();
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			cout << "El proveedor ya se encuentra creado, si desea modificarlo ingrese en EDITAR" << endl;
		}
		else {
			p.cargarProveedor(dni);
			if (_archivoProveedores.Modificar(p)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		p.setId(_archivoProveedores.ContarRegistros() + 1);
		p.cargarProveedor(dni);
		p.mostrar();
		system("pause");
		if (_archivoProveedores.Guardar(p)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	system("pause");
}
void AbmPersonasManager::EditarProveedor() {
	system("cls");
	cout << "***********  Edicion Proveedor  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Proveedor p;
	int dni = cargarDni();
	p = _archivoProveedores.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			p.editarProveedor();
			if (_archivoProveedores.Modificar(p)) {
				cout << "Registro editado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
		else {
			cout << "El proveedor no existe, realice el alta." << endl;
		}
	}
	else {
		cout << "El proveedor no existe, realice el alta." << endl;	
	}
	system("pause");
}

void AbmPersonasManager::BajaProveedor() {
	system("cls");
	cout << "***********  Baja Proveedor  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Proveedor p;
	string decision;
	int dni = cargarDni();
	p = _archivoProveedores.BuscarObj(dni);
	if (p.getDni() != -1) {
		if (p.getEstado()) {			
			cout << "Desea dar la baja del proveedor con dni:  " << dni << "? S/N : ";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				p.setEstado(false);
				if (_archivoProveedores.Modificar(p)) {
					cout << "Registro eliminado correctamente." << endl;
				}
				else {
					cout << "Error al guardar." << endl;
				}
			}
			else {
				cout << "Accion cancelada." << endl;
			}
		}
		else {
			cout << "El proveedor no existe.";
		}
	}
	else {
		cout << "El proveedor no existe." << endl;
	}
	system("pause");
}

void AbmPersonasManager::AltaVisita() {
	system("cls");
	cout << "AltaVisita" << endl;
	system("pause");
}

void AbmPersonasManager::EditarVisita() {
	system("cls");
	cout << "EditarVisita" << endl;
	system("pause");
}
void AbmPersonasManager::BajaVisita() {
	system("cls");
	cout << "BajaVisita" << endl;
	system("pause");
}
void AbmPersonasManager::AltaResidente() {
	system("cls");
	cout << "AltaResidente" << endl;
	system("pause");
}
void AbmPersonasManager::EditarResidente() {
	system("cls");
	cout << "EditarResidente" << endl;
	system("pause");
}
void AbmPersonasManager::BajaResidente() {
	system("cls");
	cout << "BajaResidente" << endl;
	system("pause");
}