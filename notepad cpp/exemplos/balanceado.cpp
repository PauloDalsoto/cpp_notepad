#include <iostream>
#include <stack>
#include <string>

bool verificarBalanceamento(const std::string& expressao) {
    std::stack<char> pilha;

    // Itera sobre cada caractere da expressão
    for (int i = 0; i < expressao.length(); ++i) {
        char c = expressao[i];

        // Abre um delimitador
        if (c == '(' || c == '{' || c == '[') {
            pilha.push(c);
        } 
        // Fecha um delimitador
        else if (c == ')' || c == '}' || c == ']') {
            // Verifica se a pilha está vazia ou o topo não corresponde
            if (pilha.empty() ||
                (c == ')' && pilha.top() != '(') ||
                (c == '}' && pilha.top() != '{') ||
                (c == ']' && pilha.top() != '[')) {
                return false; // Fechou mais do que abriu ou incorretamente
            }
            pilha.pop(); // Fecha um delimitador corretamente
        }
    }

    // Se a pilha estiver vazia, significa que todos os delimitadores foram fechados corretamente
    return pilha.empty();
}

int main() {
    std::string expressao1 = "{[()]}";
    std::string expressao2 = "{[(])}";
    std::string expressao3 = "((())";

    // Verificando se as expressões estão balanceadas
    std::cout << "Expressão 1: " << expressao1 << " -> " 
              << (verificarBalanceamento(expressao1) ? "Balanceada" : "Não balanceada") << std::endl;

    std::cout << "Expressão 2: " << expressao2 << " -> " 
              << (verificarBalanceamento(expressao2) ? "Balanceada" : "Não balanceada") << std::endl;

    std::cout << "Expressão 3: " << expressao3 << " -> " 
              << (verificarBalanceamento(expressao3) ? "Balanceada" : "Não balanceada") << std::endl;

    return 0;
}
