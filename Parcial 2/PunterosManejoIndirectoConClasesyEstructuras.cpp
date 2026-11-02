#include <iostream>
#include <string>
using namespace std;

// Estructura con puntero al mismo tipo
struct Alumno {
    string nombre;
    int edad;
    float calificacion;
    Alumno* siguiente;
};

int main() {

    Alumno alumnos[3];
    Alumno* inicio = nullptr;

    cout << "===== REGISTRO DE ALUMNOS =====\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nAlumno " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> alumnos[i].nombre;

        cout << "Edad: ";
        cin >> alumnos[i].edad;

        cout << "Calificacion: ";
        cin >> alumnos[i].calificacion;

        alumnos[i].siguiente = nullptr;
    }

    // Enlazar los alumnos
    for (int i = 0; i < 2; i++) {
        alumnos[i].siguiente = &alumnos[i + 1];
    }

    inicio = &alumnos[0];

    cout << "\n===== LISTA ORIGINAL =====\n";

    Alumno* actual = inicio;

    while (actual != nullptr) {
        cout << actual->nombre << " - "
             << actual->calificacion << endl;

        actual = actual->siguiente;
    }

    // Ordenamiento indirecto de los enlaces
    Alumno* ordenado = nullptr;

    while (inicio != nullptr) {

        Alumno* nodo = inicio;
        inicio = inicio->siguiente;

        if (ordenado == nullptr ||
            nodo->calificacion <
            ordenado->calificacion) {

            nodo->siguiente = ordenado;
            ordenado = nodo;

        } else {

            Alumno* aux = ordenado;

            while (aux->siguiente != nullptr &&
                   aux->siguiente->calificacion <=
                   nodo->calificacion) {

                aux = aux->siguiente;
            }

            nodo->siguiente = aux->siguiente;
            aux->siguiente = nodo;
        }
    }

    cout << "\n===== LISTA ORDENADA =====\n";

    actual = ordenado;

    while (actual != nullptr) {

        cout << actual->nombre << " - "
             << actual->calificacion << endl;

        actual = actual->siguiente;
    }

    return 0;
}
