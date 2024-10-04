#include <iostream>
using namespace std;

// Classe base
class Animal {
protected:
    string nome;
    int idade;

public:
    // Construtor da classe base
    Animal(string _nome, int _idade) : nome(_nome), idade(_idade) {
        cout << "Construtor de Animal chamado para: " << nome << endl;
    }

    // Método para exibir informações
    void exibirInfo() const {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

// Classe derivada
class Cachorro : public Animal {
private:
    string raca;

public:
    // Herança do construtor da classe base
    using Animal::Animal;  // Isso herda os construtores de Animal

    // Construtor específico da classe derivada
    Cachorro(string _nome, int _idade, string _raca) : Animal(_nome, _idade), raca(_raca) {
        cout << "Construtor de Cachorro chamado para: " << nome << " de raca " << raca << endl;
    }

    // Método para exibir informações do cachorro
    void exibirInfo() const {
        Animal::exibirInfo();  // Utilizando o método da classe base
        cout << "Raça: " << raca << endl;
    }
};

int main() {
    // Criando objeto de Animal
    Animal a("Tigre", 5);
    a.exibirInfo();

    cout << endl;

    // Criando objeto de Cachorro
    Cachorro c("Rex", 3, "Labrador");
    c.exibirInfo();

    return 0;
}
