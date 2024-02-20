#include "RegistrosManager.h"
#include "Visita.h"
#include "Unidad.h"
#include "Autorizacion.h"
#include "Registro.h"
#include "UserSingleton.h"
#include "FuncionesGlobales.h"
#include "Residente.h"

using namespace std;

UserSingleton& s = UserSingleton::getInstance();

void RegistrosManager::Cargar() {
	system("cls");
	string dniAux, unidadAux, motivoAux;
	int motivo, unidad,dni;
	Unidad uni;
	
	cout << "***********  Nuevo movimiento  ***********" << endl;
	
	// IN MOTIVO
	cout << "(1: Visita | 2 : Proveedor | 3 : Residente)" << endl;
	cout << "Ingrese motivo de ingreso: ";
	cin.ignore();
	cin >> motivoAux;
	while (soloNumeros(motivoAux)==false || !(motivoAux=="1" || motivoAux == "2" || motivoAux == "3")) {
		cout << "Motivo invalido." << endl;
		cout << "Ingrese motivo de ingreso:   (1: Visita | 2: Proveedor | 3: Residente) ";
		cin >> motivoAux;
	}
	motivo = std::stoi(motivoAux);

	// IN UNIDAD
	bool validado = false;
	while (true) {
		cout << "Ingrese unidad destino: ";
		cin.ignore();
		cin >> unidadAux;
		while (soloNumeros(unidadAux) == false) {
			cout << "Solo puede contener numeros, Ingrese unidad destino: ";
			cin.ignore();
			cin >> unidadAux;
		}
		uni = buscarUnidad(std::stoi(unidadAux));		
		if (uni.getId() >= 0) {
			break;
		}
		else {
			cout << "La unidad ingresada no existe." << endl;			
		}
	}	
	
	// IN DNI
	cout << "Ingrese DNI: ";
	cin.ignore();
	cin >> dniAux;
	while (soloNumeros(dniAux) == false || !(dniAux.size()<10 && dniAux.size()>6)) {
		cout << "DNI invalido, Ingrese DNI: ";
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
			registroProveedores(uni, dni,motivo);
			break;		
		case 3://RESIDENTE
			registroResidentes(uni, dni);
			break;
		default:
			break;
	}	
	system("pause");
}

void RegistrosManager::registroProveedores(Unidad uni, int dni,  int motivo) {
	Proveedor p;
	p = _archivoProveedores.BuscarObj(dni);
	if (p.getDni() > -1) {
		if (p.getEstado()) {
			if (adentro(p.getId(), motivo)) {
				egreso(uni, p, 2);
			}
			else {
				ingresoProveedor(uni, p);
			}
		}
		else {
			p.cargarProveedor(dni);
			if (_archivoProveedores.Modificar(p)) {
				cout << "Proveedor guardado correctamente." << endl;
				ingresoProveedor(uni, p);
			}
			else {
				cout << "Error al guardar proveedor." << endl;
			}
		}
	}
	else {
		p.cargarProveedor(dni);
		p.setId(_archivoProveedores.ContarRegistros() + 1);
		if (_archivoProveedores.Guardar(p)) {
			cout << "Proveedor guardado correctamente." << endl;
			ingresoProveedor(uni, p);
		}
		else {
			cout << "Error al guardar proveedor." << endl;
		}
	}
	return;
}

void RegistrosManager::registroVisitas(Unidad uni, int dni) {
	Persona p;
	p = _archivoVisitas.BuscarObj(dni);
	if (p.getDni() > -1) {
		if (p.getEstado()) {
			if (adentro(p.getId(), 1)) {
				egreso(uni, p, 1);
			}
			else {
				ingresoVisita(uni, p, 1);
			}
		}
		else {
			p.cargarPersona();
			if (_archivoVisitas.Modificar(p)) {
				cout << "Visita guardado correctamente." << endl;
				ingresoVisita(uni, p, 1);
			}
			else {
				cout << "Error al guardar visita." << endl;
			}
		}
	}
	else {
		p.setDni(dni);
		p.cargarPersona();
		p.setId(_archivoVisitas.ContarRegistros() + 1);
		if (_archivoVisitas.Guardar(p)) {
			cout << "Visita guardado correctamente." << endl;
			ingresoVisita(uni, p, 1);
		}
		else {
			cout << "Error al guardar visita." << endl;
		}
	}
	return;
}

