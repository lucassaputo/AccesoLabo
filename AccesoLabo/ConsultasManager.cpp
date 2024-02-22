#include "ConsultasManager.h"
#include <iostream>
#include "ReporteAutorizaciones.h"
#include <fstream>

using namespace std;

//"1 - Consulta de autorizados por Unidad"
void ConsultasManager::ConsultaAutorizadosxUnidad() {
	system("cls");
	Autorizacion aux;
	Unidad u;
	Persona per;
	ReporteAutorizaciones ra;
	ReporteAutorizaciones* vectorAut;
	cout << "++++++ Consulta autorizados por unidad ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	u = ingresarUnidad("a consultar");
	int cantReg = _archivoAutorizacion.ContarRegistros();

	vectorAut = new ReporteAutorizaciones[cantReg];
	if (vectorAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		system("pause");
		return;
	}
	int cont = 0;
	Fecha hoy;
	for (int i = 0;i < cantReg;i++) {
		aux = _archivoAutorizacion.Leer(i);
		if (aux.getEstado() && aux.getHasta()>= hoy) {
		//if (aux.getEstado()) {
			cont++;
			vectorAut[i].setIdUnidad(aux.getIdUnidad());
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
	if (cont == 0) {
		cout << "No hay autorizaciones cargadas" << endl;
		system("pause");
		return;
	}

	OrdenarAutXApellido(vectorAut, cont);

	cabeceraAutorizados();

	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrarReporte();
	}

	ExportarAutorizaciones(vectorAut, cont, "consulta1");

	delete[] vectorAut;
	system("pause");
}

//"2 - Consulta de autorizados por Apellido"
void ConsultasManager::ConsultaAutorizadosxApellido() {
	system("cls");
	Autorizacion aux;
	Fecha hoy;
	Unidad u;
	Persona per;
	string apellido;
	int motivo;
	int id;
	int cont = 0;
	ReporteAutorizaciones ra;
	ReporteAutorizaciones* vectorAut;
	cout << "++++++ Consulta autorizados por apellido ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	motivo = ingresarMotivo();
	cin.ignore();
	apellido = upper(cargarStringTam("Apellido", 50));

	int cantReg = _archivoAutorizacion.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay autorizaciones cargadas" << endl;
		system("pause");
		return;
	}
	vectorAut = new ReporteAutorizaciones[cantReg];
	if (vectorAut == nullptr) {
		cout << "Error de asignacion de memoria " << endl;
		system("pause");
		return;
	}

	if (motivo == 1) //visita
	{
		Persona vis = _archivoVisitas.BuscarObjApellido(apellido);
		//vis.mostrar();
		if (vis.getDni() > -1) {
			
			for (int i = 0;i < cantReg;i++) {
				aux = _archivoAutorizacion.Leer(i);
				if (aux.getEstado() && aux.getIdPersona() >= vis.getId() && aux.getHasta() >= hoy) {
					cont++;
					vectorAut[i].setIdUnidad(aux.getIdUnidad());
					vectorAut[i].setNombre(vis.getNombres());
					vectorAut[i].setApellido(vis.getApellidos());
					vectorAut[i].setNombreTipo("Visita");
					vectorAut[i].setHasta(aux.getHasta());
				}	
			}
		}
		else {
			cout << "La persona ingresada no existe." << endl;
			system("pause");
			return;
		}
	}
	else // proveedor
	{
		Proveedor prov = _archivoProveedores.BuscarObjApellido(apellido);
		if (prov.getDni() > -1) {
			for (int i = 0;i < cantReg;i++) {
				aux = _archivoAutorizacion.Leer(i);
				if (aux.getEstado() && aux.getIdPersona() >= prov.getId() && aux.getHasta() >= hoy) {
					cont++;
					vectorAut[i].setIdUnidad(aux.getIdUnidad());
					vectorAut[i].setNombre(prov.getNombres());
					vectorAut[i].setApellido(prov.getApellidos());
					vectorAut[i].setNombreTipo("Proveedor");
					vectorAut[i].setHasta(aux.getHasta());
				}
			}
		}
		else {
			cout << "La persona ingresada no existe." << endl;
			system("pause");
			return;
		}
	}

	if (cont == 0) {
		cout << "No hay autorizaciones cargadas" << endl;
		system("pause");
		return;
	}

	OrdenarAutXApellido(vectorAut, cont);

	cabeceraAutorizados();

	for (int j = 0;j < cantReg;j++) {
		vectorAut[j].mostrarReporte();
	}

	ExportarAutorizaciones(vectorAut, cont, "consulta2");

	delete[] vectorAut;
	system("pause");
}

