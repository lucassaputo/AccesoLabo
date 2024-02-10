#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
using namespace std;

void ListadoManager::AutorizadosPorApellido() {
	system("cls");
    cout << "AutorizadosPorApellido" << endl;
	Autorizacion* regAut;
	ArchivoAutorizacion archAut("Autorizaciones.dat");
	std::string* ApellidoAutorizados;
	int cantReg = archAut.ContarRegistros();
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
		regAut[x] = archAut.Leer(x);
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


	system("pause");
}
std::string ListadoManager::BuscarenVisita(int dni)
{
	std::string Apellido;
	Visita reg;
	ArchivoVisita archVisita("Visitas.dat");
	int pos=archVisita.Buscar(dni);
	reg = archVisita.Leer(pos);
	Apellido = reg.getApellidos();
	
	return Apellido;
}
std::string ListadoManager::BuscarenProveedor(int dni)
{
	
	std::string Apellido;
	Proveedor reg;
	ArchivoProveedores archProveedor("Proveedores.dat");
	int pos = archProveedor.Buscar(dni);
	reg = archProveedor.Leer(pos);
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
	cout << "ProveedoresPorRazon" << endl;
	Proveedor* regProv;
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
	OrdenarVectorProveedoresxRazon(regProv, cantReg);
	for (int i = 0;i < cantReg;i++) {
		regProv[i].mostrar();
	}


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
void ListadoManager::UnidadesPorFamilia(){
	system("cls");
	cout << "UnidadesPorFamilia" << endl;
	Unidad* reg;
	ArchivoUnidad archU("Unidades.dat");
	int cantReg = archU.ContarRegistros();
	reg = new Unidad[cantReg];
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = archU.Leer(i);
	}
	OrdenarVectorUnidadxApellido(reg, cantReg);
	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}
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
