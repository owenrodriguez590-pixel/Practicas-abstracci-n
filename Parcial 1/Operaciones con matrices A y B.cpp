
#include <iostream>
using namespace std;

int main() {
    int A[2][2], B[2][2], C[2][2];
    int constante;

    cout << "Ingresa la matriz A (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ingresa la matriz B (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }

    cout << "Ingresa la constante: ";
    cin >> constante;

    cout << "\nA * constante:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << A[i][j] * constante << "\t";
        }
        cout << endl;
    }

    // Multiplicacion de matrices A por B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;

            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nA * B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
