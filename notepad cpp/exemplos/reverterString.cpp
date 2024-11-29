#include <iostream>
#include <stack>
#include <string>

// Função para reverter uma string usando uma stack
std::string reverterString(const std::string& str) {
    std::stack<char> pilha;
    
    // Empilha todos os caracteres da string
    for (char c : str) {
        pilha.push(c);
    }
    
    // Desempilha os caracteres e forma a string invertida
    std::string strInvertida;
    while (!pilha.empty()) {
        strInvertida += pilha.top();
        pilha.pop();
    }
    
    return strInvertida;
}

int main() {
    // Entrada: uma string
    std::string original = "Exemplo de String";
    
    // Revertendo a string
    std::string invertida = reverterString(original);
    
    // Exibindo a string original e a invertida
    std::cout << "Original: " << original << std::endl;
    std::cout << "Invertida: " << invertida << std::endl;
    
    return 0;
}
