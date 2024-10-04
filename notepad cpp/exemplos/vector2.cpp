#include <iostream>
#include <vector>
#include <limits> // Para std::numeric_limits

using namespace std;

void inserirNumero(vector<int>& numeros) {
    int numero;
    cout << "Digite um número inteiro: ";
    cin >> numero;
    numeros.push_back(numero);
    cout << "Número inserido com sucesso.\n";
}

void removerNumero(vector<int>& numeros) {
    if (!numeros.empty()) {
        numeros.pop_back();
        cout << "Último número removido com sucesso.\n";
    } else {
        cout << "O vetor está vazio. Não há números para remover.\n";
    }
}

void exibirNumeros(const vector<int>& numeros) {
    if (numeros.empty()) {
        cout << "O vetor está vazio.\n";
        return;
    }
    cout << "Números armazenados: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
}

void exibirMaiorMenor(const vector<int>& numeros) {
    if (numeros.empty()) {
        cout << "O vetor está vazio. Não é possível encontrar o maior e o menor número.\n";
        return;
    }

    int maior = std::numeric_limits<int>::min();
    int menor = std::numeric_limits<int>::max();

    for (int num : numeros) {
        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
    }

    cout << "Maior número: " << maior << endl;
    cout << "Menor número: " << menor << endl;
}

int main() {
    vector<int> numeros;
    int opcao;

    do {
        cout << "\nEscolha uma opção:\n";
        cout << "1. Inserir número\n";
        cout << "2. Remover último número\n";
        cout << "3. Exibir todos os números\n";
        cout << "4. Exibir maior e menor número\n";
        cout << "5. Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirNumero(numeros);
                break;
            case 2:
                removerNumero(numeros);
                break;
            case 3:
                exibirNumeros(numeros);
                break;
            case 4:
                exibirMaiorMenor(numeros);
                break;
            case 5:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
