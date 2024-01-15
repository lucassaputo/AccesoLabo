#pragma once
#include "Usuario.h"

class UserSingleton {
public:
    // Funci�n est�tica para obtener la instancia �nica del Singleton
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
    // Constructor privado para evitar la creaci�n de instancias fuera de la clase
    UserSingleton() {
        //std::cout << "Se ha creado una instancia del Singleton." << std::endl;
    }

    // Destructor privado para evitar la destrucci�n accidental fuera de la clase
    ~UserSingleton() {
        //std::cout << "Se ha destruido la instancia del Singleton." << std::endl;
    }

    // Instancia �nica del Singleton
    static UserSingleton* instance;

    // Objeto de la clase deseada
    Usuario miClaseObj;
};

