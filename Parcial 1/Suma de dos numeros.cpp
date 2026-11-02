
#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int n1, n2;

    cout << "Ingresa dos numeros: ";
    cin >> n1 >> n2;

    cout << "La suma es: " << sumar(n1, n2) << endl;

    return 0;
}
