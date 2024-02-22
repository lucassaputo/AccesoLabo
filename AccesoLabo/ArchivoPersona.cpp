#include "ArchivoPersona.h"
#include <cstdio>

ArchivoPersona::ArchivoPersona(std::string nombreArchivo = "Visitas.dat") {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPersona::Guardar(Persona reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Persona), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoPersona::Guardar(Persona reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Persona), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Persona), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoPersona::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Persona);
}

Persona ArchivoPersona::Leer(int nroRegistro) {
    Persona reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Persona), SEEK_SET);
    fread(&reg, sizeof(Persona), 1, p);
    fclose(p);
    return reg;
}

/**
 * Busca el IDMovimiento en el archivo de Movimientos.
 * Si lo encuentra devuelve la posición del archivo del registro.
 * Si no lo encuentra devuelve -1
*/
int ArchivoPersona::Buscar(int dni) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Persona reg;
    while (fread(&reg, sizeof(Persona), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

int ArchivoPersona::BuscarId(int id) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Persona reg;
    while (fread(&reg, sizeof(Persona), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Persona ArchivoPersona::BuscarObj(int dni) {
    Persona aux;
    aux.setDni(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return aux;
    }
    //int i = 0;
    Persona reg;
    while (fread(&reg, sizeof(Persona), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return reg;
        }
        //i++;
    }
    fclose(p);
    return aux;
}

Persona ArchivoPersona::BuscarObjApellido(std::string apellido) {
    Persona aux;
    aux.setDni(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return aux;
    }
    int i = 0;
    Persona reg;
    while (fread(&reg, sizeof(Persona), 1, p)) {
        if (reg.getEstado() && reg.getApellidos() == apellido) {
            fclose(p);
            return reg;
        }
        i++;
    }
    fclose(p);
    return aux;
}

bool ArchivoPersona::Modificar(Persona reg) {
    bool pudoEscribir;
    int nroRegistro;
    Persona aux;
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
    fseek(p, nroRegistro * sizeof(Persona), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Persona), 1, p);
    fclose(p);
    return pudoEscribir;
}
bool ArchivoPersona::CrearArchivo(Persona reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "wb");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Persona), 1, p);
    fclose(p);
    return pudoEscribir;
}