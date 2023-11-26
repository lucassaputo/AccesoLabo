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
	ProvedoresIngresados(mesI, anioI, mesF, anioF);
		system("pause");
}


void InformesManager::HistorialMovimientosxUnidades()
{
	system("cls");
	ArchivoRegistro archRegistro("Registros.dat");
	Registro regRegistro;
	Unidad *regUnidades;
	ArchivoUnidad archUnidades("Unidades.dat");

	int *vecMovimientosUnidades;	
	int cantUnidades = archUnidades.ContarRegistros();
	regUnidades = new Unidad[cantUnidades];
	if (regUnidades == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	vecMovimientosUnidades = new int[cantUnidades];
	if (vecMovimientosUnidades == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	ponerenCeroVector(vecMovimientosUnidades, cantUnidades);
	int tamRegistros = archRegistro.ContarRegistros();
	for (int x = 0;x < tamRegistros;x++) {
		regRegistro = archRegistro.Leer(x);
		for (int i = 0;i < cantUnidades;i++) {
			if (regRegistro.getIdUnidad() == regUnidades[i].getId()) {
				vecMovimientosUnidades[i]++;
			}
		}

	}
	ordenarVectorUnidades(vecMovimientosUnidades, cantUnidades, regUnidades);



	std::cout << "*****-----Unidades con mas movimientos-----*****" << std::endl;
	regUnidades[cantUnidades - 1].mostrar();
	std::cout << " Movimientos: " << vecMovimientosUnidades[cantUnidades - 1] << std::endl;
	std::cout << "------------------------------" << std::endl;
	regUnidades[cantUnidades - 2].mostrar();
	std::cout << " Movimientos: " << vecMovimientosUnidades[cantUnidades - 2] << std::endl;
	std::cout << "------------------------------" << std::endl;
	regUnidades[cantUnidades - 3].mostrar();
	std::cout << " Movimientos: " << vecMovimientosUnidades[cantUnidades - 3] << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "*****-----Unidades con menos movimientos-----*****" << std::endl;
	regUnidades[0].mostrar();
	std::cout << " Movimientos: " << vecMovimientosUnidades[0] << std::endl;
	std::cout << "------------------------------" << std::endl;
	regUnidades[1].mostrar();
	std::cout << " Movimientos: " << vecMovimientosUnidades[1] << std::endl;
	std::cout << "------------------------------" << std::endl;
	regUnidades[2].mostrar();
	std::cout  << " Movimientos: " << vecMovimientosUnidades[2] << std::endl;
	std::cout << "------------------------------" << std::endl;
	system("pause");
}

void InformesManager::ordenarVectorUnidades(int* vec, int tam, Unidad* reg)
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {
				// Intercambiar elementos si están en el orden incorrecto
				int aux = vec[j];
				Unidad auxU = reg[j];
				vec[j] = vec[j + 1];
				reg[j] = reg[j + 1];
				vec[j + 1] = aux;
				reg[j + 1] = auxU;
			}
		}
	}
}

void InformesManager::HistorialMovimientos()
{	system("cls");
	std::cout << "Historial de movimientos " << std::endl;
	system("pause");
}

