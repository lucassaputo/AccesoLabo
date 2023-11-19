#include <iostream>
using namespace std;
#include "MenuExportacion.h"
/*
Copias de seguridad: importarlas y exportarlas. Copias disponibles de unidades, visitas, residentes, personas.
Exportar listados y consultas: el sistema permitirá exportar los registros disponibles en los listados y consultas detallados previamente para su análisis posterior.
*/
void MenuExportacion::Mostrar()
{    
	system("cls");
	cout << "----- EXPORTACIONES -----" << endl;
	cout << "1 - Copia de Seguridad" << endl;
	cout << "2 - Exportar listado" << endl;
	cout << "3 - Exportar Consulta" << endl;
	cout << "0 - Volver" << endl;
	system("pause");

}
