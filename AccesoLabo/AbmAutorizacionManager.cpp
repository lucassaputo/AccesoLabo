#include "AbmAutorizacionManager.h"
#include <iostream>
#include "FuncionesGlobales.h"
using namespace std;

void AbmAutorizacionManager::Alta()
{
	system("cls");
	int motivo, dni;
	Unidad uni;
	Autorizacion au;

	cout << "***********  Alta autorizacion  ***********" << endl;

	motivo = ingresarMotivo();
	uni = ingresarUnidad("a autorizar");//valida que exista;
	dni = cargarDni();

	if (motivo == 1) //visita
	{
		Persona vis = _archivoVisitas.BuscarObj(dni);
		vis.mostrar();
		if (vis.getDni() > 5000000) {
			if (vis.getEstado()) {
				altaAutorizacion(vis.getId(), 1, uni.getId());
			}
			else {
				cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
			}
		}
		else {
			cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
		}
	}
	else // proveedor
	{
		Proveedor prov = _archivoProveedores.BuscarObj(dni);
		if (prov.getDni() > 5000000) {
			if (prov.getEstado()) {
				altaAutorizacion(prov.getId(), 2, uni.getId());
			}
			else {
				cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
			}
		}
		else {
			cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
		}
	}
	system("pause");
}

void AbmAutorizacionManager::Editar()
{
	system("cls");
	int motivo, dni;
	Unidad uni;
	Autorizacion au;

	cout << "***********  Edicion autorizacion  ***********" << endl;

	motivo = ingresarMotivo();
	uni = ingresarUnidad("a editar");
	dni = cargarDni();

	if (motivo == 1) //visita
	{
		Persona vis = _archivoVisitas.BuscarObj(dni);
		if (vis.getDni() > 5000000) {
			if (vis.getEstado()) {
				editarAutorizacion(vis.getId(), 1, uni.getId());
				system("pause");
				return;
			}
		}
	}
	else // proveedor
	{
		Proveedor prov = _archivoProveedores.BuscarObj(dni);
		if (prov.getDni() > 5000000) {
			if (prov.getEstado()) {
				editarAutorizacion(prov.getId(), 2, uni.getId());
				system("pause");
				return;
			}
		}
	}
	cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
	system("pause");
}

void AbmAutorizacionManager::Baja()
{
	system("cls");
	int motivo, dni;
	Unidad uni;
	Autorizacion au;

	cout << "***********  Baja autorizacion  ***********" << endl;

	motivo = ingresarMotivo();
	uni = ingresarUnidad("a eliminar");//valida que exista;
	dni = cargarDni();

	if (motivo == 1) //visita
	{
		Persona vis = _archivoVisitas.BuscarObj(dni);
		if (vis.getDni() != -1) {
			if (vis.getEstado()) {
				bajaAutorizacion(vis.getId(), 1, uni.getId());
			}
			else {
				cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
			}
		}
		else {
			cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
		}
	}
	else // proveedor
	{
		Proveedor prov = _archivoProveedores.BuscarObj(dni);
		if (prov.getDni() != -1) {
			if (prov.getEstado()) {
				bajaAutorizacion(prov.getId(), 2, uni.getId());
			}
			else {
				cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
			}
		}
		else {
			cout << "La persona ingresada no existe, proceda a dar el alta y regrese aqui." << endl;
		}
	}
	system("pause");	
}

void AbmAutorizacionManager::altaAutorizacion(int idPersona, int motivo, int unidad) {
	Autorizacion aux;
	Fecha hasta;
	aux = _archivoAutorizacion.BuscarObj(idPersona, motivo, unidad);
	if (aux.getId() != -1) {
		if (aux.getEstado()) {
			cout << "La autorizacion ya existe, la puede modificar desde edicion." << endl;
		}
		else {
			aux.setIdPersona(idPersona);
			aux.setIdUnidad(unidad);
			aux.setTipo(motivo);
			aux.setHasta(ingresarFechaAutorizacion());
			aux.setEstado(true);
			if (_archivoAutorizacion.Modificar(aux)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
		}
	}
	else {
		aux.setId(_archivoAutorizacion.ContarRegistros() + 1);
		aux.setIdPersona(idPersona);
		aux.setIdUnidad(unidad);
		aux.setTipo(motivo);
		aux.setHasta(ingresarFechaAutorizacion());
		aux.setEstado(true);
		if (_archivoAutorizacion.Guardar(aux)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "Error al guardar." << endl;
		}
	}
	return;
}

void AbmAutorizacionManager::editarAutorizacion(int idPersona, int motivo, int unidad) {
	Autorizacion aux;
	Fecha hasta;
	aux = _archivoAutorizacion.BuscarObj(idPersona, motivo, unidad);
	aux.mostrar();
	cout << "HOLA";
	if (aux.getId() != -1) {
		if (aux.getEstado()) {
			aux.setHasta(ingresarFechaAutorizacion());
			if (_archivoAutorizacion.Modificar(aux)) {
				cout << "Registro guardado correctamente." << endl;
			}
			else {
				cout << "Error al guardar." << endl;
			}
			return;
		}
	}
	cout << "La 111autorizacion ya existe, la puede modificar desde edicion." << endl;
	return;
}

void AbmAutorizacionManager::bajaAutorizacion(int idPersona, int motivo, int unidad) {
	Autorizacion aux;
	string decision;
	aux = _archivoAutorizacion.BuscarObj(idPersona, motivo, unidad);
	if (aux.getId() != -1) {
		if (aux.getEstado()) {
			cout << "Desea dar la baja de la autorizacion? S/N : ";
			cin.ignore();
			cin >> decision;
			while (soloNumeros(decision) || !(decision == "S" || decision == "s" || decision == "N" || decision == "n")) {
				cout << "Ingrese S (si) o N (no)." << endl;
				cout << "Desea darle la baja? S/N:";
				cin >> decision;
			}
			if (decision == "S" || decision == "s") {
				aux.setEstado(false);
				if (_archivoAutorizacion.Modificar(aux)) {
					cout << "Registro eliminado correctamente." << endl;
				}
				else {
					cout << "Error al guardar." << endl;
				}
			}
			else {
				cout << "Accion cancelada." << endl;
			}
			return;
		}
	}
	cout << "La autorizacion no existe, la puede crear desde alta." << endl;
	return;
}