#include "ConsultasManager.h"
#include <iostream>
#include "ReporteAutorizaciones.h"
#include <fstream>

using namespace std;

//"1 - Consulta de autorizados por Unidad"
void ConsultasManager::ConsultaAutorizadosxUnidad() {
	system("cls");
	std::string unidad;
	Autorizacion aux;
	Unidad u;
	Persona per;
	ReporteAutorizaciones ra;
	ReporteAutorizaciones* vectorAut;
	cout << "++++++ Consulta autorizados por unidad ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	u = ingresarUnidad("a consultar");
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizaciones cargados" << endl;
		system("pause");
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
			//chequear que la fecha este vigente
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

	//ordenar por algo

	cabeceraAutorizados();

	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrarReporte();
	}

	if (decisionExportar()) {
		// Abrir un archivo para escribir
		std::ofstream archivo("listado1.txt");

		// Verificar si el archivo se abri� correctamente
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

	delete[] vectorAut;
	system("pause");
}

//"2 - Consulta de autorizados por Apellido"
void ConsultasManager::ConsultaAutorizadosxApellido() {
	system("cls");
	cout << "++++++ Consulta autorizados por apellido ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	Autorizacion aut;
	Persona per;
	cout << "+++++++++++++++++++++++++++++++" << endl;
	cout << "Ingrese el apellido: " << endl;
	std::string Apellido = cargarApellido();
	for (char& c : Apellido) {
		c = std::toupper(c);
	}
	cout << "Apellido " << Apellido << endl;
	int cantregPersonas = _archivoPersona.ContarRegistros();
	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de autorizaciones cargados" << endl;
	}
	else {
		int ContMuestras = 0;
		int idAutorizado = 0;
		for (int x = 0;x < cantReg;x++) {
			aut = _archivoAutorizacion.Leer(x);
			idAutorizado = aut.getIdPersona();
			for (int i = 0;i < cantregPersonas;i++) {
				per = _archivoPersona.Leer(i);
				if (idAutorizado==per.getId()) {
					per.mostrar();
					ContMuestras++;
					//break;
				}
			}			
			
		}
		if (ContMuestras == 0) {
			cout << "No hay autorizaciones asignadas con ese apellido" << endl;
		}
	}
	system("pause");
}

//"3 - Consulta de residentes por Unidad"
void ConsultasManager::ConsultaResidentesxUnidad() {// punto 3
	system("cls");
	std::string unidad;
	Residente res;
	cout << "++++++ Consulta residentes por unidad ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Ingrese el numero de Unidad: " << endl;
	unidad = ingresarIdUnidad();
	Unidad u;
	u = buscarUnidad(stoi(unidad));
	if (u.getId() == -1) {
		cout << "no existe una unidad con ese ID" << endl;
		system("pause");
		return;
	}
	int cantReg = _archivoResidente.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de Residentes cargados" << endl;
	}
	else {
		int ContMuestras = 0;
		for (int x = 0;x < cantReg;x++) {
			res = _archivoResidente.Leer(x);

			if (res.getUnidad() == stoi(unidad)) {
				res.mostrar();
				ContMuestras++;
				//break;
			}
		}
		if (ContMuestras == 0) {
			cout << "No hay Residentes dados de alta en esa Unidad Funcional" << endl;
		}
	}

	system("pause");
}

//"4 - Consulta de residentes por Apellido"
void ConsultasManager::ConsultaResidentesxApellido() {// punto 4
		system("cls");
		Residente res;
		cout << "++++++ Consulta residentes por apellido ++++++" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Ingrese el Apellido: " << endl;
		std::string Apellido = cargarApellido();
	
		int cantReg = _archivoResidente.ContarRegistros();
		if (cantReg == 0) {
			cout << "No hay registros de Residentes cargados" << endl;
		}
		else {
			int ContMuestras = 0;
			for (int x = 0;x < cantReg;x++) {
				res = _archivoResidente.Leer(x);

				if (strcmp(res.getApellidos().c_str(), Apellido.c_str()) == 0) {
					res.mostrar();
					ContMuestras++;
				}
			}
			if (ContMuestras == 0) {
				cout << "No hay Residentes dados de alta eb esa Unidad Funcional" << endl;
			}
			system("pause");
		}
	}

//"5 - Consulta de proveedores por Razon Social"
void ConsultasManager::ConsultaProveedoresxRazonSocial() { // punto 5
	system("cls");
	Proveedor prov;
	cout << "++++++ Consulta proveedores por empresa ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Inhgrese la razon Social: " << endl;
	std::string RazonSocial = cargarNombre();
	int cantReg = _archivoProveedores.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de proveedores cargados" << endl;
	}
	else {
		int ContMuestras = 0;
		for (int x = 0;x < cantReg;x++) {
			prov = _archivoProveedores.Leer(x);
			if (strcmp(prov.getEmpresa().c_str(), RazonSocial.c_str()) == 0) {
				prov.mostrar();
				ContMuestras++;
				//break;
			}
		}
		if (ContMuestras == 0) {
			cout << "No hay proveedores dados de alta con esa Razon Social" << endl;
		}
	}

	system("pause");
}

//"6 - Consulta de Proveedores por DNI"
void ConsultasManager::ConsultaProveedoresxCUIT() { // punto 6
	system("cls");
	Proveedor prov;
	cout << "++++++ Consulta proveedores por DNI ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	//cout << "Inhgrese el DNI: " << endl;
	std::string DNI = std::to_string(cargarDni());
	int cantReg = _archivoProveedores.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de proveedores cargados" << endl;
	}
	else {
		int ContMuestras = 0;
		for (int x = 0;x < cantReg;x++) {
			prov = _archivoProveedores.Leer(x);
			if (stoi(DNI) == prov.getDni()) {
				prov.mostrar();
				ContMuestras++;
				//break;
			}
		}
		if (ContMuestras == 0) {
			cout << "No hay proveedores dados de alta con ese DNI" << endl;
		}
	}
	system("pause");
	}

//"7 - Consulta de unidades por Nombre"
void ConsultasManager::ConsultaUnidadesxNombre() {// punto 7
	system("cls");
	cout << "++++++ Consulta unidades por nombre ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Inhgrese el Apellido de la familia: " << endl;
	Unidad uni;
	std::string Apellido = cargarNombre();
	int cantReg = _archivoUnidades.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de Unidades cargados" << endl;
	}
	else {
		int ContMuestras = 0;
		for (int x = 0;x < cantReg;x++) {
			uni = _archivoUnidades.Leer(x);
			if (strcmp(uni.getFamilia().c_str(), Apellido.c_str()) == 0) {
				uni.mostrar();
				ContMuestras++;
				//break;
			}
		}
		if (ContMuestras == 0) {
			cout << "No hay unidades dadas de alta con ese apellido" << endl;
		}
	}
	system("pause");
}


	
