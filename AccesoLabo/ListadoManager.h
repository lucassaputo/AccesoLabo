#pragma once
#include <iomanip>
#include "ArchivoAutorizacion.h"
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "ArchivoPersona.h"
#include "ArchivoResidente.h"
#include "ReporteAutorizaciones.h"
#include "Registro.h"

class ListadoManager
{
	public:
		void AutorizadosPorApellido(); // punto 1
		Persona BuscarenVisita(int dni);
		Proveedor BuscarenProveedor(int dni);
		void OrdenarAutorizadosxApellido(ReporteAutorizaciones* reg, int tam);
		void AutorizadosPorUnidad(); // punto 2
		void OrdenarVectorAutorizadosxNumero(Autorizacion *reg, int tam);
		void OrdenarAutorizadosxNumero(ReporteAutorizaciones* vec, int tam);
		void ResidentesPorUnidad();//punto 3
		void OrdenarResidentesxUnidad(Residente* reg, int tam);
		void ProveedoresPorRazon();//punto4
		void OrdenarVectorProveedoresxRazon(Proveedor* reg, int tam);
		void ProveedoresPorDNI();//punto5
		void OrdenarVectorProveedoresxDNI(Proveedor* reg, int tam);
		void UnidadesPorNumero();//punto 6
		void OrdenarVectorUnidadxNumero(Unidad *reg, int tam);	
		void UnidadesPorFamilia();//punto 7
		void OrdenarVectorUnidadxApellido(Unidad* reg, int tam);
		void ListarRegistros();
	private:
		ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizaciones.dat");
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoResidente _archivoResisente = ArchivoResidente("Residentes.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
		ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
};

