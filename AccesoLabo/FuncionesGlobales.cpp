#include "FuncionesGlobales.h"
#include "Fecha.h"
#include<iostream>
using namespace std;
bool vencido(Fecha fecha) {
	return false;
}

void cargarCadena(char* pal, int tam) {
	int i;
	fflush(stdin);
	for (i = 0; i < tam; i++)
	{
		pal[i] = cin.get();
		if (pal[i] == '\n') break;
	}
	pal[i] = '\0';
	fflush(stdin);
}
void Creditos() {

	system("cls");
	cout << "----- CREDITOS -----" << endl;
	cout << "Coll Benegas, Pablo" << endl;
	cout << "Saputo, Lucas" << endl;
	system("pause");

}