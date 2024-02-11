#pragma once
#include "ArchivoMovimientos.h"
#include "ArchivoProveedores.h"
#include "ArchivoAutorizacion.h"
#include "ArchivoRegistro.h"
#include "ArchivoUnidad.h"
#include "ArchivoResidente.h"
#include "Unidad.h"
#include "ArchivoPersona.h"
class RegistrosManager
{
	private:
		ArchivoProveedores _archivoProveedores = ArchivoProveedores("Proveedores.dat");
		ArchivoAutorizacion _archivoAutorizaciones = ArchivoAutorizacion("Autorizaciones.dat");
		ArchivoRegistro _archivoRegistros = ArchivoRegistro("Registros.dat");
		ArchivoRegistro _archivoActivos = ArchivoRegistro("Activos.dat");
		ArchivoUnidad _archivoUnidades = ArchivoUnidad("Unidades.dat");
		ArchivoPersona _archivoVisitas = ArchivoPersona("Visitas.dat");
		ArchivoResidente _archivoResidentes = ArchivoResidente("Residentes.dat");
	public:
		void Cargar();
		void Editar();
		void Eliminar();
		void registroProveedores(Unidad uni, int dni,int motivo);
		void registroVisitas(Unidad uni, int dni);
		void registroResidentes(Unidad uni, int dni);
		void ingresoProveedor(Unidad& uni, Proveedor& p);
		void ingresoVisita(Unidad& uni, Persona& p, int motivo);
		void egresoProveedor(Unidad& uni, Proveedor& p, int posActivo);
		void egreso(Unidad& uni, Persona& p, int motivo);
		bool adentro(int dni, int motivo);
		bool autorizado(Unidad uni, int idPersona,int motivo);
		bool vencido(Proveedor p);
		bool checkAutorizacion(Unidad u, int idPersona, int motivo);
		void guardarRegistro(Unidad u, Proveedor p);
		void guardar(Unidad u, Persona p, int motivo);

};

