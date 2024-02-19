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
	u = _archivoUsuario.BuscarObj(legajo);
	//cout << "eeee:     " << u.getLegajo();
	//u.mostrar();
	cout << "DDDDDDDDDDDDDD2222222222222222222222" << endl;
	if (u.getLegajo() != "-1") {
		//cout << "DDDDDDDDDDDDDD" << endl;
		if (u.getActivo()) {
			//u.mostrar();
			cout << "El usuario ya se encuentra creado, si desea modificarlo ingrese en EDITAR" << endl;
		}
		else {
			//cout << "ACAAA11" << endl;			
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
		//cout << "ACAAA22" << endl;
		u.setLegajo(legajo);
		u.setId(_archivoUsuario.ContarRegistros() + 1);
		u.cargar();
		u.mostrar();system("pause");
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
	u = _archivoUsuario.BuscarObj(legajo);
	if (u.getLegajo() != "-1") {
		if (!u.getActivo()) {
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
	u = _archivoUsuario.BuscarObj(legajo);
	if (u.getLegajo() != "-1") {
		if (!u.getActivo()) {
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
				u.setActivo(false);
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

