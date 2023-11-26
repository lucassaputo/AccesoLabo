#include "InformesManager.h"
#include <iostream>

void InformesManager::ProvedoresIngresados(int mi, int ai, int mf, int af)
{
	ArchivoRegistro archRegistro("Registros.dat");
	Registro regRegistro;
	Proveedor* regProveedores=nullptr;
	ArchivoProveedores arcProveedores("Proveedores.dat") ;
	int *vecContador;// cada posicion es equivalente a la posicion del vector de proveedores. si tiene mas de 0 significa que hizo movimientos
	int cantP = 0, cant=0;

	cantP = arcProveedores.ContarRegistros();
	/*regRegistro = new Registro[cant];
	if (regRegistro == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1); // revisar de q otra manera volver
	}*/
	vecContador = new int[cantP];
	if (vecContador == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);// revisar de q otra manera volver
	}
	ponerenCeroVector(vecContador, cantP);
	for (int x = 0;x < cantP;x++) {
		regProveedores[x] = arcProveedores.Leer(x);
	}
	int cantReg = archRegistro.ContarRegistros();
	for (int j = 0; j < cantReg;j++) {
		regRegistro = archRegistro.Leer(j);
		for (int k = 0;k < cantP;k++) {
			if (regRegistro.getSentido() == 2) {
				if (regRegistro.getFecha().getMes() >= mi && regRegistro.getFecha().getMes() <= mf && regRegistro.getFecha().getAnio() >= ai && regRegistro.getFecha().getAnio() <= af) {
					if(regRegistro.getIdPersona() == regProveedores[j].getId()) {
						vecContador[j]++;
					}
				}
			
		     }

		}
	}
	std::cout << "Proveedores Ingresados en la fecha solicitada: " << std::endl;

	for (int i = 0;i < cantP;i++) {
		if (vecContador[i] > 0) {
			regProveedores[i].mostrar();
			std::cout << "Ingreso: " << vecContador[i] << " veces " << std::endl;
		}
	}

}

void InformesManager::ContarMovimientosIndicados(int m, int a)
{
	int* vecCantidad;
	ArchivoUnidad archUnidad("Unidades.dat");
	Unidad* regUnidad = nullptr;
	ArchivoRegistro archRegistro("Registros.dat");
	Registro regRegistro;
	int cant = archUnidad.ContarRegistros(), cant2 = archRegistro.ContarRegistros();
	regUnidad = new Unidad[cant];
	if (regUnidad == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);// revisar de q otra manera volver
			}	
	 vecCantidad= new int[cant];
	if (vecCantidad == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);// revisar de q otra manera volver
			}
	ponerenCeroVector(vecCantidad, cant);
	for (int x = 0;x < cant;x++) {
		regUnidad[x] = archUnidad.Leer(x);
}
	for (int i = 0;i < cant2;i++) {
		regRegistro = archRegistro.Leer(i);
		bool bandera = false;
		for (int j = 0;j < cant;j++) {
			if (regUnidad[j].getId() == regRegistro.getIdUnidad() && regRegistro.getFecha().getMes()==m && regRegistro.getFecha().getAnio()==a) {
				vecCantidad[j]++;
			}
		}

	}
	int Contadormas50 = 0;
	for (int z = 0;z < cant;z++) {
		if (vecCantidad[z] >= 50) {
			regUnidad[z].mostrar();
			Contadormas50++;
		}
	}
	if (Contadormas50 == 0) {
		std::cout << "No hubo unidades que hayan registrado mas de 50 movimientos en el periodo ingresado" << std::endl;
		system("pause");
	}
		system("pause");

}

void InformesManager::UnidadesMas50()
{	system("cls");
int mes, anio;
	std::cout << "Unidades con mas de 50 movimientos " << std::endl;
	std::cout << "Ingrese mes y año (MM/AAAA)" << std::endl;
	std::cout << "Mes: " << std::endl;
	std::cin >> mes;
	std::cout << "Anio: " << std::endl;
	std::cin >> anio;
	ContarMovimientosIndicados(mes, anio);

	system("pause");
}

void InformesManager::InformeProveedores()
{	system("cls");
	std::cout << "Informe de Proveedores " << std::endl;
	int mesI, anioI,mesF, anioF;
	std::cout << "Ingrese el Periodo --- mes y año (MM/AAAA)" << std::endl;
	std::cout << "Entre: " << std::endl;
	std::cout << "Mes: " << std::endl;
	std::cin >> mesI;
	std::cout << "Anio: " << std::endl;
	std::cin >> anioI;
	std::cout << " Y : " << std::endl;
	std::cout << "Mes : " << std::endl;
	std::cin >> mesF;
	std::cout << "Anio : " << std::endl;
	std::cin >> anioF;



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
