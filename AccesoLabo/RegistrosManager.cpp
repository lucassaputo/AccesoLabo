#include "RegistrosManager.h"
#include "Visita.h"
#include "Unidad.h"
#include "Autorizacion.h"
#include "Registro.h"
#include "UserSingleton.h"
#include "FuncionesGlobales.h"


using namespace std;

UserSingleton& s = UserSingleton::getInstance();
// Obtener el objeto desde el Singleton y llamar a su funci�n

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
	system("pause");
	motivo = std::stoi(motivoAux);

	// UNIDAD
	bool validado = false;
	while (true) {
		cout << "Ingrese unidad destino: " << endl;
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
	
	// DNI
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
	//return;
}

void RegistrosManager::registroProveedores(Unidad uni, int dni,  int motivo) {
	Proveedor p;
	int pos;	
	pos = _archivoProveedores.Buscar(dni);
	if (pos >= 0) {
		p = _archivoProveedores.Leer(pos);
		p.mostrar();
		int x = adentro(p.getDni(), motivo, 2);
		if (adentro(p.getDni(), motivo, 2)>-1) {
			egresoProveedor(uni,p,x);
		}
		else {
			ingresoProveedor(uni,p);
		}
	}
	else {
		p.cargarProveedor(dni);
		p.setId(_archivoProveedores.ContarRegistros() + 1);
		_archivoProveedores.Guardar(p);
		cout << "Proveedor guardado correctamente." << endl;
		ingresoProveedor(uni,p);
	}	
	return;
}
void RegistrosManager::ingresoProveedor(Unidad& uni, Proveedor& p) {
	bool vigente = false, permitido = false;
	if (!p.vencido()) {
		cout << "Vencido: " << p.vencido() << endl;
		vigente = true;
		cout << "Esta vigente" << endl;
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
				cout << "OKFecha" << endl;
				break;
			}
		}
		p.setArt(aux);
		vigente = true;
	}

	if (autorizado(uni, p)) {
		permitido = true;
	}
	else {
		char r;
		cout << "No se encuentra autorizado." << endl;
		cout << "Llame al: " << uni.getTelefono() << endl;
		cout << "Fue autorizado el ingreso? S/N";
		cin >> r;
		while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
			cout << "Fue autorizado el ingreso? S/N";
			cin >> r;
		}
		if (r == 'S' || r == 's') {
			permitido = true;
		}
		else {
			cout << "Fin del acceso." << endl;
		}
	}
	if (vigente && permitido) {
		Registro reg;
		char r;
		//reg.setIdUnidad(uni.getId());
		reg.setIdUnidad(uni.getId());
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
	else {
		cout << "AAAAA" << endl;
	}
}
void RegistrosManager::egresoProveedor(Unidad& uni, Proveedor& p, int posActivo) {
	//grabar salida
	//borrar activo
}
int RegistrosManager::adentro(int idPersona,int motivo,int tipoPersona) {
	Registro r;
	int cant = _archivoActivos.ContarRegistros();
	for (int i = 0;i < cant;i++) {
		r = _archivoActivos.Leer(i);
		if (r.getTipoPersona() == motivo && r.getIdPersona() == idPersona && r.getTipoPersona() == tipoPersona && r.getEstado()==true) {
			return i;
		}
	}
	return -1;
}
bool RegistrosManager::autorizado(Unidad uni, Proveedor p) {
	Autorizacion a;
	Fecha hoy;
	int cant = _archivoAutorizaciones.ContarRegistros();
	for (int i = 0;i < cant;i++) {
		a = _archivoAutorizaciones.Leer(i);
		if (a.getIdPersona() == p.getId() && a.getIdUnidad() == uni.getId()) {
			if (!(a.getHasta() < hoy)) {
				return true;
			}
		}
	}
	return false;
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

