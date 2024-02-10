#pragma once
#include "ArchivoMovimientos.h"
#include "ArchivoProveedores.h"
#include "ArchivoAutorizacion.h"
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "Unidad.h"
class RegistrosManager
{
	private:
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
		ArchivoAutorizacion _archivoAutorizaciones = ArchivoAutorizacion("Autorizaciones.dat");
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoRegistro _archivoActivos = ArchivoRegistro("Activos.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
	public:
		void Cargar();
		void Editar();
		void Eliminar();
		Unidad buscarUnidad(int u);
		void registroProveedores(Unidad uni, int dni,int motivo);
		void registroVisitas(Unidad uni, int dni);
		void registroResidentes(Unidad uni, int dni);
		Autorizacion getAutorizacion(Proveedor &p);
		void ingresoProveedor(Unidad& uni, Proveedor& p);
		void egresoProveedor(Unidad& uni, Proveedor& p, int posActivo);
		int adentro1(int dni, int motivo, int tipoPersona);
		bool adentro(int dni, int motivo);
		bool autorizado(Unidad uni, Proveedor p);
		bool vencido(Proveedor p);
		bool checkAutorizacion(Unidad u, Proveedor p);
		void guardarRegistro(Unidad u, Proveedor p);
};

