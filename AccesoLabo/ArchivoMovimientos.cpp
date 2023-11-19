#include "ArchivoMovimientos.h"
#include <cstdio>

ArchivoMovimientos::ArchivoMovimientos(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoMovimientos::Guardar(Movimiento reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoMovimientos::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Movimiento);
}

Movimiento ArchivoMovimientos::Leer(int nroRegistro) {
    Movimiento reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Movimiento), SEEK_SET);
    fread(&reg, sizeof(Movimiento), 1, p);
    fclose(p);
    return reg;
}

int ArchivoMovimientos::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Movimiento reg;
    while (fread(&reg, sizeof(Movimiento), 1, p)) {
        if (reg.getPersona().getDni() == dni) {//cambiar
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
