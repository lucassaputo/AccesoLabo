#pragma once
#include <cstring>
#include <iomanip>
#include "Fecha.h"
class Persona {
	private:
		int _id;
		char _nombres[51];
		char _apellidos[51];		
		int _dni;
		Fecha _nacimiento;
		bool _estado;
	public:
		//constructor
		Persona();
		//sets
		void setApellidos(std::string apellidos);
		void setNombres(std::string nombres);
		void setDni(int dni);
		void setNacimiento(Fecha f);
		void setEstado(bool estado);
		void setId(int id);
		//gets
		std::string getApellidos();
		std::string getNombres();
		std::string getApellidosyNombres();
		int getDni();
		std::string  getNacimiento();
		int getId();
		bool getEstado();
		//acciones
		void cargarPersona();
		void  editarPersona();
		void mostrar();
		void mostrarX();
};
