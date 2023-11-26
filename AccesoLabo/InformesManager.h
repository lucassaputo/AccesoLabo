#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "Registro.h"
#include "FuncionesGlobales.h"
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
		void ProvedoresIngresados(int mi, int ai, int mf, int af); // cuenta los proveedores ingresados entre dos fechas especificadas
		void ContarMovimientosIndicados(int m, int a);//cuenta los movimientos en un mes y año especificado
		void UnidadesMas50();
		void InformeProveedores();
		void HistorialMovimientosxUnidades(); 
		void ordenarVectorUnidades(int* vec, int tam, Unidad* reg);
		void HistorialMovimientos();

	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

	};

