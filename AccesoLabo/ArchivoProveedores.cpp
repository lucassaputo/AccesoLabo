#include "ArchivoProveedores.h"
#include <cstdio>

ArchivoProveedores::ArchivoProveedores(std::string nombreArchivo = "Proveedores.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProveedores::Guardar(Proveedor reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoProveedores::Guardar(Proveedor reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoProveedores::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Proveedor);
}

Proveedor ArchivoProveedores::Leer(int nroRegistro) {
    Proveedor reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
    fread(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return reg;
}

/**
 * Busca el IDMovimiento en el archivo de Movimientos.
 * Si lo encuentra devuelve la posici�n del archivo del registro.
 * Si no lo encuentra devuelve -1
*/
int ArchivoProveedores::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
