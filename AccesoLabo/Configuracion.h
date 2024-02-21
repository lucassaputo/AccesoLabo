#pragma once
#include "Horario.h"
class Configuracion
{
	private:
		int _id;
		 Horario _desde;
		 Horario _hasta;
		
	public:
		//sets
		void setId(int id);
		void setDesde(Horario h);
		void setHasta(Horario h);

		//gets
		int getId();
		Horario getDesde();
		Horario getHasta();
		
		//acciones
		void cargar();
		void mostrar();		
};

