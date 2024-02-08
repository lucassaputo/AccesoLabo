#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
using namespace std;

void ListadoManager::AutorizadosPorApellido() {
	system("cls");
	cout << "AutorizadosPorApellido" << endl;
	//MostrarCantidadRegistros();
	//ListarTodos();	
	ListarUsuarios();
	system("pause");
}
void ListadoManager::AutorizadosPorUnidad() {
	system("cls");
	cout << "AutorizadosPorUnidad" << endl;
	MostrarCantidadProveedores();
	ListarTodosProveedores();
	system("pause");
}
void ListadoManager::ResidentesPorUnidad() {
	system("cls");
	//cout << "ResidentesPorUnidad" << endl;
	ListarUnidades();
	system("pause");
}
void ListadoManager::ProveedoresPorRazon() {
	system("cls");
	//cout << "ProveedoresPorRazon" << endl;
	ListarRegistros();
	system("pause");
}
void ListadoManager::EmpleadosPorDNI() {
	system("cls");
	cout << "EmpleadosPorDNI" << endl;
	system("pause");
}
void ListadoManager::UnidadesPorNumero() {
	system("cls");
	cout << "UnidadesPorNumero" << endl;
	system("pause");
}
void ListadoManager::UnidadesPorFamilia() {
	system("cls");
	cout << "UnidadesPorFamilia" << endl;
	system("pause");
}

void ListadoManager::Mostrar(Registro reg) {
	
	//cout << "idPersona: " << reg.getPersona() << endl;
	//cout << "idUnidad: " << reg.getUnidad() << endl;
	//cout << "FECHA: " << reg.getFecha().toString() << endl;
	//cout << "TIPO: " << reg.getTipoAutorizacion() << endl;
	//cout << "sentido" << reg.getSentido() << endl;
	//cout << "observaciones " << reg.getObservaciones() << endl;
	//cout << "estado" << reg.getEstado() << endl;
}
/*
void ListadoManager::MostrarCantidadRegistros() {
	int cantidadRegistros = _archivoRegistros.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
}*/
void ListadoManager::MostrarCantidadRegistros() {
	int cantidadRegistros = _archivoUnidades.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
}
/*
void ListadoManager::ListarTodos() {
	int cantidadRegistros = _archivoRegistros.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
	Registro reg;
	for (int i = 0; i < cantidadRegistros; i++) {
		//Mostrar(_archivoRegistros.Leer(i));
		cout << endl << "CANT: " << i << endl;
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
	}
}*/
void ListadoManager::ListarTodos() {
	int cantidadRegistros = _archivoUnidades.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
	Unidad reg;
	for (int i = 0; i < cantidadRegistros; i++) {
		//Mostrar(_archivoRegistros.Leer(i));
		cout << endl << "CANT: " << i << endl;
		reg = _archivoUnidades.Leer(i);
		reg.mostrar();
	}
}
void ListadoManager::MostrarCantidadProveedores() {
	int cantidadRegistros = _archivoProveedores.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
}
void ListadoManager::ListarTodosProveedores() {

	int cantidadRegistros = _archivoProveedores.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
	Proveedor reg;
	for (int i = 0; i < cantidadRegistros; i++) {
		//Mostrar(_archivoRegistros.Leer(i));
		reg = _archivoProveedores.Leer(i);
		//reg.mostrar();
		//reg.mostrar();
		cout << "Nombre: " << reg.getNombres() << endl;
		cout << "Apellido: " << reg.getApellidos() << endl;
		cout << endl << "CANT: " << i << endl;

	}
}
void ListadoManager::ListarUnidades() {
	int cant = _archivoUnidades.ContarRegistros();
	Unidad u;
	for (int i = 0;i < cant;i++) {
		u = _archivoUnidades.Leer(i);
		u.mostrar();
	}
}
void ListadoManager::ListarRegistros() {
	int cant = _archivoRegistros.ContarRegistros();
	Registro reg;
	for (int i = 0;i < cant;i++) {
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
	}
}

void ListadoManager::ListarUsuarios() {
	int cant = _archivoUsuarios.ContarRegistros();
	Usuario u;
	for (int i = 0;i < cant;i++) {
		u = _archivoUsuarios.Leer(i);
		u.mostrar();
	}
}