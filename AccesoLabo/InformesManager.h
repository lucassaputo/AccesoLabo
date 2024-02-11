#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "ArchivoRegistro.h"

/*
		cout << "**************     INFORMES     **************" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "1 - Unidades con mas de 50 movimientos" << endl;
		cout << "2 - Informe Proveedores" << endl;
		cout << "3 - Historial de Movimientos de Unidades" << endl;
		cout << "4 - Historial de Movimientos" << endl;
*/
class InformesManager
{	
	public:
		void UnidadesMas50();// punto 1
		int ID_Maximo();
		void Mostrar50(int *vec, int tam);
		void InformeProveedores(); // Punto 2
		void CargarVectorRegistros(Registro *reg, int cant);
		void CargarVectorProveedores(Proveedor *reg, int cant);
		void MostrarMovimientos(Fecha fi, Fecha ff, Registro* reg, int cant);
		void HistorialMovimientosxUnidades(); // punto 3
		void CargarVectorIndices(int* vecIndices, int tam);
		void OrdenarVectorEnterosxNumero(int* reg, int tam);
		void CargarvectorUnidades(Unidad* u, int cant);
		void HistorialMovimientos(); // punto 4

	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

	};

