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
		void AutorizadosPorApellido();
		void AutorizadosPorUnidad(); // punto 2
		void ResidentesPorUnidad();//punto 3
		void ProveedoresPorRazon();//punto4
		void ProveedoresPorDNI();//punto5
		void UnidadesPorNumero();//punto 6
		void OrdenarVectorUnidadxNumero(Unidad *reg, int tam);
		void UnidadesPorFamilia();//punto 7
		void Mostrar(Registro reg);
		//Registro LeerRegistro(int pos);
		void MostrarCantidadUnidades();
		void ListarTodos();
		void ContarRegistros();
		void MostrarCantidadProveedores();
		void ListarTodosProveedores();
		void ListarUnidades();
		void ListarRegistros();
		
	private:
		ArchivoAutorizacion _archivoAutorizacion = ArchivoAutorizacion("Autorizaciones.dat");
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");

};



