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
 * Si lo encuentra devuelve la posición del archivo del registro.
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

int ArchivoProveedores::BuscarId(int id) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Proveedor ArchivoProveedores::BuscarObj(int dni) {
    Proveedor prov;
    prov.setDni(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return prov;
    }
    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p)) {
        if (reg.getDni() == dni) {
            fclose(p);
            return reg;
        }
        i++;
    }
    fclose(p);
    return prov;
}

Proveedor ArchivoProveedores::BuscarObjApellido(std::string apellido) {
    Proveedor aux;
    aux.setDni(-1);
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return aux;
    }
    int i = 0;
    Proveedor reg;
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

bool ArchivoProveedores::Modificar(Proveedor reg) {
    bool pudoEscribir;
    int nroRegistro;
    Proveedor aux;
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
    fseek(p, nroRegistro * sizeof(Proveedor), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoProveedores::CrearArchivo(Proveedor reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "wb");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return pudoEscribir;
}