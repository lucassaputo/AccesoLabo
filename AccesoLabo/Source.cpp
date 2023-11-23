#include <iostream>
#include<cstdio>
using namespace std;
#include "FuncionesGlobales.h"
#include <string>
#include "App.h"
#include "Empresa.h"
#include "Fecha.h"
#include "Singleton.h"
#include "Usuario.h"

// Inicialización estática de la instancia como nullptr
Singleton* Singleton::instance = nullptr;

int main() {		
	// Obtener la instancia única del Singleton
	Singleton& s = Singleton::getInstance();
	// Crear un objeto de la clase deseada
	Usuario reg;
	reg.setId(11);
	reg.setNombres("Lucas");
	reg.setApellidos("Saputo");
	reg.setNick("LucasNick");
	// Guardar el objeto en el Singleton
	s.setMiClase(reg);
	// Obtener el objeto desde el Singleton y llamar a su función
	//s.getUsuario().mostrar();



	Fecha aux;
	cout << aux.toString() << endl;
	Fecha tt;
	tt.cargar(11, 10, 2023);
	cout << tt.toString() << endl;
	if (tt > aux) {
		cout << "si" << endl;
	}
	else {
		cout << "no" << endl;
	} 
	//system("pause");
	App app;
	app.Ejecutar();
	
	return 0;
}

//HACER
/*
* hacer algun tipo de escape en medio del registro
* login
* validaciones
*	DNI
*	nombre
*	apellido
*	fecha
* ingreso fecha mejorarlo
* ABML vehiculos
* esta adentro?
* menues
* ingreso de fechas mas simple
* tipo de proveedor queda?
*/


/*
* tipos de unidades
* sentido 1 entrada 2 salida
*/