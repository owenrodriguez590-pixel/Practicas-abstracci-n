
#include <iostream>
using namespace std;

int main() {
    double n[5], suma = 0;
    double maximo, minimo;

    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> n[i];
        suma += n[i];
    }

    maximo = minimo = n[0];

    for (int i = 1; i < 5; i++) {
        if (n[i] > maximo) maximo = n[i];
        if (n[i] < minimo) minimo = n[i];
    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio o media: " << suma / 5 << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    return 0;
}
