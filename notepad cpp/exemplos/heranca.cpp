#include <iostream>
using namespace std;

// Classe base (superclasse)
class Animal {
public:
    // Método virtual que permite sobrescrita nas subclasses
    virtual void fazerSom() {
        cout << "O animal faz um som." << endl;
    }

    // Método não virtual, para demonstrar uso de 'super'
    void comer() {
        cout << "O animal está comendo." << endl;
    }
};

// Classe derivada (subclasse) - Cão
class Cao : public Animal {
public:
    // Sobrescrevendo o método virtual
    void fazerSom() override {
        cout << "O cão late." << endl;
    }

    // Método específico da subclasse
    void abanarRabo() {
        cout << "O cão está abanando o rabo." << endl;
    }

    // Método para chamar o método da classe base
    void usarMetodoSuper() {
        cout << "Usando o método 'comer' da classe base:" << endl;
        Animal::comer(); // Chamada ao método da superclasse
    }
};

// Classe derivada (subclasse) - Gato
class Gato : public Animal {
public:
    // Sobrescrevendo o método virtual
    void fazerSom() override {
        cout << "O gato mia." << endl;
    }
};

// Função para demonstrar polimorfismo
void emitirSom(Animal* animal) {
    // Polimorfismo: executa o método sobrescrito dependendo do tipo do objeto
    animal->fazerSom();
}

int main() {
    // Criando objetos das subclasses
    Cao meuCao;
    Gato meuGato;

    // Demonstração de polimorfismo
    emitirSom(&meuCao); // Saída: O cão late.
    emitirSom(&meuGato); // Saída: O gato mia.

    // Usando métodos específicos da subclasse
    meuCao.abanarRabo();

    // Chamando método da classe base a partir da subclasse
    meuCao.usarMetodoSuper(); // Saída: O animal está comendo.

    return 0;
}
