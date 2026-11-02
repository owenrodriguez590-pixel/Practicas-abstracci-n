
#include <iostream>
using namespace std;

int main() {
    double numeros[5];
    double suma = 0, maximo, minimo;

    for (int i = 0; i < 5; i++) {
        cout << "Ingresa un numero: ";
        cin >> numeros[i];
    }

    maximo = minimo = numeros[0];

    for (int i = 0; i < 5; i++) {
        suma += numeros[i];

        if (numeros[i] > maximo)
            maximo = numeros[i];

        if (numeros[i] < minimo)
            minimo = numeros[i];
    }

    cout << "Suma: " << suma << endl;
    cout << "Media: " << suma / 5 << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    return 0;
}
