#include <iostream>
#include <string>
using namespace std;

// Nuevo tipo de dato
struct Alumno {
    string nombre;
    int edad;
    float calificacion;
};

int main() {
    int opcion;

    do {
        cout << "\n===== ORDENAMIENTO BURBUJA =====" << endl;
        cout << "1. Ordenar numeros enteros" << endl;
        cout << "2. Ordenar caracteres" << endl;
        cout << "3. Ordenar alumnos" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            int numeros[5];
            int aux;

            cout << "\nIngresa 5 numeros enteros:\n";
            for (int i = 0; i < 5; i++) {
                cin >> numeros[i];
            }

            // Ordenamiento burbuja
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4 - i; j++) {
                    if (numeros[j] > numeros[j + 1]) {
                        aux = numeros[j];
                        numeros[j] = numeros[j + 1];
                        numeros[j + 1] = aux;
                    }
                }
            }

            cout << "\nNumeros ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << numeros[i] << " ";
            }
            cout << endl;
            break;
        }

        case 2: {
            char letras[5];
            char aux;

            cout << "\nIngresa 5 caracteres:\n";
            for (int i = 0; i < 5; i++) {
                cin >> letras[i];
            }

            // Ordenamiento burbuja
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4 - i; j++) {
                    if (letras[j] > letras[j + 1]) {
                        aux = letras[j];
                        letras[j] = letras[j + 1];
                        letras[j + 1] = aux;
                    }
                }
            }

            cout << "\nCaracteres ordenados: ";
            for (int i = 0; i < 5; i++) {
                cout << letras[i] << " ";
            }
            cout << endl;
            break;
        }

        case 3: {
            Alumno alumnos[3];
            Alumno aux;

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

            // Ordenamiento burbuja
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2 - i; j++) {
                    if (alumnos[j].calificacion >
                        alumnos[j + 1].calificacion) {

                        aux = alumnos[j];
                        alumnos[j] = alumnos[j + 1];
                        alumnos[j + 1] = aux;
                    }
                }
            }

            cout << "\nAlumnos ordenados por calificacion:\n";

            for (int i = 0; i < 3; i++) {
                cout << alumnos[i].nombre << " - "
                     << alumnos[i].edad << " anios - "
                     << alumnos[i].calificacion << endl;
            }
            break;
        }

        case 4:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "\nOpcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
