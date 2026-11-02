
#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) {
        return a + b;
    }

    double restar(double a, double b) {
        return a - b;
    }

    double multiplicar(double a, double b) {
        return a * b;
    }

    double dividir(double a, double b) {
        if (b == 0) {
            cout << "Error: division entre cero" << endl;
            return 0;
        }
        return a / b;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    double potencia(double base, int exponente) {
        double resultado = 1;

        for (int i = 0; i < exponente; i++)
            resultado *= base;

        return resultado;
    }
};

int main() {
    CalculadoraNueva c;

    cout << "Suma: " << c.sumar(5, 3) << endl;
    cout << "Resta: " << c.restar(5, 3) << endl;
    cout << "Multiplicacion: " << c.multiplicar(5, 3) << endl;
    cout << "Division: " << c.dividir(6, 3) << endl;
    cout << "Potencia: " << c.potencia(2, 3) << endl;

    return 0;
}
