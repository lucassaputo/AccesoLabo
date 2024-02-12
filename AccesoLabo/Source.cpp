#include <iostream>
#include<cstdio>
using namespace std;
#include <string>
#include "App.h"
#include "UserSingleton.h"
#include "ConfigSingleton.h"
#include <fstream> // Incluir la biblioteca para manejar archivos

// Inicialización estática de la instancia como nullptr
UserSingleton* UserSingleton::instance = nullptr;
ConfigSingleton* ConfigSingleton::instance = nullptr;

int main() {	
    /*
    // Abrir un archivo para escribir
    std::ofstream archivo("datos.txt");

    // Verificar si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribir datos en el archivo
        archivo << "Hola, este es un ejemplo de exportación a un archivo de texto en C++.\n";
        archivo << "Puedes escribir cualquier dato que desees aquí.\n";
        archivo << "¡Buena suerte con tu programa!\n";

        // Cerrar el archivo
        archivo.close();

        std::cout << "Los datos se han exportado correctamente al archivo 'datos.txt'.\n";
    }
    else {
        // Mostrar un mensaje de error si no se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo 'datos.txt'.\n";
    }

    return 0;
	
	
	*/
	
	App app;
	app.Ejecutar();

	return 0;
}

// user leg 8 pass 12 ADMIN
// user 10 pass 1234 VIGILADOR

//validar si esta adentro del mismo lote antes de dar salida
// agregar estado a la validacion de las personas en registroManager, en los tres tipos
// chequear si es inquilino una fecha que sea hasta hay que agregar y dsp validar
// ver libreria para pdf
// ver libreria para seleccionar archivos
// ver como usar librerias en general
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
* tocas y chequear tamaño de los atributos char[xxxxx]
* limitar mas los submenus segun usuario logueado
* poner en rojo algunos textos? o negritas?
* chequear defaults en switch que tengan todos
* discriminar errores en buscarObj por ejemplo da igual sino abrio el archivo o si no encontro  registro
* tipo proveedor, lo sacamos?
* como reconoce proveedor si no esta incluido en abmPersonasManager
* pasar a texto en edicion la condicion se es inquilino o propietario
* agregar usuario a los registros
* corregir o ver que autorizacion queda vigente si la persona se da de baja o no?
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