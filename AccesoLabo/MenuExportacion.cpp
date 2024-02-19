#include <iostream>
#include "MenuExportacion.h"
#include "ExportacionManager.h"
#include "FuncionesGlobales.h"
/*
Copias de seguridad: importarlas y exportarlas. Copias disponibles de unidades, visitas, residentes, personas.
Exportar listados y consultas: el sistema permitirá exportar los registros disponibles en los listados y consultas detallados previamente para su análisis posterior.
*/
void MenuExportacion::Mostrar()
{
	while (true)
	{

	system("cls");
		std::cout << "----- BACKUPS -----" << std::endl;
		std::cout << "* - Copia de Seguridad" << std::endl;
		std::cout << "	1 - Copia de Unidades" << std::endl;
		std::cout << "	2 - Copia de Residentes" << std::endl;
		std::cout << "	3 - Copia de Visitas" << std::endl;
		std::cout << "	4 - Copia de Proveedores" << std::endl;
		std::cout << "* - Restaurar copia de Seguridad" << std::endl;
		std::cout << "	5 - Restaurar Unidades" << std::endl;
		std::cout << "	6 - Restaurar Residentes" << std::endl;
		std::cout << "	7 - Restaurar Visitas" << std::endl;
		std::cout << "	8 - Restaurar Proveedores" << std::endl;
		std::cout << "0 - Volver" << std::endl;

		int opcion = ingresarOpcionMenu(8);
		while (opcion == -1) {
			opcion == ingresarOpcionMenu(8);
		}

		switch (opcion)
		{
		case 1:
			system("cls");
			_manager.CopiadeSeguridad();
			//system("pause");
			break;
		case 5:
			system("cls");
			_manager.RestaurarCopia();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}

	
	}
}