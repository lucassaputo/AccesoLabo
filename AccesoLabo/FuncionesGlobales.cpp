#include "FuncionesGlobales.h"
#include "Fecha.h"
#include<iostream>
using namespace std;

void ordenarVector(int* vec, int tam)
{
	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0; j < tam - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {
				// Intercambiar elementos si están en el orden incorrecto
				int aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}

}

void ponerenCeroVector(int* vec, int tam)
{
	for (int x = 0;x < tam;x++) {
		vec[x] = 0;
	}

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

bool soloNumeros(string x) {
	bool esNumero = true;
	for (char c : x) {
		if (!isdigit(c)) {
			esNumero = false;
			break;
		}
	}
	return esNumero;
}

void Creditos() {
	system("cls");
	cout << "----- CREDITOS -----" << endl;
	cout << "Coll Benegas, Pablo" << endl;
	cout << "Saputo, Lucas" << endl;
	system("pause");
}