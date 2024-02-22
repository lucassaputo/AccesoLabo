#include "InformesManager.h"
#include <iostream>
using namespace std;
void InformesManager::UnidadesMas50() // punto 1
{	system("cls"); cout << "||| Unidades con más de 50 movimientos||| "<< endl;
//int mes, anio;
 cout << " en este reporte se informará según el mes y año que ingrese el usuario las unidades con más de 50 movimientos. ";
	Fecha fi;
	fi.ingresarMes_Anio();	
	Unidad u;
	Registro reg;
	 int maximo = ID_Maximo(); 
	int* contMovimientos;
	int cant = _archivoUnidades.ContarRegistros(); // contador registros de unidades
	if (cant == 0) {
		cout << "no hay registros de unidad" << endl;
		return;
	}
	contMovimientos = new int[maximo]();
	if (contMovimientos == nullptr) {
		cout << "error en la asignacion de memoria" << endl;
		return;
	}
	int cantRegistros = _archivoRegistros.ContarRegistros(); // contador de registros de archivoregistros
	for (int i = 0;i < cantRegistros;i++) {
		reg = _archivoRegistros.Leer(i);
		if (reg.getFechaIngreso().getFecha().getMes() == fi.getMes() && reg.getFechaIngreso().getFecha().getAnio()==fi.getAnio()) {
			contMovimientos[reg.getIdUnidad() - 1]++;
		}
	}
	Mostrar50(contMovimientos, cant);
	delete[] contMovimientos;

	//los que tengan mas de 50 chequear el estado del lote antes de listarlo  ----> por que? quizas nos interesa saber en un periodo que estaba activa la unidad
	//
	

	system("pause");
}

int InformesManager::ID_Maximo()
{
	int CantRegU=0,ID_Max = 0;
	int* vecID;
	Unidad reg;
	CantRegU = _archivoUnidades.ContarRegistros();
	vecID = new int [CantRegU];
	if (vecID==nullptr) {
		cout << "Error en la asignacion de memoria" << endl;
		return 0;
	}
	for (int x = 0;x < CantRegU;x++) {
		reg = _archivoUnidades.Leer(x);
		vecID[x] = reg.getId();
	}	
	for (int i = 0;i < CantRegU;i++) {
		if (vecID[i] > ID_Max) {
			ID_Max = vecID[i];
		}
	}
	delete[]vecID;
	return ID_Max;
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
		cout << "Ninguna unidad registrro mas de 50 movimientos en la fecha seleccionada" << endl;
	}
}


void InformesManager::InformeProveedores() // punto 2
{	system("cls");
	Fecha FechaInicial, FechaFinal;
	std::cout << "Informe de Proveedores " << std::endl;
	cout << "Este informe nos brindará entre dos fechas a elección del usuario los proveedores que ingresaron al Barrio. " << endl;
	// pedir al usuario fecha inicial y final para buscar en ese rango el ingreso de proveedores
	cout << "Fecha inicial: " << endl;
	FechaInicial.ingresarFecha();
	cout << "Fecha final: " << endl;
	FechaFinal.ingresarFecha();
	Registro *reg;
	int cantReg = _archivoRegistros.ContarRegistros();
	reg = new Registro[cantReg];
	if (reg == nullptr) {
		cout << "error en la asignacion de memoria" << endl;
		return;
	}
	CargarVectorRegistros(reg, cantReg);
	MostrarMovimientos(FechaInicial, FechaFinal, reg, cantReg);

	system("pause");
}

void InformesManager::CargarVectorRegistros(Registro *reg, int cant)
{
	for (int x = 0;x < cant;x++) {
		reg[x] = _archivoRegistros.Leer(x);
	}
}

void InformesManager::CargarVectorProveedores(Proveedor* reg, int cant)
{
	for (int x = 0;x < cant;x++) {
		reg[x] = _archivoProveedores.Leer(x);
	}
}

void InformesManager::MostrarMovimientos(Fecha fi, Fecha ff, Registro* reg, int cant)
{
	Fecha fechamov;
	FechaHorario FechaHoraMostrar;
	int contMuestras = 0;
	int cantRegp = _archivoProveedores.ContarRegistros();
	Proveedor* RegProv;
	RegProv = new Proveedor[cantRegp];
	if (RegProv == nullptr) {
		cout << "error de asignacion de memoria" << endl;
		return;
	}
	CargarVectorProveedores(RegProv, cantRegp);
	for (int i = 0;i < cant;i++) {
		fechamov = reg[i].getFechaIngreso().getFecha();
		FechaHoraMostrar = reg[i].getFechaIngreso();
		if (fechamov>=fi && fechamov<=ff) {
			for (int j = 0;j < cantRegp;j++) {
				if (reg[i].getIdPersona()==RegProv[j].getId()) {
					cout << "Fecha y Horario del movimiento: " << FechaHoraMostrar.toString() << endl;
					cout << "Datos del proveedor: " << endl;
					RegProv[j].mostrar();
					contMuestras++;
				}
			}
		}

	}
	if (contMuestras == 0) {
		cout << "No hubo movimientos de proveedores en la fecha seleccionada" << endl;
	}
		
}

