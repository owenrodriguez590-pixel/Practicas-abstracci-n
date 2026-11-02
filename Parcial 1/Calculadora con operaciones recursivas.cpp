
#include <iostream>
using namespace std;

int multiplicar(int a, int b) {
    if (b == 0)
        return 0;

    if (b < 0)
        return -multiplicar(a, -b);

    return a + multiplicar(a, b - 1);
}

int potencia(int base, int exponente) {
    if (exponente == 0)
        return 1;

    return multiplicar(base, potencia(base, exponente - 1));
}

int dividir(int a, int b) {
    if (b == 0)
        return 0;

    if (a < b)
        return 0;

    return 1 + dividir(a - b, b);
}

int main() {
    int a, b;

    cout << "Ingresa dos numeros positivos: ";
    cin >> a >> b;

    cout << "Multiplicacion: " << multiplicar(a, b) << endl;
    cout << "Potencia: " << potencia(a, b) << endl;

    if (b != 0)
        cout << "Division entera: " << dividir(a, b) << endl;
    else
        cout << "No se puede dividir entre cero" << endl;

    return 0;
}
