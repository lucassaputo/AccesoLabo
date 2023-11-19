#include "Vehiculo.h"
using namespace std;
string Vehiculo::getPatente()
{
    return _patente;
}

string Vehiculo::getTitular()
{
    return _titular;
}

Fecha Vehiculo::getSeguro()
{
    return _fechaSeguro;
}

int Vehiculo::getTipo()
{
    return _tipo;
}

void Vehiculo::setPatente(string patente)
{
    _patente = patente;
}

void Vehiculo::setTitular(string titular)
{
    _titular = titular;
}

void Vehiculo::setSeguro(Fecha fechaSeguro)
{
    _fechaSeguro = fechaSeguro;
}

void Vehiculo::setTipo(int tipo)
{
    _tipo = tipo;
}

void Vehiculo::Cargar()
{
    int d, m, a;
    cout << "Ingrese la patente: " << endl;
    cin >> _patente;
    cout << "Ingrese el titular: " << endl;
    cin >> _titular;
    cout << "Ingrese la fecha de vencimiento del seguro: (dd/mm/aaaa)" << endl;
    cin >> d >> m >> a;
    _fechaSeguro.cargar(d,m, a);
    cout << "Ingrese el Tipo de vehiculo: " << endl;
    cin >> _tipo;


}

void Vehiculo::Mostrar()
{
    cout << "Patente: " << _patente << endl;
    cout << "Titular: " << _titular << endl;
    cout << "Vencimiento del seguro: " << endl;
    _fechaSeguro.toString();
    cout << "Tipo: " << _tipo << endl;
}
