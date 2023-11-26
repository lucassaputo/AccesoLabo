#include "ArchivoConfiguraciones.h"
#include "Configuracion.h"
#include <cstdio>

ArchivoConfiguraciones::ArchivoConfiguraciones(std::string nombreArchivo = "Configuraciones.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoConfiguraciones::Guardar(Configuracion reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Configuracion), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoConfiguraciones::Guardar(Configuracion reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Configuracion), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Configuracion), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoConfiguraciones::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Configuracion);
}

Configuracion ArchivoConfiguraciones::Leer(int nroRegistro) {
    Configuracion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Configuracion), SEEK_SET);
    fread(&reg, sizeof(Configuracion), 1, p);
    fclose(p);
    return reg;
}