//Programa Lista
#include <iostream>
using namespace std;

const int LIMITE = 10;

struct Nodo {
    int dato;
    Nodo* siguiente;
};
void insertar(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* auxiliar = lista;

        while (auxiliar->siguiente != nullptr) {
            auxiliar = auxiliar->siguiente;
        }

        auxiliar->siguiente = nuevo;
    }

    cout << "Elemento insertado correctamente.\n";
}

void eliminar(Nodo*& lista, int valor) {
    if (lista == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

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
    cout << "Elemento eliminado correctamente.\n";
}

void mostrar(Nodo* lista) {
    if (lista == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    cout << "Elementos de la lista:\n";

    while (lista != nullptr) {
        cout << lista->dato << " -> ";
        lista = lista->siguiente;
    }

    cout << "NULL\n";
}

int main() {
    Nodo* lista = nullptr;
    int opcion, valor;

    do {
        cout << "\n--- LISTA DINAMICA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> valor;
                insertar(lista, valor);
                break;

            case 2:
                cout << "Ingrese el numero a eliminar: ";
                cin >> valor;
                eliminar(lista, valor);
                break;

            case 3:
                mostrar(lista);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 4);

    while (lista != nullptr) {
        Nodo* auxiliar = lista;
        lista = lista->siguiente;
        delete auxiliar;
    }

    return 0;
}
