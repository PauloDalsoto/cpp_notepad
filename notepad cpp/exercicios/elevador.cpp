#include <iostream>

class Elevador {
private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int pessoasPresentes;

public:
    // Construtor
    Elevador(int capacidade, int totalAndares) 
        : andarAtual(0), totalAndares(totalAndares), capacidade(capacidade), pessoasPresentes(0) {}

    // Método para entrar no elevador
    void entra() {
        if (pessoasPresentes < capacidade) {
            pessoasPresentes++;
            std::cout << "Uma pessoa entrou. Total de pessoas: " << pessoasPresentes << std::endl;
        } else {
            std::cout << "Elevador cheio!" << std::endl;
        }
    }

    // Método para sair do elevador
    void sai() {
        if (pessoasPresentes > 0) {
            pessoasPresentes--;
            std::cout << "Uma pessoa saiu. Total de pessoas: " << pessoasPresentes << std::endl;
        } else {
            std::cout << "Elevador vazio!" << std::endl;
        }
    }

    // Métodos para subir e descer
    void sobe() {
        if (andarAtual < totalAndares) {
            andarAtual++;
            std::cout << "Subindo para o andar: " << andarAtual << std::endl;
        } else {
            std::cout << "Já está no último andar!" << std::endl;
        }
    }

    void desce() {
        if (andarAtual > 0) {
            andarAtual--;
            std::cout << "Descendo para o andar: " << andarAtual << std::endl;
        } else {
            std::cout << "Já está no térreo!" << std::endl;
        }
    }

    // Método para obter dados
    void exibirDados() const {
        std::cout << "Andar Atual: " << andarAtual << "\nTotal de Andares: " << totalAndares 
                  << "\nCapacidade: " << capacidade << "\nPessoas Presentes: " << pessoasPresentes << std::endl;
    }
};

int main() {
    Elevador elevador(5, 10); // capacidade de 5 pessoas e 10 andares
    elevador.entra();
    elevador.sobe();
    elevador.sobe();
    elevador.sai();
    elevador.exibirDados();

    return 0;
}
