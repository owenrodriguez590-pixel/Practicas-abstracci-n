#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<float> cola;
    int opcion;
    float valor;

    do {
        cout << "\n--- COLA CON QUEUE ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (cola.size() >= 10) {
                    cout << "La cola esta llena.\n";
                } else {
                    cout << "Ingresa un numero: ";
                    cin >> valor;
                    cola.push(valor);
                    cout << "Elemento insertado.\n";
                }
                break;

            case 2:
                if (cola.empty()) {
                    cout << "La cola esta vacia.\n";
                } else {
                    cout << "Eliminado: " << cola.front() << endl;
                    cola.pop();
                }
                break;

            case 3: {
                if (cola.empty()) {
                    cout << "La cola esta vacia.\n";
                } else {
                    queue<float> auxiliar = cola;

                    cout << "Elementos de la cola: ";
                    while (!auxiliar.empty()) {
                        cout << auxiliar.front() << " ";
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
