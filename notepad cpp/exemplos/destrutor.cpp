#include <iostream>
using namespace std;

class Vetor {
private:
    int* arr;  // Atributo ponteiro para um array dinâmico
    int tamanho;

public:
    // Construtor
    Vetor(int tam) : tamanho(tam) {
        arr = new int[tamanho];  // Alocação dinâmica de memória para o array
        cout << "Construtor chamado. Array de tamanho " << tamanho << " alocado." << endl;
    }

    // Método para definir valor no array
    void setValor(int indice, int valor) {
        if (indice >= 0 && indice < tamanho) {
            arr[indice] = valor;
        }
    }

    // Método para exibir o array
    void exibir() const {
        for (int i = 0; i < tamanho; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destrutor
    ~Vetor() {
        delete[] arr;  // Libera a memória alocada para o array
        cout << "Destrutor chamado. Memória liberada." << endl;
    }
};

int main() {
    // Instanciando o objeto Vetor
    Vetor meuVetor(5);  // Criando um vetor de tamanho 5

    // Definindo alguns valores no array
    meuVetor.setValor(0, 10);
    meuVetor.setValor(1, 20);
    meuVetor.setValor(2, 30);
    meuVetor.setValor(3, 40);
    meuVetor.setValor(4, 50);

    // Exibindo os valores do array
    meuVetor.exibir();

    // Ao sair do escopo, o destrutor será chamado automaticamente
    return 0;
}
