#pragma once
#include "Fecha.h"
#include "Unidad.h"
#include "Horario.h"

void cargarCadena(char* pal, int tam);
std::string cargarNombre();
std::string cargarApellido();
std::string cargarString(std::string campo);
std::string cargarStringTam(std::string campo, int tam);
int cargarDni();
bool soloNumeros(std::string aux);
bool soloLetras(std::string x);
std::string ingresarLegajo();
int ingresarCantUnidades();
std::string ingresarIdUnidad();
std::string cargarTelefono();
void Creditos();
Unidad buscarUnidad(int u);
int ingresarMotivo();
Unidad ingresarUnidad(std::string mensaje);
bool ingresarPropInq();
Fecha ingresarFechaAutorizacion();
Fecha ingresarFechaIngreso();
Fecha ingresarFechaHasta();
int ingresarOpcionMenu(int opciones);
std::string upper(std::string cadena);
std::string ingresarPassword();
Horario ingresarHorario(std::string campo);
std::string dosDigitos(int n);