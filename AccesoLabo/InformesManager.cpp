#include "InformesManager.h"
#include <iostream>

using namespace std;

//punto 1
void InformesManager::UnidadesMas50() {
	system("cls"); cout << "++++++ Unidades con más de 50 movimientos ++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "En este reporte se informará según el mes y año que ingrese el usuario las unidades con más de 50 movimientos. ";
	Fecha fi;
	fi.ingresarMes_Anio();
	//Unidad u;
	Registro reg;	
	int cantUnidades = _archivoUnidades.ContarRegistros();
	int* contMovimientos;
	
	contMovimientos = new int[cantUnidades]();
	if (contMovimientos == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		system("pause");
		return;
	}
	int cantRegistros = _archivoRegistros.ContarRegistros();
	for (int i = 0;i < cantRegistros;i++) {
		reg = _archivoRegistros.Leer(i);
		if (reg.getFechaIngreso().getFecha().getMes() == fi.getMes() && reg.getFechaIngreso().getFecha().getAnio() == fi.getAnio()) {
			contMovimientos[reg.getIdUnidad() - 1]++;
		}
	}

	Mostrar50(contMovimientos, cantUnidades);
	delete[] contMovimientos;
	system("pause");
}

// punto 2
void InformesManager::InformeProveedores(){	
	system("cls");
	Fecha FechaInicial, FechaFinal;
	Registro *vector;
	Registro reg;
	std::cout << "++++++ Informe de proveedores ++++++" << std::endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Este informe nos brindará entre dos fechas a elección del usuario los proveedores que ingresaron al Barrio. " << endl;
	
	FechaInicial = ingresarFechaDesdeReporte();
	FechaFinal = ingresarFechaHastaReporte();

	int cantReg = _archivoRegistros.ContarRegistros();
	vector = new Registro[cantReg];

	if (vector == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		system("pause");
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		reg = _archivoRegistros.Leer(x);
		if (reg.getFechaIngreso().getFecha() >= FechaFinal && reg.getFechaIngreso().getFecha() <= FechaFinal && reg.getTipoPersona()== 2) {
			reg.mostrarReporte();//faltan apellidos y nombres y tipos

			//Proveedor pro = BuscarenProveedor(aux.getIdPersona());
			//vectorAut[i].setNombre(pro.getNombres());
			//vectorAut[i].setApellido(pro.getApellidos());
			//vectorAut[i].setNombreTipo("Proveedor");


		}				
	}

	delete[] vector;
	system("pause");
}

//punto 3
void InformesManager::MovimientosPorUnidad(){
	system("cls");
	Fecha FechaInicial, FechaFinal;
	Registro* vector;
	Registro reg;
	Unidad u;
	std::cout << "++++++ Informe de proveedores ++++++" << std::endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Este informe nos brindará entre dos fechas a elección del usuario los proveedores que ingresaron al Barrio al lote seleccionado." << endl;

	FechaInicial = ingresarFechaDesdeReporte();
	FechaFinal = ingresarFechaHastaReporte();
	u = ingresarUnidad("a consultar");

	int cantReg = _archivoRegistros.ContarRegistros();
	vector = new Registro[cantReg];
	if (vector == nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		system("pause");
		return;
	}
	for (int x = 0;x < cantReg;x++) {
		reg = _archivoRegistros.Leer(x);
		if (reg.getFechaIngreso().getFecha() >= FechaFinal && reg.getFechaIngreso().getFecha() <= FechaFinal && reg.getIdUnidad()==u.getId()) {
			reg.mostrar();//faltan apellidos y nombres y tipos
		}
	}

	delete[] vector;
	system("pause");
}

void InformesManager::Mostrar50(int* vec, int tam)
{	
	int cont = 0;
	for (int x = 0;x < tam;x++) {
		if (vec[x] > 50) {
			cout << "La Unidad Funcional: " << x + 1 << " tiene " << vec[x] << " movimientos " << endl;
			cont++;
		}
	}
	if (cont == 0) {
		cout << "Ninguna unidad registro mas de 50 movimientos en la fecha seleccionada" << endl;
		return;
	}
}


