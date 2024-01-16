#include "UsuarioManager.h"
#include <iostream>
using namespace std;

void UsuarioManager::Cargar() {
	system("cls");
	cout << "ALTA USUARIO" << std::endl;
	cout << "---------------------------" << endl;
	Usuario u;
	u.cargar();
	system("pause");
}
void UsuarioManager::Editar() {
	system("cls");
	cout << "**EditarLog In**" << std::endl;
	system("pause");
}
void UsuarioManager::Eliminar() {
	system("cls");
	cout << "**EliminarLog In**" << std::endl;
	system("pause");
}