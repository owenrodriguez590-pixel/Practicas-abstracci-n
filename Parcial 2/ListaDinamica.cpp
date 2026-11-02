#include <iostream>
using namespace std;

struct Nodo {
    float dato;
    Nodo* siguiente;
};

void insertar(Nodo*& lista, int& cantidad) {
    if (cantidad >= 10) {
        cout << "La lista esta llena.\n";
        return;
    }

    float valor;
    cout << "Ingresa un numero: ";
    cin >> valor;

    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* actual = lista;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }

    cantidad++;
    cout << "Elemento insertado.\n";
}

void eliminar(Nodo*& lista, int& cantidad) {
    if (lista == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    float valor;
    cout << "Valor a eliminar: ";
    cin >> valor;

    Nodo* actual = lista;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "Elemento no encontrado.\n";
        return;
    }

    if (anterior == nullptr) {
        lista = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cantidad--;
    cout << "Elemento eliminado.\n";
}

void mostrar(Nodo* lista) {
    if (lista == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    cout << "Elementos: ";
    while (lista != nullptr) {
        cout << lista->dato << " ";
        lista = lista->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n--- LISTA DINAMICA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertar(lista, cantidad);
                break;
            case 2:
                eliminar(lista, cantidad);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
    } while (opcion != 4);

    while (lista != nullptr) {
        Nodo* auxiliar = lista;
        lista = lista->siguiente;
        delete auxiliar;
    }

    return 0;
}
