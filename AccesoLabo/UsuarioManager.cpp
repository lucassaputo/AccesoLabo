#include "UsuarioManager.h"
#include "FuncionesGlobales.h"
#include <iostream>
using namespace std;

void UsuarioManager::Cargar() {
	system("cls");
	cout << "ALTA USUARIO" << std::endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Usuario u;
	string legajo = ingresarLegajo();	
	u = _archivoUsuario.BuscarObj(std::stoi(legajo));
	cout << "eeee:     " << u.getLegajo();
	u.mostrar();
	if (u.getLegajo() >= 0) {
		if (u.getEstado()) {
			u.mostrar();
			cout << "El usuario ya se encuentra creado, si desea modificarlo ingrese en EDITAR" << endl;
		}
		else {
			cout << "ACAAA11" << endl;			
			u.cargar();
			
			if (_archivoUsuario.Modificar(u)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		cout << "ACAAA22" << endl;
		u.setLegajo(std::stoi(legajo));
		u.setId(_archivoUsuario.ContarRegistros() + 1);
		u.cargar();
		if (_archivoUsuario.Guardar(u)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	system("pause");
}
void UsuarioManager::Editar() {
	system("cls");
	cout << "EDICION USUARIO" << std::endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Usuario u;
	string legajo = ingresarLegajo();
	u = _archivoUsuario.BuscarObj(std::stoi(legajo));
	if (u.getLegajo() >= 0) {
		if (!u.getEstado()) {
			cout << "El usuario no existe, realice el alta." << endl;
		}
		else {
			u.editar();
			if (_archivoUsuario.Modificar(u)) {
				cout << "Registro editado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		cout << "La unidad no existe, realice el alta." << endl;
	}
	system("pause");
}
void UsuarioManager::Eliminar() {
	system("cls");
	cout << "BAJA USUARIO" << std::endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Usuario u;
	string decision;
	string legajo = ingresarLegajo();
	u = _archivoUsuario.BuscarObj(std::stoi(legajo));
	if (u.getLegajo() >= 0) {
		if (!u.getEstado()) {
			cout << "El usuario no existe.";
		}
		else {
			cout << "Desea dar la baja del usuario de legajo:  " << legajo << "? S/N : ";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				u.setEstado(false);
				if (_archivoUsuario.Modificar(u)) {
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
	}
	else {
		cout << "El usuario no existe." << endl;
	}
	system("pause");
}

string UsuarioManager::ingresarLegajo() {
	string legajo;
	cout << "Ingrese legajo: " << endl;
	cin.ignore();
	cin >> legajo;
	while (!(soloNumeros(legajo))) {
		cout << "Solo puede contener numeros, ingrese legajo: ";
		cin.ignore();
		cin >> legajo;
	}
	return legajo;
}