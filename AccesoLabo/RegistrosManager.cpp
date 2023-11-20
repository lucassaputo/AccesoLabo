#include "RegistrosManager.h"
#include <iostream>
#include "Visita.h"
#include "Unidad.h"
#include "Autorizacion.h"
#include "Registro.h"
#include "Singleton.h"

using namespace std;
Singleton& s = Singleton::getInstance();
// Obtener el objeto desde el Singleton y llamar a su función
//s.getUsuario().mostrar();

void RegistrosManager::Cargar() {
	system("cls");
	int motivo, dni, unidad;
	Unidad uni;
	
	cout << "***********  Nuevo movimiento  ***********" << endl;
	cout << "(1: Visita | 2 : Proveedor | 3 : Residente)" << endl;
	cout << "Ingrese motivo de ingreso: ";
	cin >> motivo;
	while (motivo < 1 || motivo>3) {
		cout << "Motivo invalido." << endl;
		cout << "Ingrese motivo de ingreso:   (1: Visita | 2: Proveedor | 3: Residente) ";
		cin >> motivo;
	}
	cout << "Ingrese unidad destino: ";
	cin >> unidad;
	while (unidad < 1 || unidad>20) {
		cout << "Unidad invalida." << endl;
		cout << "Ingrese unidad destino: " << endl;
		cin >> unidad;
	}
	/*
	uni = buscarUnidad(unidad);
	if (uni.getId() < 0) {
		cout << "Error al encontrar unidad." << endl;
		system("pause");
		return;
	}*/
	uni.setId(unidad);
	cout << "Ingrese DNI: ";
	cin >> dni;
	switch (motivo) {
		case 1://VISITA		
			registroVisitas(uni, dni);		
			break;
		case 2://PROVEEDOR		
			registroProveedores(uni.getId(), dni);
			break;		
		case 3://RESIDENTE
			registroResidentes(uni, dni);
			break;
		default:
			break;
	}	
	system("pause");
	//return;
}

void RegistrosManager::registroProveedores(int uni, int dni) {
	Proveedor p;
	int pos;
	bool vigente = false, autorizado = true;
	pos = _archivoProveedores.Buscar(dni);
	if (pos >= 0) {
		p = _archivoProveedores.Leer(pos);
		p.mostrar();
	}
	else {
		p.cargarProveedor(dni);
		p.setId(_archivoProveedores.ContarRegistros() + 1);
		_archivoProveedores.Guardar(p);
		cout << "Proveedor guardado correctamente." << endl;
	}
	if(!p.vencido()){
		vigente = true;
		//cout << "Esta vigente" << endl;
	}
	else
	{
		Fecha aux;
		cout << "ART vencida, ingrese nueva fecha: " << endl;
		while (aux.ingresarFecha() == false) {
			cout << "Formato invalido, ingrese DD/MM/AA";
			cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
		}
		p.setArt(aux);
		//if(!p.vencido) usar la sobrecarga que pase a fecha
	}

	Autorizacion a;
	a = getAutorizacion(p);
	if (a.getIdUnidad() != -1) {
		autorizado = true;
		a.mostrar();
	}

	if (vigente && autorizado) {
		Registro reg;
		char r;
		//reg.setIdUnidad(uni.getId());
		reg.setIdUnidad(uni);
		reg = p;//sobrecarga asigna ipProveedor y fecha
		reg.setSentido(1);
		reg.setObservaciones("");
		reg.setTipoAutorizacion(1);
		reg.setIdUser(s.getUsuario().getId());
		cout << "Desea dar el siguiente ingreso?S/N";
		cin >> r;
		while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
			cout << "Desea dar el siguiente ingreso?S/N";
			cin >> r;
		}
		if (r == 'S' || r == 's') {
			if (_archivoRegistros.Guardar(reg)) {
				cout << "Registro guardado correctamente." << endl;
				//reg.mostrar();
			}
			else {
				cout << "ERROR al guardar." << endl;
			}
		}
		else {
			cout << "Registro cancelado.";
		}
	}
	return;
}
void RegistrosManager::registroVisitas(Unidad uni, int dni) {

}
void RegistrosManager::registroResidentes(Unidad uni, int dni) {

}
void RegistrosManager::Editar() {
	system("cls");
	cout << "Editar" << endl;
	system("pause");
}

void RegistrosManager::Eliminar() {
	system("cls");
	cout << "Eliminar" << endl;
	system("pause");
}

Unidad RegistrosManager::buscarUnidad(int u) {
	int cant = _archivoUnidades.ContarRegistros();
	Unidad uni;
	uni.setId(-1);
	for (int i = 0;i < cant;i++) {
		uni = _archivoUnidades.Leer(i);
		if (uni.getId() == u) {
			return uni;
		}
	}
	return uni;
}
Autorizacion RegistrosManager::getAutorizacion(Proveedor &p) {
	Autorizacion a;
	a.setIdUnidad(-1);
	int cant = _archivoAutorizaciones.ContarRegistros();
	for (int i = 0;i < cant;i++) {
		a = _archivoAutorizaciones.Leer(i);
		if (a.getIdPersona() == p.getId()) {
			//chequear fecha, unidad, etc...
			return a;
		}
	}
	return a;
}