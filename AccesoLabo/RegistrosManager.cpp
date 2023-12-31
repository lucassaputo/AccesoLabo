#include "RegistrosManager.h"
#include "Visita.h"
#include "Unidad.h"
#include "Autorizacion.h"
#include "Registro.h"
#include "Singleton.h"
#include "FuncionesGlobales.h"


using namespace std;
Singleton& s = Singleton::getInstance();
// Obtener el objeto desde el Singleton y llamar a su función
//s.getUsuario().mostrar();



void RegistrosManager::Cargar() {
	system("cls");
	string dniAux, unidadAux, motivoAux;
	int motivo, unidad,dni;
	Unidad uni;
	
	cout << "***********  Nuevo movimiento  ***********" << endl;
	
	// MOTIVO
	cout << "(1: Visita | 2 : Proveedor | 3 : Residente)" << endl;
	cout << "Ingrese motivo de ingreso: ";
	cin.ignore();
	cin >> motivoAux;
	while (soloNumeros(motivoAux)==false || !(motivoAux=="1" || motivoAux == "2" || motivoAux == "3")) {
		cout << "Motivo invalido." << endl;
		cout << "Ingrese motivo de ingreso:   (1: Visita | 2: Proveedor | 3: Residente) ";
		cin >> motivoAux;
	}	
	cout << "aca";
	system("pause");
	motivo = std::stoi(motivoAux);

	// UNIDAD
	cout << "Ingrese unidad destino: ";
	cin.ignore();
	cin >> unidadAux;
	while (soloNumeros(unidadAux) == false) {
		cout << "Solo puede contener numeros, Ingrese unidad destino: ";
		cin.ignore();
		cin >> unidadAux;
	}
	uni = buscarUnidad(std::stoi(unidadAux));
	cout << "TTTTTTT: " << uni.getId() << endl;
	while (uni.getId() < 0) {
		cout << "Unidad invalida." << endl;
		cout << "Ingrese unidad destino: " << endl;
		cin >> unidad;
		uni = buscarUnidad(unidad);
	}	
	// DNI
	cout << "Ingrese DNI: ";
	cin.ignore();
	cin >> dniAux;
	while (soloNumeros(dniAux) == false) {
		cout << "Solo puede contener numeros, Ingrese DNI: ";
		cin.ignore();
		cin >> dniAux;
	}
	dni = std::stoi(dniAux);

	// LOGICA
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
	cout << "FX u: " << u << endl;//
	int cant = _archivoUnidades.ContarRegistros();
	Unidad uni;
	Unidad aux;
	uni.setId(-1);
	for (int i = 0;i < cant;i++) {
		aux = _archivoUnidades.Leer(i);
		if (aux.getId() == u) {
			cout << "ACAAAA" << endl;
			return aux;
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

