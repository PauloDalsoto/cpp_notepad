#ifndef CIRCLE_H    // Guardas de inclusão
#define CIRCLE_H

const double PI = 3.14159;  // Declaração de constante

// Declaração da função para calcular a área do círculo
double calculateCircleArea(double radius);

// Classe Circle
class Circle {
private:
    double radius;  // Atributo privado para armazenar o raio

public:
    // Construtor
    Circle(double r);

    // Método para calcular a área do círculo
    double calculateArea() const;

    // Método para obter o valor do raio
    double getRadius() const;

    // Método para definir um novo valor para o raio
    void setRadius(double r);
};

#endif  // CIRCLE_H