void RegistrosManager::registroResidentes(Unidad uni, int dni) {
	Residente p;
	p = _archivoResidentes.BuscarObj(dni);
	if (p.getDni() > -1) {
		if (p.getEstado()) {
			if (adentro(p.getId(), 3)) {
				egreso(uni, p, 3);
			}
			else {
				ingresoResidente(uni,p,3);
			}
		}
		else {
			p.cargarResidente();
			if (_archivoResidentes.Modificar(p)) {
				cout << "Residente guardado correctamente." << endl;
				ingresoResidente(uni, p, 3);
			}
			else {
				cout << "Error al guardar residente." << endl;
			}
		}
	}
	else {
		p.setDni(dni);
		p.cargarResidente();
		p.setId(_archivoResidentes.ContarRegistros() + 1);
		if (_archivoResidentes.Guardar(p)) {
			cout << "Residente guardado correctamente." << endl;
			ingresoResidente(uni, p, 3);
		}
		else {
			cout << "Error al guardar residente." << endl;
		}
	}
	return;
}

void RegistrosManager::ingresoVisita(Unidad& uni, Persona& p, int motivo) {
	int permitido = checkAutorizacion(uni, p.getId(), 1);
	if (permitido<3) {
		guardar(uni, p,1,permitido);
	}
}

void RegistrosManager::ingresoResidente(Unidad& uni, Residente& p, int motivo) {
	Fecha hoy;
	if (!p.getPropietarioInquilino()) {//es inquilino
		if (p.getFechaHasta() >= hoy) {
			guardar(uni, p, 3, 0);
		}
		else {
			cout << "La persona tiene el contrato vencido." << endl;
		}
	}
	else {
		guardar(uni, p, 3, 0);
	}
}

void RegistrosManager::ingresoProveedor(Unidad& uni, Proveedor& p) {
	bool vigente = false;
	int permitido = 3;
	vigente = !vencido(p);
	permitido = checkAutorizacion(uni, p.getId(), 2);

	if (vigente && permitido<3) {
		guardar(uni, p,2,permitido);
	}
}

void RegistrosManager::egreso(Unidad& uni, Persona& p, int motivo) {
	cout << "EGRESO" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Registro reg;
	bool banderaEncontrado = false;
	int cant = _archivoRegistros.ContarRegistros();
	for (int i = cant;i > -1;i--) {
		reg = _archivoRegistros.Leer(i);
		if (reg.getIdPersona() == p.getId() && reg.getEstado() == true) {
			if (reg.getAdentro()) {
				banderaEncontrado = true;
				break;
			}
		}
	}	
	if (banderaEncontrado) {
		if (!(uni.getId() == reg.getIdUnidad())) {
			cout << "La persona se encuentra dentro del barrio pero en una unidad distinta a la ingresada, se procedera con la salida del lote al que ingreso." << endl;
		}
		if (!(motivo == reg.getTipoAutorizacion())) {
			cout << "La persona se encuentra dentro del barrio pero con otro motivo, se procedera con la salida con el motivo que ingreso." << endl;
		}
		char r;
		cout << "Desea guardar la salida de " << p.getNombres() << " " << p.getApellidos() << " del lote " << uni.getId() << "? S / N";
		std::cin >> r;
		while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
			cout << "Desea guardar la salida de " << p.getNombres() << " " << p.getApellidos() << " del lote " << uni.getId() << "? S / N";
			cin >> r;
		}
		if (r == 'S' || r == 's') {
			FechaHorario aux;
			reg.setAdentro(false);
			reg.setFechaEgreso(aux);
			if (_archivoRegistros.Modificar(reg)) {
				cout << "Salida guardada correctamente." << endl;
			}
			else {
				cout << "ERROR al guardar." << endl;
			}
		}
		else {
			cout << "Registro cancelado.";
		}
	}
	else {
		cout << "ERROR al guardar." << endl;
	}
}

