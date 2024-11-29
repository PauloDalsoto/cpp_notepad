#include <iostream>
#include <map>  // Necessário para usar std::map

void mostrarMap(const std::map<int, std::string>& m) {
    std::cout << "Conteúdo do map: \n";
    for (const auto& pair : m) {
        std::cout << "Chave: " << pair.first << " | Valor: " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Criação de um map que armazena inteiros como chave e strings como valor
    std::map<int, std::string> mapa;

    // Insercao de elementos
    mapa[1] = "Um";
    mapa[2] = "Dois";
    mapa[3] = "Tres";
    mapa[4] = "Quatro";
    mapa[5] = "Cinco";

    // Exibir o mapa apos insercao
    std::cout << "Apos insercao de elementos:" << std::endl;
    mostrarMap(mapa);

    // Utilizando o 'find' para procurar por uma chave
    auto it = mapa.find(3);  // Procurar pela chave 3
    if (it != mapa.end()) {
        std::cout << "Elemento encontrado: Chave = " << it->first << ", Valor = " << it->second << std::endl;
    } else {
        std::cout << "Elemento não encontrado!" << std::endl;
    }

    // Utilizando 'count' para verificar a existência de uma chave
    int chaveBusca = 4;
    if (mapa.count(chaveBusca)) {
        std::cout << "A chave " << chaveBusca << " existe no mapa." << std::endl;
    } else {
        std::cout << "A chave " << chaveBusca << " não existe no mapa." << std::endl;
    }

    // Remover um elemento usando 'erase' pela chave
    mapa.erase(2);  // Remove o elemento com chave 2

    // Exibir mapa apos remoção
    std::cout << "Apos remoção da chave 2:" << std::endl;
    mostrarMap(mapa);

    // Remover um intervalo de elementos com 'erase'
    auto itStart = mapa.find(3);
    auto itEnd = mapa.find(5);  // A chave 5 será excluída

    mapa.erase(itStart, itEnd);  // Remove os elementos de 3 até antes de 5

    // Exibir mapa apos remoção de intervalo
    std::cout << "Apos remoção do intervalo de chaves [3, 5):" << std::endl;
    mostrarMap(mapa);

    // Utilizando 'clear' para limpar todos os elementos do mapa
    mapa.clear();  // Remove todos os elementos do mapa

    // Exibir mapa apos 'clear'
    std::cout << "Apos limpar todos os elementos (clear):" << std::endl;
    mostrarMap(mapa);

    // Insercao de novos elementos apos o 'clear'
    mapa[6] = "Seis";
    mapa[7] = "Sete";

    std::cout << "Apos insercao de novos elementos:" << std::endl;
    mostrarMap(mapa);

    // Verificando o tamanho do mapa
    std::cout << "Tamanho do mapa: " << mapa.size() << std::endl;

    return 0;
}
