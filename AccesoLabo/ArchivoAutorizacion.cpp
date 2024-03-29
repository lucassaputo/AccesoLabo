#include "ArchivoAutorizacion.h"
#include <cstdio>

ArchivoAutorizacion::ArchivoAutorizacion(std::string nombreArchivo = "Autorizaciones.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoAutorizacion::Guardar(Autorizacion reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Autorizacion), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoAutorizacion::Guardar(Autorizacion reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Autorizacion), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Autorizacion), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoAutorizacion::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Autorizacion);
}

Autorizacion ArchivoAutorizacion::Leer(int nroRegistro) {
    Autorizacion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Autorizacion), SEEK_SET);
    fread(&reg, sizeof(Autorizacion), 1, p);
    fclose(p);
    return reg;
}

int ArchivoAutorizacion::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Autorizacion reg;
    while (fread(&reg, sizeof(Autorizacion), 1, p)) {
        if (reg.getIdPersona() == dni) {//cambiar
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Autorizacion ArchivoAutorizacion::BuscarObj(int idPersona, int motivo, int unidad) {
    Autorizacion aux;
    aux.setId(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return aux;
    }
    int i = 0;
    Autorizacion reg;
    while (fread(&reg, sizeof(Autorizacion), 1, p)) {
        if (reg.getIdPersona() == idPersona && reg.getIdUnidad() == unidad && reg.getTipo() == motivo && reg.getEstado() == true) {
            fclose(p);
            return reg;
        }
        i++;
    }
    fclose(p);
    return aux;
}


bool ArchivoAutorizacion::Modificar(Autorizacion reg) {
    bool pudoEscribir;
    int nroRegistro;
    Autorizacion aux;
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
    fseek(p, nroRegistro * sizeof(Autorizacion), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Autorizacion), 1, p);
    fclose(p);
    return pudoEscribir;
}