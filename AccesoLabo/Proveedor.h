#pragma once
#include<cstring>
#include "Fecha.h"
#include "Persona.h"

class Proveedor : public Persona {
	private:
		char _tipo;
		Fecha _art;
		char _empresa[51];
	public:
		//sets
		void setTipo(char tipo);
		void setArt(int dia, int mes, int anio);
		void setArt(Fecha fecha);
		void setEmpresa(std::string empresa);

		//gets
		char getTipo() const;
		std::string getArt();
		Fecha getArtFecha();
		std::string getEmpresa() const;

		//acciones
		void cargarProveedor(int dni);
		void editarProveedor();
		void mostrar();
		bool operator>(Fecha &fechaActual);
		bool vencido();	

};