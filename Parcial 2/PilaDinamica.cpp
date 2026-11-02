#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<float> pila;
    int opcion;
    float valor;

    do {
        cout << "\n--- PILA CON STACK ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (pila.size() >= 10) {
                    cout << "La pila esta llena.\n";
                } else {
                    cout << "Ingresa un numero: ";
                    cin >> valor;
                    pila.push(valor);
                    cout << "Elemento insertado.\n";
                }
                break;

            case 2:
                if (pila.empty()) {
                    cout << "La pila esta vacia.\n";
                } else {
                    cout << "Eliminado: " << pila.top() << endl;
                    pila.pop();
                }
                break;

            case 3: {
                if (pila.empty()) {
                    cout << "La pila esta vacia.\n";
                } else {
                    stack<float> auxiliar = pila;

                    cout << "Pila (cima a base): ";
                    while (!auxiliar.empty()) {
                        cout << auxiliar.top() << " ";
                        auxiliar.pop();
                    }
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion incorrecta.\n";
        }

    } while (opcion != 4);

    return 0;
}
