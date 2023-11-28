#include "ListadoManager.h"
#include "Registro.h"
#include "Autorizacion.h"
#include "ArchivoAutorizacion.h"
#include "Residente.h"


#include <iostream>

using namespace std;
//residentes por unidad (falta archivo residentes)
void ListadoManager::AutorizadosPorApellido() {
	system("cls");	
	Autorizacion *regAut, * regAutVisitas, * regAutProveedores;
	int CantidadregAutorizacion = 0, CantAutorizadosVisitas = 0, CantAutorizadosProveedores = 0; // contadores para cuando recorra el archivo de autorizados saber cuantos de visita y cuantos de proveedores hay
		
	separarsepararAutorizacionporTipo(regAut, regAutVisitas, regAutProveedores, CantidadregAutorizacion, CantAutorizadosVisitas, CantAutorizadosProveedores);
	if (CantAutorizadosVisitas > 0) {
		std::cout << "Visitantes Autorizados Por Apellido" << std::endl;
		for (int i = 0; i < CantAutorizadosVisitas; i++)
		{
			regAutVisitas[i].mostrar();
		}
	}
	else if (CantAutorizadosVisitas == 0) {
		std::cout << "No hay Visitantes autorizados" << std::endl;
	}
	if (CantAutorizadosProveedores > 0) {
	std::cout << "Proveedores Autorizados PorApellido" << std::endl;
		std::cout << "Visitantes Autorizados Por Apellido" << std::endl;
		for (int i = 0; i < CantAutorizadosProveedores; i++)
		{
			regAutVisitas[i].mostrar();
		}
	}
	else if (CantAutorizadosProveedores == 0) {
		std::cout << "No hay Proveedores autorizados" << std::endl;
	}
			
	system("pause");
}
void ListadoManager::separarsepararAutorizacionporTipo(Autorizacion* reg, Autorizacion* reg2, Autorizacion* reg3, int& cant, int& cant2, int& cant3) 
{
	ArchivoAutorizacion archAutorizacion("Autorizaciones.dat");
	cant = archAutorizacion.ContarRegistros();
	reg = new Autorizacion[cant];
	if (reg == nullptr) {
		std::cout << "Error en la asignacion de memoria" << std::endl;
		return;
	}
	for (int x = 0; x < cant;x++) {
		reg[x] = archAutorizacion.Leer(x);
		if (reg[x].getTipo() == 1) cant2++;
		if (reg[x].getTipo() == 2) cant3++;
	}
	reg2 = new Autorizacion[cant2];
	reg3 = new Autorizacion[cant3];
	if (reg2 == nullptr || reg3 == nullptr) {
		std::cout << "Error en la asignacion de memoria" << std::endl;
		return;
	}	
	int contv = 0,contp = 0;
	for (int i = 0; i < cant;i++) {
		if (reg[i].getTipo() == 1) {
			reg2[contv++] = reg[i];
		}
		else if (reg[i].getTipo() == 2) {
			reg3[contp++] = reg[i];
		}
	}
}
void ListadoManager::ordenarVector(Autorizacion* vec, int tam) //ordena vector de autorizacion por numero de id
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (vec[j].getId() > vec[j + 1].getId()) {				
				Autorizacion aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}

}

void ListadoManager::AutorizadosPorUnidad() {
	system("cls");
	ArchivoAutorizacion archAut("Autorizaciones.dat");
	Autorizacion *regAut;
	int cantreg = archAut.ContarRegistros();
	regAut = new Autorizacion[cantreg];
	if (regAut == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	
	for (int x = 0;x < cantreg;x++) {
		regAut[x] = archAut.Leer(x);
	}
	ordenarVector(regAut, cantreg);
	cout << "AutorizadosPorUnidad" << endl;
	for (int i = 0;i < cantreg;i++) {
		regAut[i].mostrar();
	}

	delete regAut;
	system("pause");
} 

void ListadoManager::ResidentesPorUnidad() {
	system("cls");

	/// falta archivo residentes
	cout << "ResidentesPorUnidad" << endl;
	system("pause");
}
void ListadoManager::ProveedoresPorRazon() {
	system("cls");
	std::string *vecRazon;
	Proveedor *regProveedor;
	ArchivoProveedores archProveedor("Proveedores.dat");
	int cantRegistroProveedores = archProveedor.ContarRegistros();
	regProveedor = new Proveedor[cantRegistroProveedores];
	if (regProveedor == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	vecRazon = new std::string[cantRegistroProveedores];
	if (vecRazon == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	for (int x = 0;x < cantRegistroProveedores;x++) {
		regProveedor[x] = archProveedor.Leer(x);
		vecRazon[x] = regProveedor[x].getEmpresa();
	}
	ordenarVector(vecRazon, regProveedor, cantRegistroProveedores);

	for (int k = 0;k < cantRegistroProveedores;k++) {
		regProveedor[k].mostrar();
	}

	delete vecRazon;
	delete regProveedor;
	cout << "ProveedoresPorRazon" << endl;
	system("pause");
}
void ListadoManager::ordenarVector(std::string* vec,Proveedor *regp, int tam)
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (strcmp(vec[j].c_str(),vec[j + 1].c_str())<0) {
				// Intercambiar elementos si están en el orden incorrecto
				std::string aux = vec[j];
				Proveedor auxp = regp[j];
				vec[j] = vec[j + 1];
				regp[j] = regp[j + 1];
				vec[j + 1] = aux;
				regp[j + 1] = auxp;
			}
		}
	}


}


