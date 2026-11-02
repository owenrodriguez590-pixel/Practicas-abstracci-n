
#include <iostream>
using namespace std;

void sierpinski(int n, int fila, int columna,
                int tam, char dibujo[64][128]) {
    if (n == 0) {
        dibujo[fila][columna] = '*';
        return;
    }

    int mitad = tam / 2;

    sierpinski(n - 1, fila, columna, mitad, dibujo);
    sierpinski(n - 1, fila, columna + mitad,
               mitad, dibujo);
    sierpinski(n - 1, fila + mitad, columna,
               mitad, dibujo);
}

int main() {
    char dibujo[64][128];

    for (int i = 0; i < 64; i++)
        for (int j = 0; j < 128; j++)
            dibujo[i][j] = ' ';

    int nivel;
    cout << "Nivel del fractal (0 a 5): ";
    cin >> nivel;

    if (nivel < 0 || nivel > 5) {
        cout << "Nivel no valido" << endl;
        return 0;
    }

    int tam = 1 << nivel;

    sierpinski(nivel, 0, 0, tam, dibujo);

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << dibujo[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
