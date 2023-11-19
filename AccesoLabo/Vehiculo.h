#pragma once
#include <iostream>
#include "Fecha.h"

class Vehiculo
{
private:
	std::string _patente;
	std::string _titular;
	Fecha _fechaSeguro;
	int _tipo;

public:
	std::string getPatente();
	std::string getTitular();
	Fecha getSeguro();
	int getTipo();

	void setPatente(std::string patente);
	void setTitular(std::string titular);
	void setSeguro(Fecha _fechaSeguro);
	void setTipo(int tipo);

	void Cargar();
	void Mostrar();
};

/*
-escribir(pos:int):bool
-leer(pos:int):bool
-buscar(pos:int):bool*/
