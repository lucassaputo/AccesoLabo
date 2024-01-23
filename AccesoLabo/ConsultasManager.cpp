#include "ConsultasManager.h"
#include <iostream>
#include "ArchivoUnidad.h"
#include "Unidad.h"
#include "ArchivoAutorizacion.h"
#include "Autorizacion.h"
#include "ArchivoVisita.h"
#include "Visita.h"
#include "ArchivoProveedores.h"
#include "Proveedor.h"

void ConsultasManager::ConsultaAutorizadosxUnidad() {
	system("cls");
	std::cout << "Consulta Autorizados por Unidad" << std::endl;
	int numUnidad,tipo = 0;
	Autorizacion regAut;
	ArchivoAutorizacion archAut("Autorizados.dat");
	ArchivoVisita archVisita("Visita.dat");
	Visita regVisita;
	Proveedor regProv;
	ArchivoProveedores archProv("Proveedores.dat");
	std::cout << "Ingrese el numero de unidad: " << std::endl;
	std::cin >> numUnidad;
	int pos = archAut.BuscarxUnidad(numUnidad);
	regAut = archAut.Leer(pos);
	tipo = regAut.getTipo();
	if (tipo == 1) {
		//visita
		pos=archVisita.BuscarxID(regAut.getId());
		regVisita = archVisita.Leer(pos);
		regVisita.mostrar();
	
	}
	else if(tipo==2)
	{
		//proveedor
		pos = archProv.BuscarxID(regAut.getId());
		regProv = archProv.Leer(pos);
		regProv.mostrar();
	}


	system("pause");
}

void ConsultasManager::ConsultaAutorizadosxApellido() {
	system("cls");
	std::cout << "Consulta Autorizados por Apellido" << std::endl;
	std::string Apellido;
	int  tipo = 0;
	Autorizacion regAut;
	ArchivoAutorizacion archAut("Autorizados.dat");
	ArchivoVisita archVisita("Visita.dat");
	Visita regVisita;
	Proveedor regProv;
	ArchivoProveedores archProv("Proveedores.dat");
	std::cout << "Ingrese el Apellido: " << std::endl;
	std::cin >> Apellido;
	int pos = archAut.Buscar();
	regAut = archAut.Leer(pos);
	tipo = regAut.getTipo();
	if (tipo == 1) {
		//visita
		pos = archVisita.BuscarxID(regAut.getId());
		regVisita = archVisita.Leer(pos);
		regVisita.mostrar();

	}
	else if (tipo == 2)
	{
		//proveedor
		pos = archProv.BuscarxID(regAut.getId());
		regProv = archProv.Leer(pos);
		regProv.mostrar();
	}


	system("pause");
}

void ConsultasManager::ConsultaResidentesxUnidad() {
	system("cls");
	std::cout << "Consulta de Residentes por unidad" << std::endl;
	system("pause");
}
void ConsultasManager::ConsultaResidentesxApellido() {
	system("cls");
	std::cout << "Consulta de Residentes por apellido" << std::endl;
	system("pause");
}

void ConsultasManager::ConsultaProveedoresxRazonSocial() {
	system("cls");
	std::cout << "ConsultaProveedores" << std::endl;
	system("pause");
}
void ConsultasManager::ConsultaProveedoresxCuit() {
	system("cls");
	std::cout << "ConsultaProveedores" << std::endl;
	system("pause");
}


void ConsultasManager::ConsultaUnidadesxNombre() {
	system("cls");
	std::cout << "ConsultaUnidades" << std::endl;
	system("pause");
}