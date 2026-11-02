
#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    string marca;
    double precio;
    int anio;

    void mostrar() {
        cout << marca << " $" << precio
             << " " << anio << endl;
    }
};

class Persona {
public:
    string nombre, ap, am, genero;
    int edad;

    void mostrar() {
        cout << nombre << " " << ap << " " << am << endl;
        cout << "Genero: " << genero
             << ", Edad: " << edad << endl;
    }
};

int main() {
    Auto a;
    Persona p;

    a.marca = "Nissan";
    a.precio = 250000;
    a.anio = 2022;

    p.nombre = "Juan";
    p.ap = "Perez";
    p.am = "Lopez";
    p.genero = "Masculino";
    p.edad = 18;

    a.mostrar();
    p.mostrar();

    return 0;
}
