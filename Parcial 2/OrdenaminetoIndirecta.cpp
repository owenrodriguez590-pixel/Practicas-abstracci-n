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
bool mayor(int a, int b) {
    return a > b;
}

bool mayor(char a, char b) {
    return a > b;
}

bool mayor(const Alumno &a, const Alumno &b) {
    return a.calificacion > b.calificacion;
}

// Ordenamiento Burbuja indirecto
template <typename T>
void burbujaIndirecta(T datos[], int indices[], int n) {

    // Inicializar los indices
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Ordenar los indices con Burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            if (mayor(datos[indices[j]],
                      datos[indices[j + 1]])) {

                int aux = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = aux;
            }
        }
    }
}

// Mostrar indices ordenados
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
        cout << "\n===== BURBUJA INDIRECTA =====\n";
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

            burbujaIndirecta(numeros, indices, 5);

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

            burbujaIndirecta(letras, indices, 5);

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

            burbujaIndirecta(alumnos, indices, 3);

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
