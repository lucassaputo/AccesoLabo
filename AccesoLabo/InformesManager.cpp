#include "InformesManager.h"
#include <iostream>

	/*regRegistro = new Registro[cant];
	if (regRegistro == nullptr) {
		std::cout << "Error en la asignacion de memoria" << std::endl;
		return; 
	}*/
void InformesManager::ProvedoresIngresados(int mi, int ai, int mf, int af)
{
	ArchivoRegistro archRegistro("Registros.dat");
	Registro regRegistro;
	Proveedor* regProveedores;
	ArchivoProveedores arcProveedores("Proveedores.dat") ;
	int *vecContador;// cada posicion es equivalente a la posicion del vector de proveedores. si tiene mas de 0 significa que hizo movimientos
	int cantP = 0, cant=0;

	cantP = arcProveedores.ContarRegistros();
    regProveedores = new Proveedor[cantP];
	if (regProveedores == nullptr) {
		std::cout << "Error" << std::endl;
		return;
	}
	vecContador = new int[cantP];
	if (vecContador == nullptr) {
		std::cout << "Error" << std::endl;
		return;// revisar de q otra manera volver
	}
	ponerenCeroVector(vecContador, cantP);
	for (int x = 0;x < cantP;x++) {
		regProveedores[x] = arcProveedores.Leer(x);
	}
	int cantReg = archRegistro.ContarRegistros();
	for (int j = 0; j < cantReg;j++) {
		regRegistro = archRegistro.Leer(j);
		for (int k = 0;k < cantP;k++) {
			if (regRegistro.getSentido() == 2) { // 2 por que es PROVEEDORES
				if (regRegistro.getFecha().getMes() >= mi && regRegistro.getFecha().getMes() <= mf && regRegistro.getFecha().getAnio() >= ai && regRegistro.getFecha().getAnio() <= af) {
					if(regRegistro.getIdPersona() == regProveedores[j].getId()) {
						vecContador[j]++;
					}
				}
			
		     }

		}
	}
	std::cout << "Proveedores Ingresados en la fecha solicitada: " << std::endl;

		int cont = 0;
	for (int i = 0;i < cantP;i++) {
		if (vecContador[i] > 0) {
			cont++;
			regProveedores[i].mostrar();
			std::cout << "Ingreso: " << vecContador[i] << " veces " << std::endl;
		}
		
	}
	if (cont == 0) {
		std::cout << "Contador = " << cont << std::endl;;
		std::cout << "No se registraron movimientos de proveedores en el rango indicado" << std::endl;
	}
	delete[] regProveedores;

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
		std::cout << "Error en la asignacion de memoria en regUnidades" << std::endl;
		return;
	}
	vecMovimientosUnidades = new int[cantUnidades];
	if (vecMovimientosUnidades == nullptr) {
		std::cout << "Error en la asignacion de memoria en vecMovimientosUnidades" << std::endl;
		return;
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
	std::cout << "********* ATENCION: CANTIDAD DE MOVIMIENTOS: " << cantUnidades << " **************" << std::endl;
	if (cantUnidades == 0) {
		std::cout << "Cantidad de Unidades = 0 - No hay registros cargados actualmente" << std::endl;
	}
	else if (cantUnidades < 6) {
		std::cout << "Unidades ordenadas por cantidad de movimientos" << std::endl;
		for (int j = 0;j < cantUnidades;j++) {
			regUnidades[j].mostrar();
		}
	}
	else if (cantUnidades >= 6) {

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
		std::cout << " Movimientos: " << vecMovimientosUnidades[2] << std::endl;
		std::cout << "------------------------------" << std::endl;
	}
	delete[] regUnidades; 
	delete[] vecMovimientosUnidades;
	system("pause");
}

void InformesManager::ordenarVectorUnidades(int* vec, int tam, Unidad* reg)
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {			
				int aux = vec[j];
				Unidad& auxU = reg[j]; // pasa por referencia
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
	int mesI, anioI, mesF, anioF;
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
	MovimientosRealizados(mesI, anioI, mesF, anioF);
	system("pause");
}

void InformesManager::MovimientosRealizados(int mi, int ai, int mf, int af)
{
	ArchivoRegistro archRegistro("Registros.dat");
	Registro* regRegistro;

	int* vecContador;// cada posicion es equivalente a la posicion del vector de registros. si tiene mas de 0 significa que hizo movimientos

	int cant = archRegistro.ContarRegistros();
	regRegistro = new Registro[cant];
	if (regRegistro == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1); // revisar de q otra manera volver
	}
	vecContador = new int[cant];
	if (vecContador == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);// revisar de q otra manera volver
	}
	ponerenCeroVector(vecContador, cant);

	for (int j = 0; j < cant;j++) {
		regRegistro[j] = archRegistro.Leer(j);

		if (regRegistro[j].getFecha().getMes() >= mi && regRegistro[j].getFecha().getMes() <= mf && regRegistro[j].getFecha().getAnio() >= ai && regRegistro[j].getFecha().getAnio() <= af) {
				vecContador[j]++;
		}

	}
	std::cout << "Movimientos realizados en la fecha solicitada: " << std::endl;
	int cont = 0; // cuento las vueltas del for - si es 0 es xq no mostro nada
	for (int i = 0;i < cant;i++) {
		if (vecContador[i] > 0) {
			regRegistro[i].mostrar();
			cont++;
		}
	}
	if (cont == 0) {
		std::cout << "No hay registros para mostrar" << std::endl;
	}

}