#include <iostream>
#include <stack>
#include <string>

// Função para avaliar a expressão em notação pós-fixa
double avaliarExpressao(const std::string& expressao) {
    std::stack<double> pilha;
    std::string token = "";

    // Percorre a expressão caractere por caractere
    for (char c : expressao) {
        if (c == ' ') {
            // Quando encontrar um espaço, significa que temos um token completo
            if (token != "") {
                // Se o token for um número, empilha
                pilha.push(std::stod(token));
                token = ""; // Limpa o token para o próximo número
            }
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Se for um operador, realiza a operação com os dois operandos do topo da pilha
            if (pilha.size() < 2) {
                std::cerr << "Erro: expressao invalida. Operadores insuficientes.\n";
                return 0;
            }

            double operando2 = pilha.top();
            pilha.pop();
            double operando1 = pilha.top();
            pilha.pop();

            double resultado = 0;
            if (c == '+') {
                resultado = operando1 + operando2;
            } else if (c == '-') {
                resultado = operando1 - operando2;
            } else if (c == '*') {
                resultado = operando1 * operando2;
            } else if (c == '/') {
                if (operando2 == 0) {
                    std::cerr << "Erro: divisao por zero!\n";
                    return 0;
                }
                resultado = operando1 / operando2;
            }

            pilha.push(resultado);
        } 
        else {
            // Se não for espaço ou operador, então deve ser parte de um número
            token += c;  // Concatena o caractere ao token
        }
    }

    // No final, deve restar apenas um valor na pilha
    if (pilha.size() != 1) {
        std::cerr << "Erro: expressao invalida. Operadores ou operandos faltando.\n";
        return 0;
    }

    return pilha.top();
}

int main() {
    std::string expressao;
    std::cout << "Digite uma expressao em notacao pos-fixa (RPN): ";
    std::getline(std::cin, expressao);

    double resultado = avaliarExpressao(expressao);
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
