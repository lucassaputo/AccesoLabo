#include "ArchivoResidente.h"
#include <cstdio>

ArchivoResidente::ArchivoResidente(std::string nombreArchivo = "Residentes.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoResidente::Guardar(Residente reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Residente), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoResidente::Guardar(Residente reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Residente), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Residente), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoResidente::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Residente);
}

Residente ArchivoResidente::Leer(int nroRegistro) {
    Residente reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Residente), SEEK_SET);
    fread(&reg, sizeof(Residente), 1, p);
    fclose(p);
    return reg;
}

int ArchivoResidente::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Residente reg;
    while (fread(&reg, sizeof(Residente), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
