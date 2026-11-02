
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

struct Auto {
    string marca;
    double precio;
    int anio;
};

int main() {
    Persona personas[3];
    Auto autos[3];

    cout << "REGISTRO DE PERSONAS" << endl;

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

    cout << "\nREGISTRO DE AUTOS" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nAuto " << i + 1 << endl;

        cout << "Marca: ";
        cin >> autos[i].marca;
        cout << "Precio: ";
        cin >> autos[i].precio;
        cout << "Anio: ";
        cin >> autos[i].anio;
    }

    cout << "\nLISTA DE PERSONAS" << endl;
    for (int i = 0; i < 3; i++) {
        cout << personas[i].nombre << " "
             << personas[i].ap << " "
             << personas[i].am << ", edad "
             << personas[i].edad << endl;
    }

    cout << "\nLISTA DE AUTOS" << endl;
    for (int i = 0; i < 3; i++) {
        cout << autos[i].marca << ", $"
             << autos[i].precio << ", "
             << autos[i].anio << endl;
    }

    return 0;
}
