#include <iostream>
#include "MenuExportacion.h"
#include "ExportacionManager.h"
/*
Copias de seguridad: importarlas y exportarlas. Copias disponibles de unidades, visitas, residentes, personas.
Exportar listados y consultas: el sistema permitirá exportar los registros disponibles en los listados y consultas detallados previamente para su análisis posterior.
*/
void MenuExportacion::Mostrar()
{
	while (true)
	{

	system("cls");
		std::cout << "----- EXPORTACIONES -----" << std::endl;
		std::cout << "1 - Copia de Seguridad" << std::endl;
		std::cout << "2 - Exportar listado" << std::endl;
		std::cout << "3 - Exportar Consulta" << std::endl;
		std::cout << "0 - Volver" << std::endl;

		int opc;
		std::cin >> opc;
		switch (opc)
		{
		case 1:
			system("cls");
			_manager.CopiadeSeguridad();
			//system("pause");
			break;
		case 2:
			system("cls");
			_manager.ExportarListado();
		//	system("pause");
			break;
		case 3:
			system("cls");
			_manager.ExportarConsulta();
			//system("pause");
			break;


		case 0:
			return;
			break;


		}

	
	}
}