void ListadoManager::EmpleadosPorDNI() {
	system("cls");
	Proveedor *regProveedor;
	ArchivoProveedores archProveedor("Proveedores.dat");
	int cant = archProveedor.ContarRegistros();
	 regProveedor = new Proveedor[cant];
	if (regProveedor == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	cout << "EmpleadosPorDNI" << endl;
ordenarVector(regProveedor, cant);

for (int x = 0;x < cant; x++) {
	regProveedor[x].mostrar();
}
delete regProveedor;
	system("pause");
}
void ListadoManager::ordenarVector(Proveedor *vec, int tam)
{
	
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {			
			if (vec[j].getDni() > vec[j + 1].getDni()) {
				Proveedor aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
	
}

void ListadoManager::UnidadesPorNumero() {
	system("cls");
	Unidad* RegUnidad;
	ArchivoUnidad archUnidad("Unidades.dat");
	int cantUnidades = archUnidad.ContarRegistros();
	RegUnidad = new Unidad[cantUnidades];
	if (RegUnidad == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	for (int x = 0;x < cantUnidades;x++) {
		RegUnidad[x] = archUnidad.Leer(x);
	}
	ordenarVector(RegUnidad, cantUnidades);
	cout << "UnidadesPorNumero" << endl;
	for (int i = 0;i < cantUnidades;i++) {
		RegUnidad[i].mostrar();
	}
	delete RegUnidad;
	system("pause");
}
void ListadoManager::ordenarVector(Unidad* vec, int tam)
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (vec[j].getId() > vec[j + 1].getId()) {
				Unidad aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}

}
void ListadoManager::ordenarVectorUnidadxFamilia(Unidad* vec, int tam)
{
	//	if (strcmp(vec[j].c_str(),vec[j + 1].c_str())<0)
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (strcmp(vec[j].getFamilia().c_str(), vec[j + 1].getFamilia().c_str()) < 0) {
				Unidad aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
}
void ListadoManager::UnidadesPorFamilia() {
	system("cls");
	Unidad* RegUnidad;
	ArchivoUnidad archUnidad("Unidades.dat");
	int cantUnidades = archUnidad.ContarRegistros();
	RegUnidad = new Unidad[cantUnidades];
	if (RegUnidad == nullptr) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	for (int x = 0;x < cantUnidades;x++) {
		RegUnidad[x] = archUnidad.Leer(x);
	}
	ordenarVectorUnidadxFamilia(RegUnidad, cantUnidades);
	cout << "UnidadesPorFamilia" << endl;
	for (int i = 0;i < cantUnidades;i++) {
		RegUnidad[i].mostrar();
	}
	delete RegUnidad;
	system("pause");
}

void ListadoManager::Mostrar(Registro reg) {
	
	//cout << "idPersona: " << reg.getPersona() << endl;
	//cout << "idUnidad: " << reg.getUnidad() << endl;
	//cout << "FECHA: " << reg.getFecha().toString() << endl;
	//cout << "TIPO: " << reg.getTipoAutorizacion() << endl;
	//cout << "sentido" << reg.getSentido() << endl;
	//cout << "observaciones " << reg.getObservaciones() << endl;
	//cout << "estado" << reg.getEstado() << endl;
}

void ListadoManager::MostrarCantidadRegistros() {
	int cantidadRegistros = _archivoRegistros.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
}

void ListadoManager::ListarTodos() {

	int cantidadRegistros = _archivoRegistros.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
	Registro reg;
	for (int i = 0; i < cantidadRegistros; i++) {
		//Mostrar(_archivoRegistros.Leer(i));
		cout << endl << "CANT: " << i << endl;
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
		

	}
}
void ListadoManager::MostrarCantidadProveedores() {
	int cantidadRegistros = _archivoProveedores.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
}
void ListadoManager::ListarTodosProveedores() {

	int cantidadRegistros = _archivoProveedores.ContarRegistros();
	cout << endl << "CANTIDAD REGISTROS: " << cantidadRegistros << endl;
	Proveedor reg;
	for (int i = 0; i < cantidadRegistros; i++) {
		//Mostrar(_archivoRegistros.Leer(i));
		reg = _archivoProveedores.Leer(i);
		//reg.mostrar();
		//reg.mostrar();
		cout << "Nombre: " << reg.getNombres() << endl;
		cout << "Apellido: " << reg.getApellidos() << endl;
		cout << endl << "CANT: " << i << endl;

	}
}
void ListadoManager::ListarUnidades() {
	int cant = _archivoUnidades.ContarRegistros();
	Unidad u;
	for (int i = 0;i < cant;i++) {
		u = _archivoUnidades.Leer(i);
		u.mostrar();
	}
}
void ListadoManager::ListarRegistros() {
	int cant = _archivoRegistros.ContarRegistros();
	Registro reg;
	for (int i = 0;i < cant;i++) {
		reg = _archivoRegistros.Leer(i);
		reg.mostrar();
	}
}