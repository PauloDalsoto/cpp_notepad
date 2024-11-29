#include <iostream>
#include <stack> // Necessário para usar a pilha (stack)

void converterDecimalParaBinario(int numero) {
    // Criando uma pilha para armazenar os restos das divisões
    std::stack<int> pilha;

    // Enquanto o número for maior que 0
    while (numero > 0) {
        int resto = numero % 2;  // Resto da divisão por 2
        pilha.push(resto);        // Empilha o resto
        numero = numero / 2;     // Divide o número por 2
    }

    // Exibir o número binário (desempilhando os valores da pilha)
    std::cout << "Equivalente binário: ";
    while (!pilha.empty()) {
        std::cout << pilha.top();  // Exibe o valor no topo da pilha
        pilha.pop();               // Remove o valor do topo
    }
    std::cout << std::endl;
}

int main() {
    int numeroDecimal;

    // Solicita ao usuário que insira um número decimal
    std::cout << "Digite um número decimal: ";
    std::cin >> numeroDecimal;

    // Chama a função para converter o número para binário
    converterDecimalParaBinario(numeroDecimal);

    return 0;
}
