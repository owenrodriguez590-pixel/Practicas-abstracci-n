
#include <iostream>
using namespace std;

int main() {
    double a, b;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    cout << "Suma: " << a + b << endl;
    cout << "Resta: " << a - b << endl;
    cout << "Multiplicacion: " << a * b << endl;

    if (b != 0)
        cout << "Division: " << a / b << endl;
    else
        cout << "No se puede dividir entre cero" << endl;

    return 0;
}
