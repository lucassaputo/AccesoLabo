#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "ArchivoRegistro.h"
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
		void UnidadesMas50();// punto 1
		void InformeProveedores(); // Punto 2
		void MovimientosPorUnidad(); // punto 3
		void Mostrar50(int *vec, int tam);

	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

	};

