#include <iostream>
#include <vector>
#include <string>

// Definição dos namespaces
namespace Shopping {
    
    namespace Funcionarios {
        class Funcionario {
        private:
            std::string nome;
            int id;
            std::string cargo;

        public:
            // Construtor para inicializar os dados do funcionário
            Funcionario(std::string n, int i, std::string c) : nome(n), id(i), cargo(c) {}

            // Métodos para acessar os atributos
            std::string getNome() const { return nome; }
            int getId() const { return id; }
            std::string getCargo() const { return cargo; }
        };
    }

    namespace Lojas {
        class Loja {
        private:
            std::string nome;
            std::vector<Funcionarios::Funcionario> funcionarios;

        public:
            // Construtor para inicializar o nome da loja
            Loja(std::string n) : nome(n) {}

            // Método para adicionar um funcionário à loja
            void adicionarFuncionario(const Funcionarios::Funcionario& f) {
                funcionarios.push_back(f);
            }

            // Método para exibir os dados da loja e seus funcionários
            void exibirInformacoes() {
                std::cout << "Loja: " << nome << std::endl;
                std::cout << "Funcionários:" << std::endl;
                for (const auto& f : funcionarios) {
                    std::cout << "Nome: " << f.getNome() << ", ID: " << f.getId() << ", Cargo: " << f.getCargo() << std::endl;
                }
            }
        };
    }

    namespace Clientes {
        class Cliente {
        private:
            std::string nome;
            int id;
            int pontosFidelidade;

        public:
            // Construtor para inicializar o cliente
            Cliente(std::string n, int i) : nome(n), id(i), pontosFidelidade(0) {}

            // Método para acumular pontos de fidelidade
            void acumularPontos(int pontos) {
                pontosFidelidade += pontos;
            }

            // Método para exibir as informações do cliente
            void exibirInformacoes() const {
                std::cout << "Cliente: " << nome << ", ID: " << id << ", Pontos de Fidelidade: " << pontosFidelidade << std::endl;
            }
        };
    }
}

int main() {
    // Criando funcionários
    Shopping::Funcionarios::Funcionario f1("Carlos Souza", 101, "Vendedor");
    Shopping::Funcionarios::Funcionario f2("Ana Costa", 102, "Gerente");

    // Criando loja e adicionando funcionários
    Shopping::Lojas::Loja loja1("Super Loja");
    loja1.adicionarFuncionario(f1);
    loja1.adicionarFuncionario(f2);

    // Criando clientes e acumulando pontos
    Shopping::Clientes::Cliente c1("João Silva", 201);
    Shopping::Clientes::Cliente c2("Maria Oliveira", 202);
    c1.acumularPontos(150);
    c2.acumularPontos(200);

    // Exibindo informações da loja
    loja1.exibirInformacoes();

    // Exibindo informações dos clientes
    c1.exibirInformacoes();
    c2.exibirInformacoes();

    return 0;
}