bool RegistrosManager::adentro(int idPersona, int motivo) {
	Registro r;
	int cant = _archivoRegistros.ContarRegistros();
	for (int i = cant;i >-1;i--) {
		r = _archivoRegistros.Leer(i);		
		//if (r.getTipoPersona() == motivo && r.getIdPersona() == idPersona && r.getEstado() == true) {
		if (r.getIdPersona() == idPersona && r.getEstado() == true) {
			if (r.getAdentro()) {
				return true;
			}
		}
	}
	return false;
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

bool RegistrosManager::vencido(Proveedor p) {
	if (!p.vencido()) {
		return false;
	}
	else
	{
		Fecha aux;
		Fecha hoy;
		cout << "ART vencida, ingrese nueva fecha: " << endl;
		bool pasado = true;
		while (true) {
			while (aux.ingresarFecha() == false) {
				cout << "Formato invalido, ingrese DD/MM/AA";
				cout << "Ingrese fecha vencimiento (DD/MM/AA): ";
			}
			if (!(aux > hoy)) {
				cout << "La fecha ingresada debe ser mayor a hoy." << endl;
			}
			else {
				p.setArt(aux);
				if (_archivoProveedores.Modificar(p)) {
					cout << "Vencimiento modificado correctamente" << endl;
					return false;
				}
				else {
					cout << "Error al modificar vencimiento." << endl;
				}
			}
		}
		return true;
	}
}

int RegistrosManager::checkAutorizacion(Unidad u, int idPersona, int motivo) {
	if (autorizado(u, idPersona,motivo)) {
		return 1;//autorizacion cargada previamente
	}
	else {
		char r;
		cout << "No se encuentra autorizado." << endl;
		cout << "Llame al: " << u.getTelefono() << endl;
		cout << "Fue autorizado el ingreso? S/N: ";
		cin >> r;
		while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
			cout << "Fue autorizado el ingreso? S/N: ";
			cin >> r;
		}
		if (r == 'S' || r == 's') {
			return 2;//autorizacion telefonica
		}
		else {
			cout << "Fin del acceso." << endl;			
		}
	}
	return 3;//no autorizado
}

bool RegistrosManager::autorizado(Unidad uni, int idPersona,int motivo) {
	Autorizacion a;
	Fecha hoy;
	int cant = _archivoAutorizaciones.ContarRegistros();
	for (int i = cant;i >= -1 ;i--) {
		a = _archivoAutorizaciones.Leer(i);
		if (a.getIdPersona() == idPersona && a.getIdUnidad() == uni.getId() && a.getTipo()==motivo && a.getEstado()) {
			if (!(a.getHasta() < hoy)) {
				return true;
			}
		}
	}
	return false;
}

void RegistrosManager::guardar(Unidad uni,Persona p, int motivo,int autorizacion) {
	Registro reg;
	char r;
	reg.setId(_archivoRegistros.ContarRegistros() + 1);
	reg.setIdUnidad(uni.getId());
	reg = p;//sobrecarga asigna idPersona y fecha
	reg.setAdentro(true);
	reg.setTipoPersona(motivo);
	reg.setTipoAutorizacion(autorizacion);
	reg.setIdUser(s.getUsuario().getId());
	reg.setEstado(true);
	//reg.mostrar();
	cout << "Desea guardar el ingreso de " << p.getNombres() << " " << p.getApellidos() << " a la unidad " << uni.getId() << "? S / N";
	cin >> r;
	while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
		cout << "Desea guardar el ingreso de " << p.getNombres() << " " << p.getApellidos() << " a la unidad " << uni.getId() << "? S / N";
		cin >> r;
	}
	if (r == 'S' || r == 's') {
		if (_archivoRegistros.Guardar(reg)) {
			cout << "Registro guardado correctamente." << endl;
		}
		else {
			cout << "ERROR al guardar." << endl;
		}
	}
	else {
		cout << "Registro cancelado.";
	}
}
