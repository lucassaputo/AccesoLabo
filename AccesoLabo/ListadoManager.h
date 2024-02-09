#pragma once
#include "ArchivoAutorizacion.h"
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "Unidad.h"
#include "ArchivoProveedores.h"
#include "Registro.h"
class ListadoManager
{
	public:
		void AutorizadosPorApellido(); // punto 1
		void OrdenarVectorAutorizadosxApellido(Autorizacion* reg, int tam);
		void AutorizadosPorUnidad(); // punto 2
		void OrdenarVectorAutorizadosxNumero(Autorizacion *reg, int tam);
		void ResidentesPorUnidad();//punto 3
		void ProveedoresPorRazon();//punto4
		void OrdenarVectorProveedoresxRazon(Proveedor* reg, int tam);
		void ProveedoresPorDNI();//punto5
		void OrdenarVectorProveedoresxDNI(Proveedor* reg, int tam);
		void UnidadesPorNumero();//punto 6
		void OrdenarVectorUnidadxNumero(Unidad *reg, int tam);	
		void UnidadesPorFamilia();//punto 7
		void OrdenarVectorUnidadxApellido(Unidad* reg, int tam);
		
	private:
		ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizaciones.dat");
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

};



