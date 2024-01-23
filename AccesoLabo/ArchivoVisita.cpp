#include "ArchivoVisita.h"
#include <cstdio>

ArchivoVisita::ArchivoVisita(std::string nombreArchivo = "Visita.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVisita::Guardar(Visita reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Visita), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoVisita::Guardar(Visita reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Visita), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Visita), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoVisita::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Visita);
}

Visita ArchivoVisita::Leer(int nroRegistro) {
    Visita reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Visita), SEEK_SET);
    fread(&reg, sizeof(Visita), 1, p);
    fclose(p);
    return reg;
}

/**
 * Busca el IDMovimiento en el archivo de Movimientos.
 * Si lo encuentra devuelve la posición del archivo del registro.
 * Si no lo encuentra devuelve -1
*/
int ArchivoVisita::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Visita reg;
    while (fread(&reg, sizeof(Visita), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int ArchivoVisita::Buscar(const char* a)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Visita reg;
    while (fread(&reg, sizeof(Visita), 1, p)) {
        if (strcmp(reg.getApellidos().c_str(), a) == 0) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int ArchivoVisita::BuscarxID(int id)
{

    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Visita reg;
    while (fread(&reg, sizeof(Visita), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;

}
