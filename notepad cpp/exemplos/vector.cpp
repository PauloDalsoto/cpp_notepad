#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Criando um vetor de inteiros vazio
    vector<int> numeros;

    // Adicionando elementos no vetor
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    // Exibindo os elementos do vetor usando um loop for tradicional
    cout << "Elementos no vetor (usando for tradicional): ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";  // Acessando elementos com o operador []
    }
    cout << endl;

    // Exibindo os elementos do vetor usando um loop for-each
    cout << "Elementos no vetor (usando for-each): ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // Inserindo um elemento em uma posição específica
    numeros.insert(numeros.begin() + 1, 15);  // Inserir 15 na posição 1 (segunda posição)

    // Exibindo os elementos após a inserção
    cout << "Vetor após inserção: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // Removendo o último elemento
    numeros.pop_back();

    // Exibindo os elementos após a remoção
    cout << "Vetor após remoção do último elemento: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // Acessando o primeiro e o último elemento
    cout << "Primeiro elemento: " << numeros.front() << endl;
    cout << "Último elemento: " << numeros.back() << endl;

    // Verificando o tamanho atual do vetor
    cout << "Tamanho do vetor: " << numeros.size() << endl;

    // Limpando todo o conteúdo do vetor
    numeros.clear();

    // Verificando se o vetor está vazio
    if (numeros.empty()) {
        cout << "O vetor está vazio." << endl;
    }

    return 0;
}
