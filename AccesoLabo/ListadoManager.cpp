#include "ListadoManager.h"
#include "Registro.h"
#include <iostream>
#include "ReporteAutorizaciones.h"
#include <fstream> // Incluir la biblioteca para manejar archivos
#include <iomanip>
using namespace std;

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

	cout << left;
	cout << setw(2) << "ID";
	cout << setw(9) << " |idPersona";
	cout << setw(9) << "|idUnidad";
	//cout << setw(1) << " || idTipo: ";
	cout << setw(12) << "|Apellido";
	cout << setw(12) << "|NombreTipo";
	cout << setw(15) << "|Autorizado hasta" << endl;
	int cont = 0;
	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrar2(); //ver que pasa con los estado false
		cont++;
	}
	if (cont == 0) {
		cout << endl;
		cout << "no hay registros de autorizaciones para mostrar" << endl;
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
/*Autorizacion *regAut;
	int cantReg =  _archivoAutorizacion.ContarRegistros(), cantRegPersonas= _archivoVisitas.ContarRegistros(), cantRegProveedores = _archivoProveedores.ContarRegistros() ;
	Persona per;
	Proveedor prov;
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
	cout << left ;
	cout << setw(3) << "ID: ";
	cout << setw(3) << " | idPersona: " ;
	cout << setw(3) << " | idUnidad: " ;
	cout << setw(3) << " | idTipo: " ;
	cout << setw(10) << " | Autorizado hasta: ";
	cout << setw(3) << " | Estado: " << endl;
	for (int i = 0;i < cantReg;i++) {
		if (regAut[i].getTipo() == 1) {
			for (int j = 0;j < cantRegPersonas;j++) {
				per = _archivoVisitas.Leer(j);
				if (regAut[i].getIdPersona() == per.getId()) { //  get id persona o get dni??
					per.mostrar();
				}
			}
		}
		else if (regAut[i].getTipo() == 2) {
			for (int j = 0;j < cantRegProveedores;j++) {
				prov = _archivoProveedores.Leer(j);
				if (regAut[i].getIdPersona() == prov.getId()) { //  get id persona o get dni??
					//int id = regAut[i].getIdUnidad();
					//cout << "ID :" << id << " ";
					prov.mostrar();
				}
			}
		}
	}
	delete[] regAut;*/
void ListadoManager::AutorizadosPorUnidad() {
	system("cls");
	cout << "AutorizadosPorUnidad" << endl;
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
// orenar por numero

	cout << left;
	cout << setw(2) << " || ID: ";
	cout << setw(10) << " || idPersona: ";
	cout << setw(10) << " || idUnidad: ";
	cout << setw(10) << " || idTipo: ";
	cout << setw(10) << " || Apellido: ";
	cout << setw(10) << " || NombreTipo: ";
	cout << setw(15) << " || Autorizado hasta: " << endl;
	int cont = 0;
	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrar2(); //ver que pasa con los estado false
		cont++;
	}
	if (cont == 0) {
		cout << endl;
		cout << "no hay registros de autorizaciones para mostrar" << endl;
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
		std::ofstream archivo("listadoAutorizadosPorUnidad.txt");

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




	delete[] vectorAut;
	
	system("pause");
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

void ListadoManager::ResidentesPorUnidad() { // punto 3
	system("cls");
	cout << "ResidentesPorUnidad" << endl;
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
void ListadoManager::ProveedoresPorRazon() { // punto 4
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
	cout << left;
	cout << setw(2) << "id";
	cout << setw(10) << " | nombre";
	cout << setw(12) << " | apellido";
	cout << setw(12) << " | dni";
	//cout << setw(1) << " | estado";
	//cout << setw(1) << " | tipo";
	cout << setw(25) << " | Empresa";
	cout << setw(8) << " | art" << endl;
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
			if (strcmp(reg[x].getEmpresa().c_str(), reg[x + 1].getEmpresa().c_str())>0) {
				aux = reg[x];
				reg[x] = reg[x + 1];
				reg[x + 1] = aux;
			}
		}
	}
}

void ListadoManager::ProveedoresPorDNI() { // punto 5
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
		regProv[x] = _archivoProveedores.Leer(x);
	}
	OrdenarVectorProveedoresxDNI(regProv, cantReg);
	cout << left;
	cout << setw(2) << "id";
	cout << setw(10) << " | nombre";
	cout << setw(12) << " | apellido";
	cout << setw(12) << " | dni";
	//cout << setw(1) << " | estado";
	//cout << setw(1) << " | tipo";
	cout << setw(25) << " | Empresa";
	cout << setw(8) << " | art" << endl;
	for (int j = 0;j < cantReg;j++) {
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


void ListadoManager::UnidadesPorNumero() { // punto 6
	cout << "UnidadesPorNumero" << endl;
	system("cls");
	
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

	cout << left;
	cout << setw(2) << "ID ";
	cout << setw(8) << " | telefono ";
	cout << setw(8) << " | Familia ";
	cout << setw(15) << "| Observaciones" << endl;

		for (int j = 0;j < cantReg;j++) {
			//cout << "j=" << j << endl;	

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
void ListadoManager::UnidadesPorFamilia(){ // punto 7
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


	cout << left;
	cout << setw(2) << "ID ";
	cout << setw(10) << " | telefono ";
	cout << setw(10) << " | Familia ";
	cout << setw(10) << "| Observaciones" << endl;

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
