#include "AbmUnidadesManager.h"
#include "Unidad.h"
#include <iostream>
using namespace std;

void AbmUnidadesManager::Alta() {
	system("cls");
	cout << "Alta unidad." << endl;
	Unidad u;

	u.cargar();
	if (_archivoUnidades.Guardar(u)) {
		cout << "Registro guardado correctamente.";
	}
	else {
		cout << "Error al guardar.";
	}
	system("pause");
}
void AbmUnidadesManager::Baja() {
	system("cls");

	for (int i = 0;i < 20;i++) {
		cout << "Alta unidad." << endl;
		Unidad u;
		u.cargar();
		if (_archivoUnidades.Guardar(u)) {
			cout << "Registro guardado correctamente.";
		}
		else {
			cout << "Error al guardar.";
		}
	}
	//cout << "Baja" << endl;
	system("pause");
}
void AbmUnidadesManager::Editar() {
	system("cls");
	cout << "Edicion" << endl;
	system("pause");
}