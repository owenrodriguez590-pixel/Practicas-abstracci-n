//Programa pilas
#include <iostream>
using namespace std;

const int LIMITE = 10;


struct Nodo {
    int dato;
    Nodo*  siguiente;
};

void insertar(Nodo*& cima, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = cima;
    cima = nuevo;

    cout << "Elemento insertado correctamente.\n";
}

void eliminar(Nodo*& cima) {
    if (cima == nullptr) {
        cout << "La pila esta vacia.\n";
        return;
    }

    Nodo* auxiliar = cima;
    cout << "Elemento eliminado: " << cima->dato << endl;

    cima = cima->siguiente;
    delete auxiliar;
}

void mostrar(Nodo* cima) {
    if (cima == nullptr) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "Elementos de la pila:\n";

    while (cima != nullptr) {
        cout << cima->dato << endl;
        cima = cima->siguiente;
    }
}

int main() {
    Nodo* cima = nullptr;
    int opcion, valor;

    do {
        cout << "\n--- PILA DINAMICA ---\n";
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
                insertar(cima, valor);
                break;

            case 2:
                eliminar(cima);
                break;

            case 3:
                mostrar(cima);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 4);

    while (cima != nullptr) {
        Nodo* auxiliar = cima;
        cima = cima->siguiente;
        delete auxiliar;
    }

    return 0;
}
