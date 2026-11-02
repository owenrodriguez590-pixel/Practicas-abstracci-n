//Programa ColasPunteros sin decimales
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
using namespace std;


struct Nodo {
    double dato;
    Nodo* siguiente;
};

void insertar(Nodo*& frente, Nodo*& final, double valor) {
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

    cout << "Elemento insertado correctamente.\n";
}

void eliminar(Nodo*& frente, Nodo*& final) {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    Nodo* auxiliar = frente;

    cout << "Elemento eliminado: "
         << frente->dato << endl;

    frente = frente->siguiente;

    if (frente == nullptr) {
        final = nullptr;
    }

    delete auxiliar;
}

void mostrar(Nodo* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "\nElementos de la cola:\n";

    while (frente != nullptr) {
        cout << frente->dato << " ";
        frente = frente->siguiente;
    }

    cout << endl;
}

double leerNumero() {
    string entrada;
    double numero;
    char extra;

    while (true) {
        cout << "Ingrese un numero: ";
        cin >> entrada;

                for (char& c : entrada) {
            if (c == ',') {
                c = '.';
            }
        }

        stringstream convertir(entrada);

        if ((convertir >> numero) &&
            !(convertir >> extra)) {
            return numero;
        }

        cout << "Numero no valido. Intente otra vez.\n";
    }
}

int main() {
    Nodo* frente = nullptr;
    Nodo* final = nullptr;

    int opcion;
    double valor;

    cout << setprecision(10);

    do {
        cout << "\n--- COLA DINAMICA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion no valida.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                valor = leerNumero();
                insertar(frente, final, valor);
                break;

            case 2:
                eliminar(frente, final);
                break;

            case 3:
                mostrar(frente);
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 4);

        while (frente != nullptr) {
        Nodo* auxiliar = frente;
        frente = frente->siguiente;
        delete auxiliar;
    }

    final = nullptr;

    return 0;
}


