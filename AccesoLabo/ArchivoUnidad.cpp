#include "ArchivoUnidad.h"
#include <cstdio>

ArchivoUnidad::ArchivoUnidad(std::string nombreArchivo = "Unidades.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoUnidad::Guardar(Unidad reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Unidad), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoUnidad::Guardar(Unidad reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Unidad), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Unidad), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoUnidad::Modificar(Unidad reg) {
    bool pudoEscribir;
    int nroRegistro;
    Unidad aux;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    int cant = ContarRegistros();
    for (nroRegistro = 0;nroRegistro < cant;nroRegistro++) {
        aux = Leer(nroRegistro);
        if (aux.getId() == reg.getId()) {
            break;
        }
    }
    fseek(p, nroRegistro * sizeof(Unidad), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Unidad), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoUnidad::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Unidad);
}

Unidad ArchivoUnidad::Leer(int nroRegistro) {
    Unidad reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Unidad), SEEK_SET);
    fread(&reg, sizeof(Unidad), 1, p);
    fclose(p);
    return reg;
}


int ArchivoUnidad::BuscarPos(int id) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Unidad reg;
    while (fread(&reg, sizeof(Unidad), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Unidad ArchivoUnidad::BuscarObj(int id) {
    Unidad uni;
    uni.setId(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return uni;
    }
    int i = 0;
    Unidad reg;
    while (fread(&reg, sizeof(Unidad), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return reg;
        }
        i++;
    }
    fclose(p);
    return uni;
}
