#include <iostream>
#include <stack>

// Função para exibir os elementos da pilha
void printStack(std::stack<int> stack) {
    std::cout << "Elementos da pilha (do topo para a base): ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

// Função para inverter uma pilha
std::stack<int> reverseStack(std::stack<int> stack) {
    std::stack<int> tempStack;
    while (!stack.empty()) {
        tempStack.push(stack.top());
        stack.pop();
    }
    return tempStack;
}

// Função para copiar uma pilha
std::stack<int> copyStack(const std::stack<int>& stack) {
    std::stack<int> tempStack = stack;  // Copia a pilha original
    return tempStack;
}

// Função principal
int main() {
    std::stack<int> stack;

    // Operações básicas de pilha
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Pilha após adicionar 10, 20, 30:" << std::endl;
    printStack(stack);

    // Removendo o elemento do topo
    stack.pop();
    std::cout << "\nPilha após remover o elemento do topo:" << std::endl;
    printStack(stack);

    // Acessando o elemento do topo
    if (!stack.empty()) {
        std::cout << "\nElemento do topo: " << stack.top() << std::endl;
    }

    // Verificando se a pilha está vazia
    std::cout << "\nA pilha está vazia? " << (stack.empty() ? "Sim" : "Não") << std::endl;

    // Copiando a pilha
    std::stack<int> copiedStack = copyStack(stack);
    std::cout << "\nCópia da pilha original:" << std::endl;
    printStack(copiedStack);

    // Invertendo a pilha
    std::stack<int> reversedStack = reverseStack(stack);
    std::cout << "\nPilha invertida:" << std::endl;
    printStack(reversedStack);

    return 0;
}
