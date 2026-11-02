
#include <iostream>
using namespace std;

int main() {
    double numeros[5];
    double *p = numeros;
    double suma = 0, maximo, minimo;

    for (int i = 0; i < 5; i++) {
        cout << "Ingresa un numero: ";
        cin >> *(p + i);
    }

    maximo = minimo = *p;

    for (int i = 0; i < 5; i++) {
        suma += *(p + i);

        if (*(p + i) > maximo)
            maximo = *(p + i);

        if (*(p + i) < minimo)
            minimo = *(p + i);
    }

    cout << "Suma: " << suma << endl;
    cout << "Media: " << suma / 5 << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    return 0;
}
