#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    // Exemplo 1: Usando auto com variáveis simples
    auto x = 5;  // O tipo de x será deduzido como int
    auto y = 3.14;  // O tipo de y será deduzido como double
    std::cout << "x: " << x << ", y: " << y << std::endl;

    // Exemplo 2: Usando auto com contêineres (std::vector)
    std::vector<int> vec = {10, 20, 30, 40};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // auto deduz o tipo do iterador (std::vector<int>::iterator)
    }
    std::cout << std::endl;

    // Exemplo 3: Usando auto com range-based for loop (C++11 ou superior)
    for (auto element : vec) {
        std::cout << element << " ";  // auto deduz o tipo do elemento (int)
    }
    std::cout << std::endl;

    // Exemplo 4: Usando auto com map (std::map)
    std::map<std::string, int> m = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    for (auto& pair : m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Exemplo 5: Usando auto com funções
    auto sum = [](int a, int b) -> int { return a + b; };  // auto deduz o tipo da função
    std::cout << "Soma de 10 e 20: " << sum(10, 20) << std::endl;

    // Exemplo 6: Usando auto com tipos complexos
    auto lambda = [](int x) { return x * x; };  // auto deduz o tipo da função lambda
    std::cout << "Quadrado de 4: " << lambda(4) << std::endl;

    return 0;
}
