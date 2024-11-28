#include "circle.h"  // Inclui o cabeçalho

// Implementação da função global
double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

// Construtor da classe Circle
Circle::Circle(double r) : radius(r) {}

// Método para calcular a área
double Circle::calculateArea() const {
    return PI * radius * radius;
}

// Método para obter o raio
double Circle::getRadius() const {
    return radius;
}

// Método para definir um novo valor para o raio
void Circle::setRadius(double r) {
    radius = r;
}
