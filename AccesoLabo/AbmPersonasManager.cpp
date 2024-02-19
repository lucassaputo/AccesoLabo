#include "AbmPersonasManager.h"
#include "FuncionesGlobales.h"
#include <iostream>
#include "Persona.h"
#include "Residente.h"

using namespace std;

void AbmPersonasManager::AltaProveedor() {
	system("cls");
	Proveedor p;
	cout << "***********  Alta Proveedor  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	int dni = cargarDni();
	p = _archivoProveedores.BuscarObj(dni);
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
	if (p.getDni() > 5000000) {
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
			cout << "El proveedor no existe." << endl;
		}
	}
	else {
		cout << "El proveedor no existe." << endl;
	}
	system("pause");
}

void AbmPersonasManager::AltaVisita() {
	system("cls");
	Persona per;
	cout << "***********  Alta Visita  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	int dni = cargarDni();
	per = _archivoVisitas.BuscarObj(dni);
	if (per.getDni() > 5000000) {
		if (per.getEstado()) {
			cout << "La visita ya se encuentra creada, si desea modificarla ingrese en EDITAR" << endl;
			
		}
		else {
			per.cargarPersona();
			if (_archivoVisitas.Modificar(per)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		per.setId(_archivoVisitas.ContarRegistros() + 1);
		per.setDni(dni);
		per.cargarPersona();
		if (_archivoVisitas.Guardar(per)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	system("pause");
}

void AbmPersonasManager::EditarVisita() {
	system("cls");
	cout << "***********  Edicion Visita  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Persona p;
	int dni = cargarDni();
	p = _archivoVisitas.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			p.editarPersona();
			if (_archivoVisitas.Modificar(p)) {
				cout << "Registro editado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
		else {
			cout << "La visita no existe, realice el alta." << endl;
		}
	}
	else {
		cout << "La visita no existe, realice el alta." << endl;
	}
	system("pause");
}
void AbmPersonasManager::BajaVisita() {
	system("cls");
	cout << "***********  Baja Visita  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Persona p;
	string decision;
	int dni = cargarDni();
	p = _archivoVisitas.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			cout << "Desea dar la baja de la visita con dni:  " << dni << "? S/N : ";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				p.setEstado(false);
				if (_archivoVisitas.Modificar(p)) {
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
			cout << "La visita no existe." << endl;
		}
	}
	else {
		cout << "La visita no existe." << endl;
	}
	system("pause");
}
void AbmPersonasManager::AltaResidente() {
	system("cls");
	Residente p;//como reconoce proveedor si no esta incluido
	cout << "***********  Alta Residente  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	int dni = cargarDni();
	p = _archivoResidentes.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			cout << "El residente ya se encuentra creado, si desea modificarlo ingrese en EDITAR" << endl;
		}
		else {
			p.cargarResidente();
			if (_archivoResidentes.Modificar(p)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		p.setId(_archivoResidentes.ContarRegistros() + 1);
		p.setDni(dni);
		p.cargarResidente();
		if (_archivoResidentes.Guardar(p)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	system("pause");
}
void AbmPersonasManager::EditarResidente() {
	system("cls");
	cout << "***********  Edicion Residente  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Residente p;
	int dni = cargarDni();
	p = _archivoResidentes.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			p.editarResidente();
			if (_archivoResidentes.Modificar(p)) {
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
void AbmPersonasManager::BajaResidente() {
	system("cls");
	cout << "***********  Baja Residente  ***********" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Residente p;
	string decision;
	int dni = cargarDni();
	p = _archivoResidentes.BuscarObj(dni);
	if (p.getDni() > 5000000) {
		if (p.getEstado()) {
			cout << "Desea dar la baja del residente con dni:  " << dni << "? S/N : ";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				p.setEstado(false);
				if (_archivoResidentes.Modificar(p)) {
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
			cout << "El residente no existe." << endl;
		}
	}
	else {
		cout << "El residente no existe." << endl;
	}
	system("pause");
}