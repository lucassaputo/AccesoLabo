#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "Registro.h"
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
		void UnidadesMas50();
		void InformeProveedores();
		void HistorialMovimientosxUnidades(); // cambiamos nombre por Historial Registros?
		void HistorialMovimientos();

	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

	};

