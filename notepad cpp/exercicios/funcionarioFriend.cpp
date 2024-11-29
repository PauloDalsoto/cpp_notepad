#include <iostream>
#include <string>

class FolhaPagamento;  // Declaração antecipada da classe FolhaPagamento

class Funcionario {
private:
    std::string nome;
    int id;
    double salarioBase;

public:
    // Construtor para inicializar os dados do funcionário
    Funcionario(std::string n, int i, double s) : nome(n), id(i), salarioBase(s) {}

    // Funções para acessar os atributos privados (opcional, caso queira usar fora da classe)
    std::string getNome() const { return nome; }
    int getId() const { return id; }
    double getSalarioBase() const { return salarioBase; }

    // Declaração de FolhaPagamento como friend para acessar os dados privados
    friend class FolhaPagamento;
};

class FolhaPagamento {
public:
    // Método para calcular o pagamento final (salário base + bônus - desconto)
    double calcularPagamentoFinal(const Funcionario& f, double bonus, double desconto) {
        return f.salarioBase + bonus - desconto;
    }

    // Método para exibir as informações do pagamento final de um funcionário
    void exibirPagamentoFinal(const Funcionario& f, double bonus, double desconto) {
        double pagamentoFinal = calcularPagamentoFinal(f, bonus, desconto);
        std::cout << "Informações do Funcionário:" << std::endl;
        std::cout << "Nome: " << f.nome << std::endl;
        std::cout << "ID: " << f.id << std::endl;
        std::cout << "Salário Base: " << f.salarioBase << std::endl;
        std::cout << "Pagamento Final: " << pagamentoFinal << std::endl;
    }
};

int main() {
    // Criando um objeto Funcionario
    Funcionario func1("João Silva", 12345, 3000.00);

    // Criando um objeto FolhaPagamento
    FolhaPagamento folha;

    // Exibindo as informações e o pagamento final com bônus e desconto específicos
    double bonus = 500.00;  // Bônus
    double desconto = 200.00;  // Desconto

    folha.exibirPagamentoFinal(func1, bonus, desconto);

    return 0;
}
