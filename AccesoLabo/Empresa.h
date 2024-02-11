#pragma once
#include <cstring>
class Empresa
{
public:
	int getCuit() const;
	std::string  getRazonSocial() ;
	std::string getDescripcion() ;

	void setCuit(int cuit);
	void setRazonSocial(std::string razonSocial);
	void setDescripcion(std::string descripcion);

	void cargar();
	std::string mostrarempresastring();
	void mostrar();
	int getId();

private:
	int _cuit;
	char _razonSocial[50];
	char _descripcion[50];
	bool _estado;

};

