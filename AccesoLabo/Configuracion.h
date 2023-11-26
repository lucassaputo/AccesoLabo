#pragma once
#include "Horario.h"
class Configuracion
{
	private:
		 Horario _desde;
		 Horario _hasta;
		
	public:
		//sets
		void setDesde(Horario h);
		void setHasta(Horario h);

		//gets
		Horario getDesde();
		Horario getHasta();
		
		//acciones
		void cargar(int dni);
		void mostrar();
		
};

