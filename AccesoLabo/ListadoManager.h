#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "Proveedor.h"
#include "ArchivoProveedores.h"
#include "Registro.h"
#include "Autorizacion.h"
class ListadoManager
{
	public:
		void AutorizadosPorApellido();
		void separarsepararAutorizacionporTipo(Autorizacion* reg, Autorizacion* reg2, Autorizacion* reg3, int& cant, int& cant2, int& cant3);//recibe 3 vectores de autorizacion a uno le asigna el total de los registros//
		                                                                                                                                  //y los otros dos son para separar visitas y proveedores tmb recibe y modifica los contadores de posiciones de cada vector                                                                       
		void AutorizadosPorUnidad();		
		void ordenarVector(Autorizacion* vec, int tam);
		void ResidentesPorUnidad();
		void ProveedoresPorRazon();
		void ordenarVector(std::string* vec, Proveedor* regp, int tam);
		void EmpleadosPorDNI();
		void ordenarVector(Proveedor *vec, int tam);
		void UnidadesPorNumero();
		void ordenarVector(Unidad* vec, int tam);
		void ordenarVectorUnidadxFamilia(Unidad* vec, int tam);
		void UnidadesPorFamilia();
		void Mostrar(Registro reg);
		//Registro LeerRegistro(int pos);
		void MostrarCantidadRegistros();
		void ListarTodos();
		void ContarRegistros();
		void MostrarCantidadProveedores();
		void ListarTodosProveedores();
		void ListarUnidades();
		void ListarRegistros();
		
	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

};



