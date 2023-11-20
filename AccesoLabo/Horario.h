#pragma once
#include <string>

class Horario {
private:
    int _hora, _minuto, _segundo;
public:
    //constructores
    Horario();
    Horario(int segundo, int minuto, int hora);
    //sets
    void setSegundo(int segundo);
    void setMinuto(int minuto);
    void setHora(int hora);
    //gets
    int getSegundo();
    int getMinuto();
    int getHora();
    //acciones
    void cargar(int seg, int minuto, int hora);
    std::string toString();
};
