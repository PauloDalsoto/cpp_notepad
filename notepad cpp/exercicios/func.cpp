#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe abstrata Funcionario
class Funcionario {
protected:
    string nome;
    double salarioBase;

public:
    Funcionario(const string &nome, double salarioBase)
        : nome(nome), salarioBase(salarioBase) {}

    virtual ~Funcionario() {}

    virtual double calcularSalario() const = 0; // Método virtual puro
    virtual void exibirInformacoes() const = 0; // Método virtual puro
    virtual void aumentarSalario() = 0; // Método virtual puro para aumentar salário
};

// Classe FuncionarioCLT
class FuncionarioCLT : public Funcionario {
public:
    FuncionarioCLT(const string &nome, double salarioBase)
        : Funcionario(nome, salarioBase) {}

    double calcularSalario() const override {
        return salarioBase * 1.05; // 5% de bônus
    }

    void exibirInformacoes() const override {
        cout << "Funcionário CLT: " << nome << ", Salário Base: " << salarioBase
             << ", Salário Final: " << calcularSalario() << endl;
    }

    void aumentarSalario() override {
        salarioBase *= 1.10; // Aumenta 10%
    }
};

// Classe FuncionarioPJ
class FuncionarioPJ : public Funcionario {
public:
    FuncionarioPJ(const string &nome, double salarioBase)
        : Funcionario(nome, salarioBase) {}

    double calcularSalario() const override {
        return salarioBase * 0.85; // 15% de desconto
    }

    void exibirInformacoes() const override {
        cout << "Funcionário PJ: " << nome << ", Salário Base: " << salarioBase
             << ", Salário Final: " << calcularSalario() << endl;
    }

    void aumentarSalario() override {
        salarioBase *= 1.10; // Aumenta 10%
    }
};

int main() {
    vector<Funcionario*> funcionarios;
    int numFuncionarios;
    cout << "Quantos funcionários deseja cadastrar? ";
    cin >> numFuncionarios;

    for (int i = 0; i < numFuncionarios; ++i) {
        string tipo;
        string nome;
        double salarioBase;

        cout << "Digite o tipo de funcionário (CLT/PJ): ";
        cin >> tipo;
        cout << "Digite o nome do funcionário: ";
        cin >> nome;
        cout << "Digite o salário base: ";
        cin >> salarioBase;

        if (tipo == "CLT") {
            funcionarios.push_back(new FuncionarioCLT(nome, salarioBase));
        } else if (tipo == "PJ") {
            funcionarios.push_back(new FuncionarioPJ(nome, salarioBase));
        }
    }

    cout << "\nInformações dos funcionários:\n";
    for (Funcionario* func : funcionarios) {
        func->exibirInformacoes();
    }

    // Aumentar salário base em 10%
    for (Funcionario* func : funcionarios) {
        func->aumentarSalario(); // Aumenta o salário base
    }

    cout << "\nInformações dos funcionários após aumento salarial:\n";
    for (Funcionario* func : funcionarios) {
        func->exibirInformacoes();
    }

    // Liberar memória
    for (Funcionario* func : funcionarios) {
        delete func;
    }

    return 0;
}
