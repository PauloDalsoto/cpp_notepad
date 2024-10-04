#include <iostream>
#include <cmath>

using namespace std;

// Classe abstrata Objeto
class Objeto {
protected:
    float x, y; // Posição
    float dx, dy; // Vetor direção
    float velocidade; // Velocidade

public:
    Objeto(float x, float y, float dx, float dy, float velocidade)
        : x(x), y(y), dx(dx), dy(dy), velocidade(velocidade) {}

    virtual ~Objeto() {}

    virtual void mover() {
        x += dx * velocidade;
        y += dy * velocidade;
    }

    virtual void exibirPosicao() const = 0;
    virtual float getRaio() const = 0; // Para verificação de colisão
    virtual float getX() const = 0; // Adicionado para obter a posição X
    virtual float getY() const = 0; // Adicionado para obter a posição Y
};

// Classe Quadrado
class Quadrado : public Objeto {
private:
    float lado; // Lado do quadrado

public:
    Quadrado(float x, float y, float dx, float dy, float velocidade, float lado)
        : Objeto(x, y, dx, dy, velocidade), lado(lado) {}

    void exibirPosicao() const override {
        cout << "Quadrado na posição (" << x << ", " << y << ") com lado " << lado << endl;
    }

    float getRaio() const override {
        return lado / 2; // Para simplicidade, retorna metade do lado como "raio"
    }

    float getX() const override { return x; } // Implementa o método getX
    float getY() const override { return y; } // Implementa o método getY
};

// Classe Círculo
class Circulo : public Objeto {
private:
    float raio; // Raio do círculo

public:
    Circulo(float x, float y, float dx, float dy, float velocidade, float raio)
        : Objeto(x, y, dx, dy, velocidade), raio(raio) {}

    void exibirPosicao() const override {
        cout << "Círculo na posição (" << x << ", " << y << ") com raio " << raio << endl;
    }

    float getRaio() const override {
        return raio; // Raio do círculo
    }

    float getX() const override { return x; } // Implementa o método getX
    float getY() const override { return y; } // Implementa o método getY
};

// Função para verificar colisão entre um quadrado e um círculo
bool verificarColisao(const Quadrado& quadrado, const Circulo& circulo) {
    // Verifica se a distância entre os centros é menor que a soma dos raios
    float distX = circulo.getX() - quadrado.getX();
    float distY = circulo.getY() - quadrado.getY();
    float distanciaCentro = sqrt(distX * distX + distY * distY);

    return distanciaCentro < (quadrado.getRaio() + circulo.getRaio());
}

int main() {
    Quadrado quadrado(0, 0, 1, 1, 1, 2); // Quadrado na posição (0,0) com lado 2
    Circulo circulo(3, 3, -1, -1, 1, 1); // Círculo na posição (3,3) com raio 1

    bool colidiu = false;

    for (int t = 0; t < 100; ++t) {
        quadrado.mover();
        circulo.mover();

        quadrado.exibirPosicao();
        circulo.exibirPosicao();

        if (verificarColisao(quadrado, circulo)) {
            cout << "Colisão detectada no tempo: " << t << " segundos." << endl;
            colidiu = true;
        }
    }

    if (!colidiu) {
        cout << "Nenhuma colisão detectada durante a simulação." << endl;
    }

    return 0;
}