void InformesManager::HistorialMovimientosxUnidades() // punto 3
{
	system("cls");
	cout << "Historial de movimientos por unidades" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Este informe mostrara las unidades con mas y menos movimientos registrados historicamente. " << endl;
	int* contMovimientos;
	int maxID = ID_Maximo();
	int CantUni = _archivoUnidades.ContarRegistros();
	int cant = _archivoRegistros.ContarRegistros();
	Unidad* regU;
	Registro reg;	
	regU = new Unidad[CantUni];
	if (regU == nullptr) {
		cout << "error de asignacion de memoria" << endl;
		return;
	}
	if (cant == 0) {
		cout << "   ***   No hay registros de movimientos cargados   ***   " << endl;
		system("pause");
		return;
	}
	contMovimientos = new int[maxID]();
	if (contMovimientos == nullptr) {
		cout << "error en la asignacion de memoria" << endl;
		return;
	}
	
	CargarvectorUnidades(regU, CantUni);
		for (int i = 0;i < cant;i++) {
		reg = _archivoRegistros.Leer(i);		 
			contMovimientos[reg.getIdUnidad() - 1]++;
	}	

		int aux = 0;
		for (int i = 0;i < cant;i++) {
			for (int x = 0;x < cant - i - 1;x++) {
				if (contMovimientos[x] > contMovimientos[x + 1]) {
					aux = contMovimientos[x];
					contMovimientos[x] = contMovimientos[x + 1];					
					contMovimientos[x + 1] = aux;					
				}
			}
		}	
		Unidad uMayor, uMenor;
		int contMenor = 0,cantmenor=0;
		for (int x = 0;x < CantUni-1;x++) { // en CantUni -1 xq en la ultima posicion esta el mayor
			if (contMovimientos[x]>0) {
				uMenor = regU[x];
				contMenor++;
				cantmenor = contMovimientos[x];
				break;
			}
		}
				uMayor = regU[CantUni-1];
			
		cout << "Unidad con mayor Movimientos: " << endl;
		uMayor.mostrar();
		cout << "Cantidad de Movimientos: " << contMovimientos[cant - 1] << endl;
		cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		if (contMenor > 0) {
			cout << "Unidad con menor Movimientos: " << endl;
			uMenor.mostrar();
			cout << "Cantidad de movimientos" << cantmenor << endl;
		}
		else {
			cout << "solo una unidad registro movimientos" << endl;
		}
	
	delete[] contMovimientos;
	delete[] regU;
	system("pause");
}

void InformesManager::CargarVectorIndices(int* vecIndices, int tam)
{
	for (int x = 0;x < tam;x++) {
		vecIndices[x] = x + 1;
	}
}
void InformesManager::CargarvectorUnidades(Unidad* u, int cant)
{
	for (int x = 0;x < cant;x++) {
		u[x] = _archivoUnidades.Leer(x);
	}
}

void InformesManager::MovimientosMensuales() // punto 4
{	system("cls");
	cout << "Movimientos Mensuales" << endl;
	cout << "+++++++++++++++++++++++++++++++" << endl;
	cout << "Este informe  brinda los movimientos entre las fechas que desee." << endl;
	Registro reg;
	Fecha fechaInicial, fechaFinal;
	cout << "Ingrese la fecha inicial: " << endl;
	fechaInicial.ingresarFecha();
	cout << "Ingrese la fecha final: " << endl;
	fechaFinal.ingresarFecha();
	
	while (fechaInicial > fechaFinal) {
		cout << "La fecha inicial no puede ser mayor a la fecha final" << endl;
		cout << "Ingrese la fecha inicial: " << endl;
		fechaInicial.ingresarFecha();
		cout << "Ingrese la fecha final: " << endl;
		fechaFinal.ingresarFecha();
	}
	int contmov = 0;
	int cant = _archivoRegistros.ContarRegistros();
	for (int x = 0;x < cant;x++) {
		Fecha fechaRegistro;
		reg = _archivoRegistros.Leer(x);
		fechaRegistro = reg.getFechaIngreso().getFecha();
		if (fechaRegistro >= fechaInicial && fechaRegistro <= fechaFinal) {
			cout << "fecha movimiento: " << fechaRegistro.toString();
			reg.mostrar(); 
			contmov++;
		}

	}
	if (contmov == 0) {
		cout << "No hay movimientos en el rango seleccionado" << endl;
	}

	system("pause");
}
