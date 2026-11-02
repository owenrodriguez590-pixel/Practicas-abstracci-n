
#include <iostream>
#include <string>
using namespace std;

struct Auto {
    string marca;
    double precio;
    int anio;
};

struct Persona {
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

int main() {
    Auto a;
    Persona p;

    cout << "Datos del auto" << endl;
    cout << "Marca: ";
    getline(cin, a.marca);
    cout << "Precio: ";
    cin >> a.precio;
    cout << "Anio: ";
    cin >> a.anio;

    cin.ignore();

    cout << "\nDatos de la persona" << endl;
    cout << "Nombre: ";
    getline(cin, p.nombre);
    cout << "Apellido paterno: ";
    getline(cin, p.ap);
    cout << "Apellido materno: ";
    getline(cin, p.am);
    cout << "Genero: ";
    getline(cin, p.genero);
    cout << "Edad: ";
    cin >> p.edad;

    cout << "\nAuto: " << a.marca << ", $" << a.precio
         << ", " << a.anio << endl;

    cout << "Persona: " << p.nombre << " "
         << p.ap << " " << p.am << endl;
    cout << "Genero: " << p.genero
         << ", Edad: " << p.edad << endl;

    return 0;
}
