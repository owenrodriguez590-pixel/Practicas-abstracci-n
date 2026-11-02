#include <iostream>
#include <string>
using namespace std;

// Nuevo tipo de dato
struct Alumno {
    string nombre;
    int edad;
    float calificacion;
};

// Comparar numeros enteros
bool menorIgual(int a, int b) {
    return a <= b;
}

// Comparar caracteres
bool menorIgual(char a, char b) {
    return a <= b;
}

// Comparar alumnos por calificacion
bool menorIgual(const Alumno &a, const Alumno &b) {
    return a.calificacion <= b.calificacion;
}

// Funcion para mezclar indices ordenados
template <typename T>
void mezclarIndirecto(
    const T datos[], int indices[],
    int inicio, int medio, int fin) {

    int n = fin - inicio + 1;
    int* auxiliar = new int[n];

    int i = inicio;
    int j = medio + 1;
    int k = 0;

    while (i <= medio && j <= fin) {

        if (menorIgual(datos[indices[i]],
                       datos[indices[j]])) {
            auxiliar[k] = indices[i];
            i++;
        } else {
            auxiliar[k] = indices[j];
            j++;
        }
        k++;
    }

    while (i <= medio) {
        auxiliar[k] = indices[i];
        i++;
        k++;
    }

    while (j <= fin) {
        auxiliar[k] = indices[j];
        j++;
        k++;
    }

    for (int x = 0; x < n; x++) {
        indices[inicio + x] = auxiliar[x];
    }

    delete[] auxiliar;
}

// Funcion Merge Sort indirecto
template <typename T>
void mergeSortIndirecto(
    const T datos[], int indices[],
    int inicio, int fin) {

    if (inicio < fin) {

        int medio = inicio + (fin - inicio) / 2;

        mergeSortIndirecto(
            datos, indices, inicio, medio);

        mergeSortIndirecto(
            datos, indices, medio + 1, fin);

        mezclarIndirecto(
            datos, indices, inicio, medio, fin);
    }
}

// Inicializar los indices
template <typename T>
void ordenarIndirecto(
    const T datos[], int indices[], int n) {

    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    mergeSortIndirecto(datos, indices, 0, n - 1);
}

// Mostrar indices
void mostrarIndices(int indices[], int n) {

    cout << "\nIndices ordenados: ";

    for (int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }

    cout << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n===== MERGE SORT INDIRECTO =====\n";
        cout << "1. Ordenar numeros enteros\n";
        cout << "2. Ordenar caracteres\n";
        cout << "3. Ordenar alumnos\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            int numeros[5];
            int indices[5];

            cout << "\nIngresa 5 numeros enteros:\n";

            for (int i = 0; i < 5; i++) {
                cin >> numeros[i];
            }

            ordenarIndirecto(numeros, indices, 5);

            cout << "\nNumeros originales: ";
            for (int i = 0; i < 5; i++) {
                cout << numeros[i] << " ";
            }

            mostrarIndices(indices, 5);

            cout << "Numeros ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << numeros[indices[i]] << " ";
            }
            cout << endl;
            break;
        }

        case 2: {
            char letras[5];
            int indices[5];

            cout << "\nIngresa 5 caracteres:\n";

            for (int i = 0; i < 5; i++) {
                cin >> letras[i];
            }

            ordenarIndirecto(letras, indices, 5);

            cout << "\nCaracteres originales: ";
            for (int i = 0; i < 5; i++) {
                cout << letras[i] << " ";
            }

            mostrarIndices(indices, 5);

            cout << "Caracteres ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << letras[indices[i]] << " ";
            }
            cout << endl;
            break;
        }

        case 3: {
            Alumno alumnos[3];
            int indices[3];

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

            ordenarIndirecto(alumnos, indices, 3);

            cout << "\nAlumnos originales:\n";

            for (int i = 0; i < 3; i++) {
                cout << alumnos[i].nombre << " - "
                     << alumnos[i].edad << " anios - "
                     << alumnos[i].calificacion << endl;
            }

            mostrarIndices(indices, 3);

            cout << "\nAlumnos ordenados por calificacion:\n";

            for (int i = 0; i < 3; i++) {
                int pos = indices[i];

                cout << alumnos[pos].nombre << " - "
                     << alumnos[pos].edad << " anios - "
                     << alumnos[pos].calificacion << endl;
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
