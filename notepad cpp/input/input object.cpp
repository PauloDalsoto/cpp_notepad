#include <iostream>
#include <string>

using namespace std;

// Classe Pessoa
class Pessoa {
private:
    string nome;
    int idade;

public:
    // Construtor
    Pessoa(const string& nome, int idade) : nome(nome), idade(idade) {}

    // Método para exibir informações da pessoa
    void exibirInformacoes() const {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

int main() {
    string nome;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin >> nome;

    cout << "Digite a idade da pessoa: ";
    cin >> idade;

    // Criar objeto Pessoa
    Pessoa pessoa(nome, idade);
    pessoa.exibirInformacoes();

    return 0;
}
