#include "ExportacionManager.h"
#include <iostream>


void ExportacionManager::CopiadeSeguridad()
{
    system("cls");
    std::cout << "Copia de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

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

void ExportacionManager::CopiaUnidades() {
    system("cls");
    std::cout << "Copia de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

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
void ExportacionManager::RestaurarUnidades() {
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
void ExportacionManager::CopiaProveedores() {
    system("cls");
    std::cout << "Copia de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

    Proveedor u;
    int cant = _archivoProveedores.ContarRegistros();
    for (int i = 0; i < cant;i++) {
        u = _archivoProveedores.Leer(i);
        if (i == 0) {
            if (!_archivoProveedoresBackup.CrearArchivo(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
        else {
            if (!_archivoProveedoresBackup.Guardar(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
    }
    std::cout << "Backup generado correctamente, se respaldaron " << cant << " unidades." << std::endl;
    system("pause");
}
void ExportacionManager::RestaurarProveedoes() {
    system("cls");
    std::cout << "Restaurar de Seguridad" << std::endl;
    std::cout << "*********************************" << std::endl;

    //desea restaurar copia de seguridad...... s/n
    Proveedor u;
    int cant = _archivoProveedoresBackup.ContarRegistros();
    for (int i = 0; i < cant;i++) {
        u = _archivoProveedoresBackup.Leer(i);
        if (i == 0) {
            if (!_archivoProveedores.CrearArchivo(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
        else {
            if (!_archivoProveedores.Guardar(u)) {
                std::cout << "Error al generar backup. Intente nuevamente." << std::endl;
                break;
            }
        }
    }
    std::cout << "Restauracion realizada correctamente de " << cant << " proveedores." << std::endl;
    system("pause");
}
void ExportacionManager::CopiaVisitas() {

}
void ExportacionManager::RestaurarVisita() {

}
void ExportacionManager::CopiaResidentes() {

}
void ExportacionManager::RestaurarResidentes() {

}