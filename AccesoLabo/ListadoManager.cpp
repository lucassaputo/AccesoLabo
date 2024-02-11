#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
using namespace std;
/*
void ListadoManager::AutorizadosPorApellido() {
	system("cls");
	cout << "AutorizadosPorApellido" << endl;
	//MostrarCantidadRegistros();
	//ListarTodos();	
	ListarRegistros();
	system("pause");
	}
 */
void ListadoManager::ListarRegistros() {
	int cant = _archivoRegistros.ContarRegistros();
	Registro reg;
	for (int i = 0;i < cant;i++) {
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
	}
}

void ListadoManager::AutorizadosPorApellido() {
	system("cls");
    cout << "AutorizadosPorApellido" << endl;
	Autorizacion* regAut;
	std::string* ApellidoAutorizados;
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
	}
	regAut = new Autorizacion[cantReg];
	if (regAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}
	ApellidoAutorizados = new std::string[cantReg];
	if (ApellidoAutorizados == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regAut[x] = _archivoAutorizacion.Leer(x);
		if (regAut[x].getTipo() == 1) {
			ApellidoAutorizados[x] = BuscarenVisita(regAut[x].getDNI());
		}
		else if (regAut[x].getTipo() == 2) {
			ApellidoAutorizados[x] = BuscarenProveedor(regAut[x].getDNI());
		}
		else {
			cout << "Error de tipo de autorizado" << endl;
			return;
		}
	}
	OrdenarVectorAutorizadosxApellido(ApellidoAutorizados, cantReg);
	for (int j = 0;j < cantReg;j++) {
		cout << ApellidoAutorizados[j] << endl;
	}
	delete [] ApellidoAutorizados;
	delete [] regAut;

	system("pause");
}
std::string ListadoManager::BuscarenVisita(int dni)
{
	std::string Apellido;
	Persona reg;
	int pos = _archivoPersona.Buscar(dni);
	reg = _archivoPersona.Leer(pos);
	Apellido = reg.getApellidos();
	
	return Apellido;
}
std::string ListadoManager::BuscarenProveedor(int dni)
{
	std::string Apellido;
	Proveedor reg;
	int pos = _archivoProveedores.Buscar(dni);
	reg = _archivoProveedores.Leer(pos);
	Apellido = reg.getApellidos();

	return Apellido;

}
void ListadoManager::OrdenarVectorAutorizadosxApellido(std::string *reg, int tam)
{
	std::string aux;

	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (strcmp(reg[x].c_str(), reg[x + 1].c_str()) > 0) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			
			}
		}
	}
}
void ListadoManager::AutorizadosPorUnidad() {
	system("cls");

	cout << "AutorizadosPorUnidad" << endl;
	Autorizacion *regAut;
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
	}
	regAut = new Autorizacion[cantReg];
	if (regAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regAut[x] = _archivoAutorizacion.Leer(x);
	}
	OrdenarVectorAutorizadosxNumero(regAut, cantReg);
	for (int i = 0;i < cantReg;i++) {
		regAut[i].mostrar();
	}
	delete[] regAut;
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
	Residente *reg;
	int cantReg = _archivoResidente.ContarRegistros();;
	reg = new Residente[cantReg];
	if (reg == nullptr) {
		cout << "error de asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		reg[x] = _archivoResidente.Leer(x);
	}
	OrdenarResidentesxUnidad(reg, cantReg);
	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}
	delete[] reg;
	system("pause");
}
void ListadoManager::OrdenarResidentesxUnidad(Residente* vec, int ram)
{
}
void ListadoManager::ProveedoresPorRazon() {
	system("cls");
	cout << "ProveedoresPorRazon" << endl;
	Proveedor* regProv;
	int cantReg = _archivoProveedores.ContarRegistros();
	regProv = new Proveedor[cantReg];
	if (regProv == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regProv[x] = _archivoProveedores.Leer(x);
	}
	OrdenarVectorProveedoresxRazon(regProv, cantReg);
	for (int i = 0;i < cantReg;i++) {
		regProv[i].mostrar();
	}
	delete[] regProv;

	system("pause");
}

void ListadoManager::OrdenarVectorProveedoresxRazon(Proveedor* reg, int tam)
{
	Proveedor aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (strcmp(reg[x].getApellidos().c_str(), reg[x + 1].getApellidos().c_str())>0) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
}

void ListadoManager::ProveedoresPorDNI() {
	system("cls");
	cout << "Proveedores Por DNI" << endl;
	Proveedor *regProv;
	int cantReg = _archivoProveedores.ContarRegistros();
	regProv = new Proveedor[cantReg];
	if (regProv == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regProv[x] = _archivoProveedores.Leer(x) ;
	}
	OrdenarVectorProveedoresxDNI(regProv, cantReg);

	for (int j = 0;j < cantReg;j++) {
		cout << "j=" << j << endl;
		regProv[j].mostrar();
	}
	delete[] regProv;

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
	int cantReg = _archivoUnidades.ContarRegistros();
	reg = new Unidad[cantReg];
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = _archivoUnidades.Leer(i);
	}
	OrdenarVectorUnidadxNumero(reg, cantReg);
	for (int j = 0;j < cantReg;j++) {
		cout << "j=" << j << endl;
		reg[j].mostrar();
	}
	delete[] reg;
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
void ListadoManager::UnidadesPorFamilia(){
	system("cls");
	cout << "UnidadesPorFamilia" << endl;
	Unidad* reg;
	int cantReg = _archivoUnidades.ContarRegistros();
	reg = new Unidad[cantReg];
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = _archivoUnidades.Leer(i);
	}
	OrdenarVectorUnidadxApellido(reg, cantReg);
	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}
	delete[] reg;
	system("pause");
}

void ListadoManager::OrdenarVectorUnidadxApellido(Unidad* reg, int tam)
{
	Unidad aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (strcmp(reg[x].getFamilia().c_str(), reg[x + 1].getFamilia().c_str()) > 0) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}


}
