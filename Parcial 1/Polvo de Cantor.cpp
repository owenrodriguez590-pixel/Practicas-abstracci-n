
#include <iostream>
#include <string>
using namespace std;

void cantor(string linea, int nivel) {
    cout << linea << endl;

    if (nivel == 0)
        return;

    int tercio = linea.size() / 3;

    if (tercio == 0)
        return;

    string izquierda = linea.substr(0, tercio);
    string centro(tercio, ' ');
    string derecha = linea.substr(2 * tercio, tercio);

    cantor(izquierda + centro + derecha, nivel - 1);
}

int main() {
    int nivel;

    cout << "Ingresa el nivel (0 a 5): ";
    cin >> nivel;

    if (nivel < 0 || nivel > 5) {
        cout << "Nivel no valido" << endl;
        return 0;
    }

    string linea(81, '*');
    cantor(linea, nivel);

    return 0;
}
