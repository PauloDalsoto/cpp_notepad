#include <iostream>
using namespace std;

class Carro {
private:
    string marca;

public:
    // Construtor
    Carro(string _marca) : marca(_marca) {
        cout << "Construtor chamado para carro: " << marca << endl;
    }

    // Método para exibir a marca
    void mostrarMarca() const {
        cout << "Marca do carro: " << marca << endl;
    }

    // Destrutor
    ~Carro() {
        cout << "Destrutor chamado para carro: " << marca << endl;
    }
};

int main() {
    // Instanciando diretamente (alocação na pilha)
    Carro carroDireto("Toyota");
    carroDireto.mostrarMarca();  // Acessando o objeto diretamente

    cout << endl;

    // Instanciando com ponteiro (alocação na heap)
    Carro* carroPonteiro = new Carro("Honda");
    carroPonteiro->mostrarMarca();  // Acessando o objeto via ponteiro

    // Liberando a memória manualmente
    delete carroPonteiro;

    return 0;
}
