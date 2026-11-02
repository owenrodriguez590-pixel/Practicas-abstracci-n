#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Nuevo tipo de dato
struct Alumno {
    string nombre;
    int edad;
    float calificacion;
};

// Funcion para comparar alumnos
bool comparar(Alumno a, Alumno b) {
    return a.calificacion <= b.calificacion;
}

// Funcion para comparar enteros
bool comparar(int a, int b) {
    return a <= b;
}

// Funcion para comparar caracteres
bool comparar(char a, char b) {
    return a <= b;
}

// Funcion que mezcla los elementos ordenados
template <typename T>
void mezclar(T datos[], int inicio, int medio, int fin) {

    int i = inicio;
    int j = medio + 1;
    vector<T> auxiliar;

    while (i <= medio && j <= fin) {
        if (comparar(datos[i], datos[j])) {
            auxiliar.push_back(datos[i]);
            i++;
        } else {
            auxiliar.push_back(datos[j]);
            j++;
        }
    }

    while (i <= medio) {
        auxiliar.push_back(datos[i]);
        i++;
    }

    while (j <= fin) {
        auxiliar.push_back(datos[j]);
        j++;
    }

    for (int k = 0; k < (int)auxiliar.size(); k++) {
        datos[inicio + k] = auxiliar[k];
    }
}

// Funcion principal de Merge Sort
template <typename T>
void mergeSort(T datos[], int inicio, int fin) {

    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        mergeSort(datos, inicio, medio);
        mergeSort(datos, medio + 1, fin);

        mezclar(datos, inicio, medio, fin);
    }
}

int main() {
    int opcion;

    do {
        cout << "\n===== ORDENAMIENTO MERGE SORT =====\n";
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

            mergeSort(numeros, 0, 4);

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

            mergeSort(letras, 0, 4);

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

            mergeSort(alumnos, 0, 2);

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
