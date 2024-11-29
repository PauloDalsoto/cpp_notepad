#include <iostream>
#include <vector>

// -------------------------
// Template de Função
// -------------------------
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// -------------------------
// Template de Classe (Stack)
// -------------------------
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    // Adiciona um elemento ao topo da pilha
    void push(T value) {
        elements.push_back(value);
    }

    // Remove o elemento do topo da pilha
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std::cout << "Pilha vazia! Não é possível remover." << std::endl;
        }
    }

    // Retorna o elemento do topo da pilha
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            throw std::out_of_range("Pilha vazia!");
        }
    }

    // Verifica se a pilha está vazia
    bool empty() const {
        return elements.empty();
    }

    // Exibe todos os elementos da pilha
    void display() const {
        std::cout << "Elementos da pilha: ";
        for (const T& el : elements) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

// -------------------------
// Função Principal
// -------------------------
int main() {
    // Testando template de função
    std::cout << "Maior entre 10 e 20: " << maxValue(10, 20) << std::endl;
    std::cout << "Maior entre 3.5 e 2.7: " << maxValue(3.5, 2.7) << std::endl;
    std::cout << "Maior entre 'a' e 'z': " << maxValue('a', 'z') << std::endl;

    // Testando template de classe (Stack)
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.display();

    std::cout << "Topo da pilha: " << intStack.top() << std::endl;
    intStack.pop();
    intStack.display();

    // Stack de strings
    Stack<std::string> stringStack;
    stringStack.push("Olá");
    stringStack.push("Mundo");
    stringStack.display();

    stringStack.pop();
    stringStack.display();

    return 0;
}
