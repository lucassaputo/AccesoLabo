#pragma once
#include "Usuario.h"

class UserSingleton {
public:
    // Función estática para obtener la instancia única del Singleton
    static UserSingleton& getInstance() {
        // La instancia se crea solo si no existe una instancia previa
        if (!instance) {
            instance = new UserSingleton();
        }
        return *instance;
    }

    // Establecer el objeto de la clase deseada
    void setMiClase(const Usuario& obj) {
        miClaseObj = obj;
    }

    // Obtener el objeto de la clase deseada
    Usuario& getUsuario() {
        return miClaseObj;
    }
    void ReiniciarClase() { /// esto deberia reiniciar la clase simulando un cierre de sesion
        miClaseObj = Usuario();
    }

private:
    // Constructor privado para evitar la creación de instancias fuera de la clase
    UserSingleton() {
        //std::cout << "Se ha creado una instancia del Singleton." << std::endl;
    }

    // Destructor privado para evitar la destrucción accidental fuera de la clase
    ~UserSingleton() {
        //std::cout << "Se ha destruido la instancia del Singleton." << std::endl;
    }

    // Instancia única del Singleton
    static UserSingleton* instance;

    // Objeto de la clase deseada
    Usuario miClaseObj;
};