//"3 - Consulta de residentes por Unidad"
void ConsultasManager::ConsultaResidentesxUnidad() {
	system("cls");
	std::string unidad;
	Residente p;
	Unidad u;
	int cont = 0;
	cout << "++++++ Consulta residentes por unidad ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
	u = ingresarUnidad("a consultar");
	int cantReg = _archivoResidente.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de residentes cargados" << endl;
		system("pause");
		return;
	}	
	for (int x = 0;x < cantReg;x++) {
		p = _archivoResidente.Leer(x);
		if (p.getEstado() && p.getUnidad() == u.getId()) {
			p.mostrar();
			cont++;
		}
	}
	if (cont == 0) {
		cout << "No hay Residentes dados de alta en esa unidad funcional" << endl;
		system("pause");
		return;
	}
	//ordenar
		//exportar
	system("pause");
}

//"4 - Consulta de residentes por Apellido"
void ConsultasManager::ConsultaResidentesxApellido() {
		system("cls");
		Residente p;
		int cont = 0;
		std::string apellido;
		cout << "++++++ Consulta residentes por apellido ++++++" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cin.ignore();
		apellido = upper(cargarStringTam("Apellido", 50));

		int cantReg = _archivoResidente.ContarRegistros();
		if (cantReg == 0) {
			cout << "No hay registros de residentes cargados" << endl;
			system("pause");
			return;
		}
		for (int x = 0;x < cantReg;x++) {
			p = _archivoResidente.Leer(x);
			if (p.getEstado() && p.getApellidos() == apellido) {
				p.mostrar();
				cont++;
			}
		}
		if (cont == 0) {
			cout << "No hay residentes dados de alta en esa unidad funcional con el apellido proporcionado." << endl;
			system("pause");
			return;
		}

		//ordenar
		//exportar

		system("pause");
	}

//"5 - Consulta de proveedores por Razon Social"
void ConsultasManager::ConsultaProveedoresxRazonSocial() {
	system("cls");
	Proveedor prov;
	std::string empresa;
	cout << "++++++ Consulta proveedores por empresa ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cin.ignore();
	empresa = upper(cargarStringTam("Empresa", 50));
	int cantReg = _archivoProveedores.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de proveedores cargados" << endl;
		system("pause");
		return;
	}
	int cont = 0;
	for (int x = 0;x < cantReg;x++) {
		prov = _archivoProveedores.Leer(x);
		if (prov.getEstado() && prov.getEmpresa()== empresa) {
			prov.mostrar();
			cont++;
		}
	}
	if (cont == 0) {
		cout << "No hay proveedores dados de alta con esa empresa." << endl;
		system("pause");
		return;
	}

	//ordenar 
	//reporte

	system("pause");
}

//"6 - Consulta de Proveedores por DNI"
void ConsultasManager::ConsultaProveedoresxCUIT() {
	system("cls");
	Proveedor prov;
	cout << "++++++ Consulta proveedores por DNI ++++++" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cin.ignore();
	int dni = cargarDni();
	int cantReg = _archivoProveedores.ContarRegistros();
	if (cantReg == 0) {
		cout << "No hay registros de proveedores cargados con ese DNI." << endl;
		system("pause");
		return;
	}
	int cont = 0;
	for (int x = 0;x < cantReg;x++) {
		prov = _archivoProveedores.Leer(x);
		if (dni == prov.getDni()) {
			prov.mostrar();
			cont++;
		}
	}
	if (cont == 0) {
		cout << "No hay proveedores dados de alta con ese DNI" << endl;
		system("pause");
		return;

	}

	//ordenar
	//exportar

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


	
