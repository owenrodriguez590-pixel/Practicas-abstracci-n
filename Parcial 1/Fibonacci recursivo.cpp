
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Cuantos numeros de Fibonacci quieres: ";
    cin >> n;

    if (n < 1 || n > 40) {
        cout << "Ingresa un numero entre 1 y 40" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    cout << endl;
    return 0;
}
