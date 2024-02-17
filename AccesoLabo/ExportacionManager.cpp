#include "ExportacionManager.h"
#include <iostream>


void ExportacionManager::CopiadeSeguridad()
{
    system("cls");
    std::cout << "Copia de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

    //desea realizar copia de seguridad...... s/n
    Unidad u;
    int cant = _archivoUnidades.ContarRegistros();
    for (int i = 0; i < cant;i++) {
        u = _archivoUnidades.Leer(i);
        if (i == 0) {
            if (!_archivoUnidadesBackup.CrearArchivo(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
        else {
            if (!_archivoUnidadesBackup.Guardar(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
    }
    std::cout << "Backup generado correctamente, se respaldaron " << cant << " unidades." << std::endl;
    system("pause");
}

void ExportacionManager::RestaurarCopia()
{
    system("cls");
    std::cout << "Restaurar de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

    //desea restaurar copia de seguridad...... s/n
    Unidad u;
    int cant = _archivoUnidadesBackup.ContarRegistros();
    for (int i = 0; i < cant;i++) {
        u = _archivoUnidadesBackup.Leer(i);
        if (i == 0) {
            if (!_archivoUnidades.CrearArchivo(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
        else {
            if (!_archivoUnidades.Guardar(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
    }
    std::cout << "Restauracion realizada correctamente de " << cant << " unidades." << std::endl;
    system("pause");
}

