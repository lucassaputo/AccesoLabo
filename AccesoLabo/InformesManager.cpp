#include "InformesManager.h"
#include <iostream>
using namespace std;
void InformesManager::UnidadesMas50()
{
	system("cls");

	fi.ingresarFecha();
	Unidad u;
	Registro reg;
	int maximo = ID_Maximo();
	int* contMovimientos;
	int cant = _archivoUnidades.ContarRegistros(); // contador registros de unidades
	if (cant == 0) {
		cout << "no hay registros de unidad" << endl;
		return;
	}
	contMovimientos = new int[cant]();
	if (contMovimientos == nullptr) {
		cout << "error en la asignacion de memoria" << endl;
		return;
	}
	int cantRegistros = _archivoRegistros.ContarRegistros(); // contador de registros de archivoregistros
	for (int i = 0;i < cantRegistros;i++) {
		reg = _archivoRegistros.Leer(i);
		if (reg.getFechaIngreso() == fi) {
			contMovimientos[reg.getId() - 1]++;
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
	for (int i = 0;i < CantRegU-1;i++) {
		if (vecID[i] > ID_Max) {
			ID_Max = vecID[i];
		}
	}
	delete[]vecID;
	return ID_Max;
}

void InformesManager::Mostrar50(int* vec, int tam)
{
	for (int x = 0;x < tam;x++) {
		if (vec[x] > 50) {
			cout << "La Unidad Funcional: " << x + 1 << " tiene mas de 50 movimientos " << endl;
		}
	}
}


void InformesManager::InformeProveedores()
{	system("cls");
	std::cout << "Informe de Proveedores " << std::endl;
	system("pause");
}

void InformesManager::HistorialMovimientosxUnidades()
{
	system("cls");
	std::cout << "Historial de movimientos por unidades" << std::endl;
	system("pause");
}

void InformesManager::HistorialMovimientos()
{	system("cls");
	std::cout << "Historial de movimientos " << std::endl;
	system("pause");
}
#include "InformesManager.h"
using namespace std;
void UnidadesMas50() {
	system("cls");
	int mes, anio;
	cout << "unidades con mas de 50 movimientos" << endl;
	cout << "Ingrese el mes: " << endl;
	cin >> mes;
	cout << "Ingrese el anio: " << endl;
	cin >> anio;









}
