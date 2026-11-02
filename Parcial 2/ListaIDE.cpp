#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<float> lista;
    int opcion;
    float valor;

    do {
        cout << "\n--- LISTA CON LIST ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Buscar\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (lista.size() >= 10) {
                    cout << "La lista esta llena.\n";
                } else {
                    cout << "Ingresa un numero: ";
                    cin >> valor;
                    lista.push_back(valor);
                    cout << "Elemento insertado.\n";
                }
                break;

            case 2: {
                if (lista.empty()) {
                    cout << "La lista esta vacia.\n";
                    break;
                }

                cout << "Valor a eliminar: ";
                cin >> valor;

                auto it = find(lista.begin(), lista.end(), valor);

                if (it != lista.end()) {
                    lista.erase(it);
                    cout << "Elemento eliminado.\n";
                } else {
                    cout << "Elemento no encontrado.\n";
                }
                break;
            }

            case 3:
                if (lista.empty()) {
                    cout << "La lista esta vacia.\n";
                } else {
                    cout << "Elementos: ";
                    for (float numero : lista) {
                        cout << numero << " ";
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Valor a buscar: ";
                cin >> valor;

                if (find(lista.begin(), lista.end(), valor)
                    != lista.end()) {
                    cout << "Elemento encontrado.\n";
                } else {
                    cout << "Elemento no encontrado.\n";
                }
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion incorrecta.\n";
        }

    } while (opcion != 5);

    return 0;
}
