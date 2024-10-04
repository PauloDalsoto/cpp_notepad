#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numerosVetor;
    int quantidade;

    cout << "Quantos números você deseja inserir no vetor? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        int numero;
        cout << "Digite o número " << (i + 1) << ": ";
        cin >> numero;
        numerosVetor.push_back(numero);
    }

    cout << "Números armazenados no vetor: ";
    for (int num : numerosVetor) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
