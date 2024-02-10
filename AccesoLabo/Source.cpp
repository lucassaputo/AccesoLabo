#include <iostream>
#include<cstdio>
using namespace std;
#include <string>
#include "App.h"
#include "UserSingleton.h"
#include "ConfigSingleton.h"

// Inicializaci�n est�tica de la instancia como nullptr
UserSingleton* UserSingleton::instance = nullptr;
ConfigSingleton* ConfigSingleton::instance = nullptr;

int main() {			
	App app;
	app.Ejecutar();//

	return 0;
}

// user leg 8 pass 12 ADMIN
// user 10 pass 1234 VIGILADOR


//2024
/*
* mostrar lo existente en el mensaje y cin de ingresar
*/
// 
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
* mantener la indentacion
* ver cuando pasar por referencia objetos o solo pasar el atributo que utilice la funcion
* hacer sobrevarga de fecha de <
* validar el ingrese de opciones del menu que sean solo numeros
* dniString en persona se rompio
* ingresar fecha nacimiento en usuario y persona
* validar password usuario
* maximo de caracteres en legajo
* estado activo o no es de usuario o persona? o de ambos?
* como se hace referencia a un atributo de la clase padre en el cpp de la hija? quiero acceder a _dni pero no pude, sera pq el encapsulamiento? this no funciono
* metodo para ingresar pass y limitar cant de caracteres
* permirtir numeros en observaciones unidad
* tocas y chequear tama�o de los atributos char[xxxxx]
* limitar mas los submenus segun usuario logueado
* poner en rojo algunos textos? o negritas?
* chequear defaults en switch que tengan todos
*/

/*
* tipos de unidades:
* --------------------
* sentido 1 entrada 2 salida
* 
* nivel usuarios:
* --------------------
* 1 admin
* 2 vigilador
* 
* tipos de personas;:
* --------------------
* 1: Visita | 2: Proveedor | 3: Residente
*/