#include "ArchivoUsuario.h"
#include "Usuario.h"
#include <cstdio>
#include <cstring>
#include <iostream>

ArchivoUsuario::ArchivoUsuario(std::string nombreArchivo = "Usuario.dat") {
    _nombreArchivo = nombreArchivo;
}


bool ArchivoUsuario::Guardar(Usuario reg) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) {
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ArchivoUsuario::Guardar(Usuario reg, int nroRegistro) {
    bool pudoEscribir;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Usuario), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return pudoEscribir;
}

int ArchivoUsuario::ContarRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Usuario);
}

Usuario ArchivoUsuario::Leer(int nroRegistro) {
    Usuario reg;
    reg.setLegajo("- 1");
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return reg;//agregar como informar este error.
    }
    fseek(p, nroRegistro * sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return reg;
}


int ArchivoUsuario::Buscar(std::string legajo) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Usuario reg;
    while (fread(&reg, sizeof(Usuario), 1, p)) {
        if (reg.getLegajo() == legajo){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -2;
}

bool ArchivoUsuario::ListarUsuarios()
{
    FILE* p;
    Usuario reg;
    p = fopen("Usuarios.dat", "rb");
    if (p == NULL) {
        return false;
    }
    while (fread(&reg, sizeof(Usuario), 1, p)) {
        reg.mostrar();
    }
    fclose(p);
    return true;
}

int ArchivoUsuario::BuscarPos(int id) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return -1;
    }
    int i = 0;
    Usuario reg;
    while (fread(&reg, sizeof(Usuario), 1, p)) {
        if (reg.getId() == id) {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Usuario ArchivoUsuario::BuscarObj(std::string legajo) {
    Usuario u;
    u.setLegajo("-1");
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        return u;
    }
    int i = 0;
    int comparacion;
    Usuario reg;
    while (fread(&reg, sizeof(Usuario), 1, p)) {
        //std::cout << "sdfsdfsd  f    " + reg.getLegajo();
        comparacion = reg.getLegajo().compare(legajo);
        if (comparacion == 0) {
            fclose(p);
            return reg;
        }
        i++;
    }
    fclose(p);
    return u;
}

bool ArchivoUsuario::Modificar(Usuario reg) {
    bool pudoEscribir;
    int nroRegistro;
    Usuario aux;
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
    fseek(p, nroRegistro * sizeof(Usuario), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return pudoEscribir;
}