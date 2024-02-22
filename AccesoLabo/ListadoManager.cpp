#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
#include "ReporteAutorizaciones.h"
#include <fstream> // Incluir la biblioteca para manejar archivos
#include <iomanip>
#include "FuncionesGlobales.h"

using namespace std;

//"1 - Listado de autorizados, ordenados por apellido"
void ListadoManager::AutorizadosPorApellido() {
	system("cls");
	cout << "++++++ Autorizados ordenados por apellido ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Autorizacion aux;
	ReporteAutorizaciones* vectorAut;
	ReporteAutorizaciones ra;
	Persona persona;
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay autorizaciones cargadas" << endl;
		return;
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
				Persona per = BuscarenVisita(aux.getIdPersona());
				vectorAut[i].setNombre(per.getNombres());
				vectorAut[i].setApellido(per.getApellidos());
				vectorAut[i].setNombreTipo("Visita");
			}
			else { // proveedor
				Proveedor pro = BuscarenProveedor(aux.getIdPersona());
				vectorAut[i].setNombre(pro.getNombres());
				vectorAut[i].setApellido(pro.getApellidos());
				vectorAut[i].setNombreTipo("Proveedor");
			}		
		}		
	}

	OrdenarAutorizadosxApellido(vectorAut, cantReg);

	cabeceraAutorizados();
	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrarReporte();
	}

	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado1.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Nombre,Apellido, Motivo, Unidad, Hasta\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = vectorAut[i];
				archivo << ra.getNombre() << "," << ra.getApellido() << "," << ra.getNombreTipo() << "," << ra.getIdUnidad() << "," << ra.getHasta().toString() << "\n";
			}
			// Cerrar el archivo
			archivo.close();

			std::cout << "Los datos se han exportado correctamente al archivo.";
		}
		else {
			std::cout << "Error al abrir el archivo.";
		}
	}
	else {
		cout << "Accion cancelado.";
	}

	delete [] vectorAut;	
	system("pause");
}

//"2 - Listado de autorizados, ordenados por unidad"
void ListadoManager::AutorizadosPorUnidad() {
	system("cls");
	cout << "++++++ Autorizados ordenados por unidad ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Autorizacion aux;
	ReporteAutorizaciones* vectorAut;
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizados cargados" << endl;
		return;
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
				Persona per = BuscarenVisita(aux.getIdPersona());
				vectorAut[i].setNombre(per.getNombres());
				vectorAut[i].setApellido(per.getApellidos());
				vectorAut[i].setNombreTipo("Visita");
			}
			else { // proveedor
				Proveedor pro = BuscarenProveedor(aux.getIdPersona());
				vectorAut[i].setNombre(pro.getNombres());
				vectorAut[i].setApellido(pro.getApellidos());
				vectorAut[i].setNombreTipo("Proveedor");
			}
		}
	}

	OrdenarAutorizadosxNumero(vectorAut, cantReg);

	cabeceraAutorizados();
	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrarReporte();
	}

	//exportar	
	ReporteAutorizaciones ra;	
	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado2.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Nombre,Apellido, Motivo, Unidad, Hasta\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = vectorAut[i];
				archivo << ra.getNombre() << "," << ra.getApellido() << "," << ra.getNombreTipo() << "," << ra.getIdUnidad() << "," << ra.getHasta().toString() << "\n";
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
	delete[] vectorAut;	
	system("pause");
}

//"3 - Listado de residentes, ordenados por unidad"
void ListadoManager::ResidentesPorUnidad() {
	system("cls");
	cout << "++++++ Residentes ordenados por unidad ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Residente res;
	int cant = _archivoResisente.ContarRegistros();
	cout << "Cant: " << cant << endl;
	/*Residente *reg;
	int cantReg = _archivoResisente.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros cargados" << endl;
	}
	reg = new Residente[cantReg];
	if (reg == nullptr) {
		cout << "error de asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		reg[x] = _archivoResisente.Leer(x);
	}
	OrdenarResidentesxUnidad(reg, cantReg);
	cout << left;
	cout << setw(3) << "id";
	cout << setw(10) << " | nombre";
	cout << setw(10) << " | apellido";
	cout << setw(8) << " | dni";
	cout << setw(1) << " | Unidad";
	cout << setw(1) << " | desde";
	cout << setw(1) << " | propietario/inquilino" << endl;
	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}
	delete[] reg;
	*/
	
	system("pause");
}

//"4 - Listado de proveedores, ordenados por razon social"
void ListadoManager::ProveedoresPorRazon() {
	system("cls");
	cout << "++++++ Proveedores ordenados por razon social ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Proveedor* regProv;

	int cantReg = _archivoProveedores.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros cargados" << endl;
		return;
	}
	regProv = new Proveedor[cantReg];
	if (regProv == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regProv[x] = _archivoProveedores.Leer(x);
	}

	OrdenarVectorProveedoresxRazon(regProv, cantReg);

	cabeceraProveedores();

	for (int i = 0;i < cantReg;i++) {
		regProv[i].mostrar();
	}

	//exportar	
	Proveedor ra;
	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado4.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Nombre,Apellido, DNI, Empresa, ART\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = regProv[i];
				archivo << ra.getNombres() << "," << ra.getApellidos() << "," << ra.getDni() << "," << ra.getEmpresa() << "," << ra.getArtFecha().toString() << "\n";
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

	delete[] regProv;
	system("pause");
}

