#include "InformesManager.h"
#include <iostream>

void InformesManager::UnidadesMas50()
{	system("cls");
	std::cout << "Unidades con mas de 50 movimientos " << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
	Unidad u;
	Registro reg;
	//buscar idLote maximo
	//crear vector segun maximo
	int cant = _archivoUnidades.ContarRegistros();	
	int maximo = 0;
	for (int i = 0;i < cant;i++) {
		u = _archivoUnidades.Leer(i);
		if (u.getId() > maximo) {
			maximo = u.getId();
		}
	}
	//crear el vector dinamico
	int contRegistros[50] = { };//este iria con el maximo
	//inicializar en cero tb el dinamico
	int cantRegistros = _archivoRegistros.ContarRegistros();
	for (int i = 0;i < cantRegistros;i++) {
		reg = _archivoRegistros.Leer(i);
		contRegistros[reg.getId() - 1]++;
	}
	//sacar los que tengan mas de 50 y listarlos
	//los que tengan mas de 50 chequear el estado del lote antes de listarlo






	system("pause");
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
void InformeProveedores() {

}
void HistorialMovimientosxUnidades() {

}
void HistorialMovimientos() {


}