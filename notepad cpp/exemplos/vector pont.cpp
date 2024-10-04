#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    // Construtor
    Produto(const string& n, double p) : nome(n), preco(p) {}

    // Método para exibir informações do produto
    void exibirInformacoes() const {
        cout << "Nome: " << nome << ", Preço: R$ " << preco << endl;
    }

    // Getter para o preço
    double getPreco() const {
        return preco;
    }
};

int main() {
    vector<Produto*> produtos;  // Vetor de ponteiros para Produto
    int quantidade;

    cout << "Quantos produtos você deseja cadastrar? ";
    cin >> quantidade;

    // Laço para capturar informações dos produtos
    for (int i = 0; i < quantidade; ++i) {
        string nome;
        double preco;

        cout << "Digite o nome do produto " << (i + 1) << ": ";
        cin >> nome;
        cout << "Digite o preço do produto " << (i + 1) << ": ";
        cin >> preco;

        // Criando um novo objeto Produto e armazenando o ponteiro no vetor
        produtos.push_back(new Produto(nome, preco));
    }

    cout << "\nProdutos cadastrados:\n";
    for (const auto& produto : produtos) {
        produto->exibirInformacoes();  // Exibindo informações de cada produto
    }

    // Liberando a memória alocada para cada Produto
    for (auto& produto : produtos) {
        delete produto;  // Libera a memória alocada para cada Produto
    }

    return 0;
}
