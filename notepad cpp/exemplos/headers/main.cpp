#include <iostream>
#include "circle.cpp"   // MUDAR PARA .H AO ENTREGAR

int main() {
    double radius;

    // Usando a funcao global
    std::cout << "Digite o raio do circulo para a funcao global: ";
    std::cin >> radius;

    double areaFunction = calculateCircleArea(radius);  // Chama a funcao global
    std::cout << "A area (funcao global) do circulo com raio " << radius 
              << " eh: " << areaFunction << std::endl;

    // Usando a classe Circle
    Circle circle(radius);  // Cria um objeto da classe Circle

    std::cout << "\nA area (classe Circle) do circulo com raio " << circle.getRadius() 
              << " eh: " << circle.calculateArea() << std::endl;

    // Alterar o raio usando o mehtodo setRadius
    std::cout << "\nDigite um novo raio para a classe Circle: ";
    std::cin >> radius;
    circle.setRadius(radius);

    std::cout << "A nova area (classe Circle) do circulo eh: " << circle.calculateArea() << std::endl;

    return 0;
}
