#include "ArchivoRegistro.h"
#include <cstdio>

ArchivoRegistro::ArchivoRegistro(std::string nombreArchivo = "Registros.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoRegistro::Guardar(Registro reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Registro), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoRegistro::Guardar(Registro reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Registro), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Registro), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoRegistro::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Registro);
}

Registro ArchivoRegistro::Leer(int nroRegistro) {
    Registro reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        std::cout << "acaa pauseeee";
        system("pause");
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Registro), SEEK_SET);
    fread(&reg, sizeof(Registro), 1, p);
    fclose(p);
    return reg;
}

/**
 * Busca el IDMovimiento en el archivo de Movimientos.
 * Si lo encuentra devuelve la posición del archivo del registro.
 * Si no lo encuentra devuelve -1
*/

int ArchivoRegistro::Buscar(int unidad) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Registro reg;
    while (fread(&reg, sizeof(Registro), 1, p)) {
        if (reg.getIdUnidad() == unidad) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
