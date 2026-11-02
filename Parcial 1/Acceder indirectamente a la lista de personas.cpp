
#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

int main() {
    Persona personas[3];

    for (int i = 0; i < 3; i++) {
        cout << "\nPersona " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Apellido paterno: ";
        cin >> personas[i].ap;
        cout << "Apellido materno: ";
        cin >> personas[i].am;
        cout << "Genero: ";
        cin >> personas[i].genero;
        cout << "Edad: ";
        cin >> personas[i].edad;
    }

    Persona *p = personas;

    cout << "\nCONSULTA INDIRECTA" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nNombre: " << (p + i)->nombre << endl;
        cout << "Apellidos: " << (p + i)->ap
             << " " << (p + i)->am << endl;
        cout << "Genero: " << (p + i)->genero << endl;
        cout << "Edad: " << (p + i)->edad << endl;
    }

    return 0;
}
