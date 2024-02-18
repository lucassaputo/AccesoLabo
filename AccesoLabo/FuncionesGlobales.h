#pragma once
#include "Fecha.h"
#include "Unidad.h"

void cargarCadena(char* pal, int tam);
std::string cargarNombre();
std::string cargarApellido();
std::string cargarString(std::string campo);
int cargarDni();
bool soloNumeros(std::string aux);
bool soloLetras(std::string x);
std::string ingresarLegajo();
std::string ingresarIdUnidad();
int cargarTelefono();
void Creditos();
Unidad buscarUnidad(int u);
int ingresarMotivo();
Unidad ingresarUnidad(std::string mensaje);
Fecha ingresarFechaAutorizacion();
int ingresarOpcionMenu(int opciones);