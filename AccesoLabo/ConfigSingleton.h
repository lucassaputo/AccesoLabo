#pragma once
#include "Configuracion.h"
class ConfigSingleton
{
public:
    // Función estática para obtener la instancia única del Singleton
    static ConfigSingleton& getInstance() {
        // La instancia se crea solo si no existe una instancia previa
        if (!instance) {
            instance = new ConfigSingleton();
        }
        return *instance;
    }

    // Establecer el objeto de la clase deseada
    void setMiClase(const Configuracion& obj) {
        miClaseObj = obj;
    }

    // Obtener el objeto de la clase deseada
    Configuracion& getConfig() {
        return miClaseObj;
    }
    void ReiniciarClase() { /// esto deberia reiniciar la clase simulando un cierre de sesion
        miClaseObj = Configuracion();
    }

private:
    // Constructor privado para evitar la creación de instancias fuera de la clase
    ConfigSingleton() {
        //std::cout << "Se ha creado una instancia del Singleton." << std::endl;
    }

    // Destructor privado para evitar la destrucción accidental fuera de la clase
    ~ConfigSingleton() {
        //std::cout << "Se ha destruido la instancia del Singleton." << std::endl;
    }

    // Instancia única del Singleton
    static ConfigSingleton* instance;

    // Objeto de la clase deseada
    Configuracion miClaseObj;
};

