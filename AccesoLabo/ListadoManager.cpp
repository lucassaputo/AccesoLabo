#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
#include "ReporteAutorizaciones.h"
#include <fstream> // Incluir la biblioteca para manejar archivos
using namespace std;

/*
void ListadoManager::AutorizadosPorApellido() {
	system("cls");
	cout << "AutorizadosPorApellido" << endl;
	//MostrarCantidadRegistros();
	//ListarTodos();	
	ListarRegistros();
	system("pause");
}*/

void ListadoManager::ListarRegistros() {//testeo
	int cant = _archivoRegistros.ContarRegistros();
	Registro reg;
	for (int i = 0;i < cant;i++) {
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
	}
}

void ListadoManager::AutorizadosPorApellido() {
	system("cls");
    cout << "Autorizados ordenados por apellido" << endl;
	Autorizacion aux;
	ReporteAutorizaciones* vectorAut;
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
	}
	vectorAut = new ReporteAutorizaciones[cantReg];
	if (vectorAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		return;
	}

	for (int i = 0;i < cantReg;i++) {
		aux = _archivoAutorizacion.Leer(i);
		if (aux.getEstado()) {
			vectorAut[i].setId(aux.getId());
			vectorAut[i].setIdPersona(aux.getIdPersona());
			vectorAut[i].setIdUnidad(aux.getIdUnidad());
			vectorAut[i].setTipo(aux.getTipo());
			vectorAut[i].setHasta(aux.getHasta());
			if (aux.getTipo() == 1) { //visita
				vectorAut[i].setApellido(BuscarenVisita(aux.getIdPersona()));
				vectorAut[i].setNombreTipo("Visita");
			}
			else { // proveedor
				vectorAut[i].setApellido(BuscarenProveedor(aux.getIdPersona()));
				vectorAut[i].setNombreTipo("Proveedor");
			}		
		}		
	}

	OrdenarAutorizadosxApellido(vectorAut, cantReg);
	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrar2(); //ver que pasa con los estado false

	}

	//exportar
	char r;
	ReporteAutorizaciones ra;
	cout << "Desea exportar los datos? S/N";
	cin >> r;
	while (r != 'S' && r != 's' && r != 'N' && r != 'n') {
		cout << "Desea exportar los datos? S/N";
		cin >> r;
	}
	if (r == 'S' || r == 's') {
		// Abrir un archivo para escribir
		std::ofstream archivo("listadoAutorizadosPorApellido.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Apellido, fechaHasta, idUnidad\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = vectorAut[i];
				archivo << ra.getApellido() << "," << ra.getHasta().toString() << "," << ra.getIdUnidad() << "\n";
			}
			// Cerrar el archivo
			archivo.close();

			std::cout << "Los datos se han exportado correctamente al archivo.";
		}
		else {
			// Mostrar un mensaje de error si no se pudo abrir el archivo
			std::cerr << "Error al abrir el archivo.";
		}
	}
	else {
		cout << "Accion cancelado.";
	}




	delete [] vectorAut;
	system("pause");
}

std::string ListadoManager::BuscarenVisita(int id)
{
	Persona reg;
	int pos=_archivoVisitas.BuscarId(id);
	reg = _archivoVisitas.Leer(pos);	
	return reg.getApellidos();
}

std::string ListadoManager::BuscarenProveedor(int id)
{
	Proveedor reg;
	int pos = _archivoProveedores.Buscar(id);
	reg = _archivoProveedores.Leer(pos);
	return reg.getApellidos();
}

void ListadoManager::OrdenarAutorizadosxApellido(ReporteAutorizaciones* vec, int tam)
{
	ReporteAutorizaciones aux;

	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (strcmp(vec[x].getApellido().c_str(), vec[x + 1].getApellido().c_str()) > 0) {
				aux = vec[x];
				vec[x] = vec[x + 1];
				vec[x + 1] = aux;
			}
		}
	}
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
	ArchivoResidente archResidente("Residentes.dat");
	int cantReg = archResidente.ContarRegistros();
	reg = new Residente[cantReg];
	if (reg == nullptr) {
		cout << "error de asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		reg[x] = archResidente.Leer(x);
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
