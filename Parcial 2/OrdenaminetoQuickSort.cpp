
#include <iostream>
#include <string>
using namespace std;

// Nuevo tipo de dato
struct Alumno {
    string nombre;
    int edad;
    float calificacion;
};

// Comparaciones para cada tipo de dato
bool menor(int a, int b) {
    return a < b;
}

bool menor(char a, char b) {
    return a < b;
}

bool menor(Alumno a, Alumno b) {
    return a.calificacion < b.calificacion;
}

// Intercambiar dos elementos
template <typename T>
void intercambiar(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}

// Funcion para dividir usando un pivote
template <typename T>
int particion(T datos[], int inicio, int fin) {

    T pivote = datos[fin];
    int i = inicio - 1;

    cout << "\nParticionando del indice "
         << inicio << " al " << fin << endl;
    cout << "Pivote seleccionado: ";

    if constexpr (false) {
        // No se utiliza
    }

    for (int j = inicio; j < fin; j++) {
        if (!menor(pivote, datos[j])) {
            i++;
            intercambiar(datos[i], datos[j]);
        }
    }

    intercambiar(datos[i + 1], datos[fin]);

    cout << "Pivote colocado en posicion "
         << i + 1 << endl;

    return i + 1;
}

// Funcion principal Quick Sort
template <typename T>
void quickSort(T datos[], int inicio, int fin) {

    if (inicio < fin) {
        int posicion = particion(datos, inicio, fin);

        quickSort(datos, inicio, posicion - 1);
        quickSort(datos, posicion + 1, fin);
    }
}

int main() {
    int opcion;

    do {
        cout << "\n===== ORDENAMIENTO QUICK SORT =====\n";
        cout << "1. Ordenar numeros enteros\n";
        cout << "2. Ordenar caracteres\n";
        cout << "3. Ordenar alumnos\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            int numeros[5];

            cout << "\nIngresa 5 numeros enteros:\n";

            for (int i = 0; i < 5; i++) {
                cin >> numeros[i];
            }

            quickSort(numeros, 0, 4);

            cout << "\nNumeros ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << numeros[i] << " ";
            }
            cout << endl;
            break;
        }

        case 2: {
            char letras[5];

            cout << "\nIngresa 5 caracteres:\n";

            for (int i = 0; i < 5; i++) {
                cin >> letras[i];
            }

            quickSort(letras, 0, 4);

            cout << "\nCaracteres ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << letras[i] << " ";
            }
            cout << endl;
            break;
        }

        case 3: {
            Alumno alumnos[3];

            cout << "\nIngresa los datos de 3 alumnos:\n";

            for (int i = 0; i < 3; i++) {
                cout << "\nAlumno " << i + 1 << endl;

                cout << "Nombre: ";
                cin >> alumnos[i].nombre;

                cout << "Edad: ";
                cin >> alumnos[i].edad;

                cout << "Calificacion: ";
                cin >> alumnos[i].calificacion;
            }

            quickSort(alumnos, 0, 2);

            cout << "\nAlumnos ordenados por calificacion:\n";

            for (int i = 0; i < 3; i++) {
                cout << alumnos[i].nombre << " - "
                     << alumnos[i].edad << " anios - "
                     << alumnos[i].calificacion << endl;
            }
            break;
        }

        case 4:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion no valida.\n";
        }

    } while (opcion != 4);

    return 0;
}
