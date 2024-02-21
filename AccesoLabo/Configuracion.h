#pragma once
#include "Horario.h"
class Configuracion
{
	private:
		int _id;
		int _cantUnidades;
		Horario _desde;
		Horario _hasta;
		
	public:
		//sets
		void setId(int id);
		void setCantUnidades(int cant);
		void setDesde(Horario h);
		void setHasta(Horario h);

		//gets
		int getId();
		int getCantUnidades();
		Horario getDesde();
		Horario getHasta();
		
		//acciones
		void cargar();
		void mostrar();		
};

