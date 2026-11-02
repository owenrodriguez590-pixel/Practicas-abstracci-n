
#include <iostream>
using namespace std;

class Calculadora {
public:
    virtual int multiplicar(int a, int b) {
        return a * b;
    }
};

class CalculadoraNueva : public Calculadora {
public:
    // Sobreescritura: multiplicacion con sumas sucesivas
    int multiplicar(int a, int b) override {
        int resultado = 0;
        int signo = 1;

        if (a < 0) {
            a = -a;
            signo = -signo;
        }
        if (b < 0) {
            b = -b;
            signo = -signo;
        }

        for (int i = 0; i < b; i++)
            resultado += a;

        return resultado * signo;
    }

    // Potencia con multiplicaciones sucesivas
    int potencia(int base, int exponente) {
        int resultado = 1;

        for (int i = 0; i < exponente; i++)
            resultado = multiplicar(resultado, base);

        return resultado;
    }

    // Division entera con restas sucesivas
    int dividir(int a, int b) {
        if (b == 0) {
            cout << "No se puede dividir entre cero" << endl;
            return 0;
        }

        int signo = 1;
        if (a < 0) {
            a = -a;
            signo = -signo;
        }
        if (b < 0) {
            b = -b;
            signo = -signo;
        }

        int cociente = 0;

        while (a >= b) {
            a -= b;
            cociente++;
        }

        return cociente * signo;
    }
};

int main() {
    CalculadoraNueva c;

    cout << "Multiplicacion: " << c.multiplicar(4, 3) << endl;
    cout << "Potencia: " << c.potencia(2, 4) << endl;
    cout << "Division entera: " << c.dividir(10, 3) << endl;

    return 0;
}
