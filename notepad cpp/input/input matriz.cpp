#include <iostream>
#include <vector>

using namespace std;

int main() {
    int linhas, colunas;

    cout << "Digite o número de linhas da matriz: ";
    cin >> linhas;
    cout << "Digite o número de colunas da matriz: ";
    cin >> colunas;

    vector<vector<int>> matriz(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite o número para a posição [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Exibir a matriz
    cout << "Matriz:\n";
    for (const auto& linha : matriz) {
        for (int num : linha) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
