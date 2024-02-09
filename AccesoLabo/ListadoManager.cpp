#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
using namespace std;

void ListadoManager::AutorizadosPorApellido() {
	system("cls");
    cout << "AutorizadosPorApellido" << endl;
	Autorizacion* regAut;
	ArchivoAutorizacion archAut("Autorizaciones.dat");
	int cantReg = archAut.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
	}
	regAut = new Autorizacion[cantReg];
	if (regAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regAut[x] = archAut.Leer(x);
	}


	system("pause");
}
void ListadoManager::OrdenarVectorAutorizadosxApellido(Autorizacion* reg, int tam)
{
	Autorizacion aux;

	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			
		}
	}
}
void ListadoManager::AutorizadosPorUnidad() {
	system("cls");

	cout << "AutorizadosPorUnidad" << endl;
	Autorizacion *regAut;
	ArchivoAutorizacion archAut("Autorizaciones.dat");
	int cantReg = archAut.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
	}
	regAut = new Autorizacion[cantReg];
	if (regAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regAut[x] = archAut.Leer(x);
	}
	OrdenarVectorAutorizadosxNumero(regAut, cantReg);
	for (int i = 0;i < cantReg;i++) {
		regAut[i].mostrar();
	}

	system("pause");
}

void ListadoManager::OrdenarVectorAutorizadosxNumero(Autorizacion* reg, int tam)
{
	 Autorizacion aux;
	 
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (reg[x].getId() > reg[x + 1].getId()) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
}


void ListadoManager::ResidentesPorUnidad() {
	system("cls");
	cout << "ResidentesPorUnidad" << endl;
	
	system("pause");
}
void ListadoManager::ProveedoresPorRazon() {
	system("cls");
	//cout << "ProveedoresPorRazon" << endl;
	ListarRegistros();
	system("pause");
}

void ListadoManager::ProveedoresPorDNI() {
	system("cls");
	cout << "Proveedores Por DNI" << endl;
	Proveedor *regProv;
	ArchivoProveedores archProv("Proveedores.dat");
	int cantReg = archProv.ContarRegistros();
	regProv = new Proveedor[cantReg];
	if (regProv == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regProv[x] = archProv.Leer(x);
	}
	OrdenarVectorProveedoresxDNI(regProv, cantReg);

	for (int j = 0;j < cantReg;j++) {
		cout << "j=" << j << endl;
		regProv[j].mostrar();
	}


	system("pause");
}
void ListadoManager::OrdenarVectorProveedoresxDNI(Proveedor* reg, int tam)
{
	Proveedor aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (reg[x].getDni() > reg[x + 1].getDni()) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
}
void ListadoManager::UnidadesPorNumero() {
	system("cls");
	cout << "UnidadesPorNumero" << endl;
	Unidad* reg;
	ArchivoUnidad archU("Unidades.dat");
	cout << "AutorizadosPorUnidad" << endl;
	int cantReg = archU.ContarRegistros();
	reg = new Unidad[cantReg];
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = archU.Leer(i);
	}
	OrdenarVectorUnidadxNumero(reg, cantReg);
	for (int j = 0;j < cantReg;j++) {
		cout << "j=" << j << endl;
		reg[j].mostrar();
	}
	system("pause");
}
void ListadoManager::OrdenarVectorUnidadxNumero(Unidad* reg, int tam)
{
	Unidad aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (reg[x].getId() > reg[x + 1].getId()) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
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

void ListadoManager::MostrarCantidadUnidades() {
	int CantidadUnidades = _archivoUnidades.ContarRegistros();
	cout << endl << "CANTIDAD DE UNIDADES REGISTRADAS: " << CantidadUnidades << endl;
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