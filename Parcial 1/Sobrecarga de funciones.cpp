
#include <iostream>
using namespace std;

int calcular() {
    return 0;
}

int calcular(int a, int b) {
    return a + b;
}

int calcular(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "Sin parametros: " << calcular() << endl;
    cout << "Con 2 parametros: " << calcular(5, 3) << endl;
    cout << "Con 3 parametros: " << calcular(5, 3, 2) << endl;

    return 0;
}