//"5 - Listado de proveedores, ordenados por DNI"
void ListadoManager::ProveedoresPorDNI() { // punto 5
	system("cls");
	cout << "++++++ Proveedores ordenados por DNI ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
	Proveedor *regProv;
	int cantReg = _archivoProveedores.ContarRegistros();
	regProv = new Proveedor[cantReg];
	if (cantReg == 0) {
		cout << "No hay registros cargados" << endl;
		return;
	}
	if (regProv == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		regProv[x] = _archivoProveedores.Leer(x);
	}

	OrdenarVectorProveedoresxDNI(regProv, cantReg);
	cabeceraProveedores();
	for (int j = 0;j < cantReg;j++) {
		regProv[j].mostrar();
	}

	//exportar	
	Proveedor ra;
	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado5.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Nombre,Apellido, DNI, Empresa, ART\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = regProv[i];
				archivo << ra.getNombres() << "," << ra.getApellidos() << "," << ra.getDni() << "," << ra.getEmpresa() << "," << ra.getArtFecha().toString() << "\n";
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

	delete[] regProv;
	system("pause");
}

//"6 - Listado de unidades, ordenados por numero"
void ListadoManager::UnidadesPorNumero() { // punto 6
	cout << "++++++ Unidades ordenadas por numero +++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	system("cls");
	Unidad* reg;
	int cantReg = _archivoUnidades.ContarRegistros();
	reg = new Unidad[cantReg];
	if (cantReg == 0) {
		cout << "No hay registros cargados" << endl;
		return;
	}
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = _archivoUnidades.Leer(i);
	}

	OrdenarVectorUnidadxNumero(reg, cantReg);
	caberaUnidades();

	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}

	//exportar	
	Unidad ra;
	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado6.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Numero,Familia,Telefono,Observaciones\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = reg[i];
				archivo << ra.getId() << "," << ra.getFamilia() << "," << ra.getTelefono() << "," << ra.getObservaciones() << "\n";
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

	delete[] reg;
	system("pause");
	
}

//"7 - Listado de unidades, ordenados por apellido familia"
void ListadoManager::UnidadesPorFamilia(){
	system("cls");
	cout << "+++++ Unidades ordenados por familia +++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	Unidad* reg;
	int cantReg = _archivoUnidades.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros cargados" << endl;
		return;
	}
	reg = new Unidad[cantReg];
	if (reg == nullptr) {
		cout << "Error de asignacion de memoria" << endl;
		return;
	}
	for (int i = 0;i < cantReg;i++) {
		reg[i] = _archivoUnidades.Leer(i);
	}

	OrdenarVectorUnidadxApellido(reg, cantReg);
	caberaUnidades();

	for (int j = 0;j < cantReg;j++) {
		reg[j].mostrar();
	}

	//exportar	
	Unidad ra;
	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado7.txt");

		// Verificar si el archivo se abrió correctamente
		if (archivo.is_open()) {
			archivo << "Numero,Familia,Telefono,Observaciones\n";
			// Escribir datos en el archivo
			for (int i = 0; i < cantReg;i++) {
				ra = reg[i];
				archivo << ra.getId() << "," << ra.getFamilia() << "," << ra.getTelefono() << "," << ra.getObservaciones() << "\n";
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

	delete[] reg;
	system("pause");
}

Persona ListadoManager::BuscarenVisita(int id)
{
	Persona reg;
	int pos=_archivoVisitas.BuscarId(id);
	reg = _archivoVisitas.Leer(pos);	
	return reg;
}

Proveedor ListadoManager::BuscarenProveedor(int id)
{
	Proveedor reg;
	int pos = _archivoProveedores.Buscar(id);
	reg = _archivoProveedores.Leer(pos);
	return reg;
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

void ListadoManager::OrdenarAutorizadosxNumero(ReporteAutorizaciones* vec, int tam)
{
	ReporteAutorizaciones aux;

	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (vec[x].getIdUnidad(), vec[x + 1].getIdUnidad()) {
				aux = vec[x];
				vec[x] = vec[x + 1];
				vec[x + 1] = aux;
			}
		}
	}
}

void ListadoManager::OrdenarVectorAutorizadosxNumero(Autorizacion* reg, int tam)
{
	 Autorizacion aux;
	 
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (reg[x].getIdUnidad() > reg[x + 1].getIdUnidad()) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
}

void ListadoManager::OrdenarResidentesxUnidad(Residente* reg, int tam)
{
	Residente aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (reg[x].getUnidad() > reg[x + 1].getUnidad()) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}

}

void ListadoManager::OrdenarVectorProveedoresxRazon(Proveedor* reg, int tam)
{
	Proveedor aux;
	for (int i = 0;i < tam;i++) {
		for (int x = 0;x < tam - i - 1;x++) {
			if (strcmp(reg[x].getEmpresa().c_str(), reg[x + 1].getEmpresa().c_str())>0) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
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
