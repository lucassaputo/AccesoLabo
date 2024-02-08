#pragma once
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoProveedores.h"
#include "ArchivoUsuario.h"
#include "Registro.h"
class ListadoManager
{
	public:
		void AutorizadosPorApellido();
		void AutorizadosPorUnidad();
		void ResidentesPorUnidad();
		void ProveedoresPorRazon();
		void EmpleadosPorDNI();
		void UnidadesPorNumero();
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
		void ListarUsuarios();
		
	private:
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
		ArchivoUsuario _archivoUsuarios = ArchivoUsuario("Usuario.dat");

};



