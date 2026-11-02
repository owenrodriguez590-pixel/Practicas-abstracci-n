
#include <iostream>
#include <string>
using namespace std;

struct Auto {
    string marca;
    double precio;
    int anio;
};

class Persona {
public:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

int main() {
    cout << "Tipos basicos:" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;

    cout << "\nTipos creados:" << endl;
    cout << "Auto: " << sizeof(Auto) << " bytes" << endl;
    cout << "Persona: " << sizeof(Persona) << " bytes" << endl;
    cout << "string: " << sizeof(string) << " bytes" << endl;

    return 0;
}
