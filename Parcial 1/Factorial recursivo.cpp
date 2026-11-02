
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;

    cout << "Ingresa un numero entre 0 y 20: ";
    cin >> n;

    if (n < 0 || n > 20) {
        cout << "Numero fuera del rango permitido" << endl;
    } else {
        cout << "Factorial: " << factorial(n) << endl;
    }

    return 0;
}
