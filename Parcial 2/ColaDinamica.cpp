#include <iostream>
using namespace std;

struct Nodo {
    float dato;
    Nodo* siguiente;
};

void insertar(Nodo*& frente, Nodo*& final, int& cantidad) {
    if (cantidad >= 10) {
        cout << "La cola esta llena.\n";
        return;
    }

    float valor;
    cout << "Ingresa un numero: ";
    cin >> valor;

    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (frente == nullptr) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }

    cantidad++;
    cout << "Elemento insertado.\n";
}

void eliminar(Nodo*& frente, Nodo*& final, int& cantidad) {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    Nodo* auxiliar = frente;
    cout << "Elemento eliminado: " << auxiliar->dato << endl;

    frente = frente->siguiente;
    delete auxiliar;
    cantidad--;

    if (frente == nullptr) {
        final = nullptr;
    }
}

void mostrar(Nodo* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "Elementos de la cola: ";
    while (frente != nullptr) {
        cout << frente->dato << " ";
        frente = frente->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* frente = nullptr;
    Nodo* final = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n--- COLA DINAMICA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertar(frente, final, cantidad);
                break;
            case 2:
                eliminar(frente, final, cantidad);
                break;
            case 3:
                mostrar(frente);
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
    } while (opcion != 4);

    while (frente != nullptr) {
        Nodo* auxiliar = frente;
        frente = frente->siguiente;
        delete auxiliar;
    }

    return 0;
}
