#include "AbmUnidadesManager.h"
#include "Unidad.h"
#include "ArchivoUnidad.h"
#include "FuncionesGlobales.h"
#include <iostream>
using namespace std;

void AbmUnidadesManager::Alta() { // chequear que no exista
	system("cls");
	cout << "Alta unidad." << endl;
	cout << "-----------------------------" << endl;
	Unidad u, Uaux;

	u.cargar();
	int pos;
	pos = _archivoUnidades.BuscarPos(u.getId());
	if (pos >= 0) {
		Uaux = _archivoUnidades.Leer(pos);
		if (Uaux.getEstado()) {
			cout << "La unidad ya se encuentra creada, si desea modificarla ingrese en EDITAR" << endl;
			//system("pause");
			//return;
		}
		else {
			if (_archivoUnidades.Guardar(u, pos)) {
				cout << "Registro guardado correctamente." << endl;
			}else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		if (_archivoUnidades.Guardar(u)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	system("pause");
}

void AbmUnidadesManager::Editar() {
	system("cls");
	string id, decision;
	Unidad u;
	cout << "Edición" << endl;
	cout << "-----------------------------" << endl;
	cout << "Ingrese numero de unidad: " << endl;
	cin.ignore();
	cin >> id;
	while (soloNumeros(id) == false) {
		cout << "Solo puede contener numeros, Ingrese unidad a editar: ";
		cin.ignore();
		cin >> id;
	}
	u= _archivoUnidades.BuscarObj(std::stoi(id));
	if (u.getId()>=0) {
		if (!u.getEstado()) {
			cout << "La unidad no existe, realice el alta." << endl;
			/*cout << "Unidad dada de baja, desea habilitarla? S/N:";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Unidad dada de baja, desea habilitarla? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				u.editar();
				if (_archivoUnidades.Modificar(u)) {
					cout << "Registro modificado correctamente." << endl;
				}
				else {
					cout << "Error al guardar." << endl;
				}
			}
			else {
				cout << "Accion cancelada." << endl;
			}*/
			
		}else {
			u.editar();
			if (_archivoUnidades.Modificar(u)) {
				cout << "Registro eliminado correctamente." << endl;
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

void AbmUnidadesManager::Baja() {
	system("cls");
	string id, decision;
	Unidad u;
	cout << "Baja" << endl;
	cout << "-----------------------------" << endl;
	cout << "Ingrese numero de unidad: " << endl;
	cin.ignore();
	cin >> id;
	while (soloNumeros(id) == false) {
		cout << "Solo puede contener numeros, Ingrese unidad a editar: ";
		cin.ignore();
		cin >> id;
	}
	u = _archivoUnidades.BuscarObj(std::stoi(id));
	if (u.getId() >= 0) {
		if (!u.getEstado()) {
			cout << "La unidad no existe.";
			
		}
		else {
			cout << "Desea darle la baja? S/N:";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				u.setEstado(false);
				if (_archivoUnidades.Modificar(u)) {
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
		cout << "La unidad no existe, realice el alta." << endl;
	}
	system("pause");
}