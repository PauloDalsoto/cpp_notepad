#include <iostream>
using namespace std;

class Coordenada {
private:
    double x, y;

public:
    // Construtor padrão
    Coordenada(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    // Sobrecarga do operador +
    Coordenada operator+(const Coordenada& outra) const {
        return Coordenada(x + outra.x, y + outra.y);
    }

    // Sobrecarga do operador -
    Coordenada operator-(const Coordenada& outra) const {
        return Coordenada(x - outra.x, y - outra.y);
    }

    // Sobrecarga do operador ==
    bool operator==(const Coordenada& outra) const {
        return (x == outra.x && y == outra.y);
    }

    // Sobrecarga do operador <<
    friend ostream& operator<<(ostream& saida, const Coordenada& coord) {
        saida << "(" << coord.x << ", " << coord.y << ")";
        return saida;
    }

    // Método para acessar coordenadas X e Y
    void mostrarCoordenadas() const {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    // Criando duas coordenadas
    Coordenada p1(3.0, 4.0);
    Coordenada p2(1.5, 2.5);

    // Sobrecarga do operador +
    Coordenada soma = p1 + p2;
    cout << "Soma de coordenadas: " << soma << endl;

    // Sobrecarga do operador -
    Coordenada subtracao = p1 - p2;
    cout << "Subtracao de coordenadas: " << subtracao << endl;

    // Sobrecarga do operador ==
    if (p1 == p2) {
        cout << "As coordenadas p1 e p2 sao iguais." << endl;
    } else {
        cout << "As coordenadas p1 e p2 sao diferentes." << endl;
    }

    return 0;
}
