#include "AbmUnidadesManager.h"
#include "Unidad.h"
#include "ArchivoUnidad.h"
#include "FuncionesGlobales.h"
#include <iostream>
using namespace std;

void AbmUnidadesManager::Alta() {
	system("cls");
	cout << "ALTA UNIDAD" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	Unidad u, Uaux;
	string id = ingresarIdUnidad();
	//u.setId(std::stoi(id));	
	int pos;
	pos = _archivoUnidades.BuscarPos(std::stoi(id));
	if (pos >= 0) {
		u = _archivoUnidades.Leer(pos);
		if (u.getEstado()) {
			cout << "La unidad ya se encuentra creada, si desea modificarla ingrese en EDITAR" << endl;
		}
		else {
			u.cargar();
			if (_archivoUnidades.Guardar(u, pos)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		u.setId(std::stoi(id));
		u.cargar();
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
	cout << "EDICION UNIDAD" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	id = ingresarIdUnidad();
	u= _archivoUnidades.BuscarObj(std::stoi(id));
	if (u.getId()>=0) {
		if (!u.getEstado()) {
			cout << "La unidad no existe, realice el alta." << endl;		
		}else {
			u.editar();
			if (_archivoUnidades.Modificar(u)) {
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

void AbmUnidadesManager::Baja() {
	system("cls");
	string id, decision;
	Unidad u;
	cout << "BAJA UNIDAD" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	id = ingresarIdUnidad();
	u = _archivoUnidades.BuscarObj(std::stoi(id));
	if (u.getId() >= 0) {
		if (!u.getEstado()) {
			cout << "La unidad no existe.";			
		}
		else {
			cout << "Desea darle la baja la unidad " << id <<"? S/N : ";
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

void AbmUnidadesManager::Listar() {
	system("cls");
	Unidad u;
	cout << "LISTADO UNIDADES" << endl;
	cout << "++++++++++++++++++++++++++++++++" << endl;
	int cant = _archivoUnidades.ContarRegistros();
	for (int i = 0;i < cant;i++) {
		u = _archivoUnidades.Leer(i);
		u.mostrar();
	}
	system("pause");
}