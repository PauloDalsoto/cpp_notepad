#include <iostream>
#include <list>

// Função para imprimir os elementos da lista
void printList(const std::list<int>& lst) {
    for (int item : lst) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> myList;

    // 1. Adicionar elementos no fim da lista
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    std::cout << "Lista apos adicionar no fim: ";
    printList(myList);

    // 2. Adicionar elementos no início da lista
    myList.push_front(5);
    myList.push_front(1);
    std::cout << "Lista apos adicionar no início: ";
    printList(myList);

    // 3. Adicionar elementos em uma posição específica
    auto it = myList.begin();
    std::advance(it, 2);  // Avança o iterador para a 3ª posição
    myList.insert(it, 15);
    std::cout << "Lista apos inserir na 3ª posição: ";
    printList(myList);

    // 4. Remover o primeiro elemento
    myList.pop_front();
    std::cout << "Lista apos remover o primeiro elemento: ";
    printList(myList);

    // 5. Remover o último elemento
    myList.pop_back();
    std::cout << "Lista apos remover o último elemento: ";
    printList(myList);

    // 6. Remover um elemento específico (valor 15)
    for (auto it = myList.begin(); it != myList.end(); ) {
        if (*it == 15) {
            it = myList.erase(it);  // Retorna o próximo iterador apos a remoção
        } else {
            ++it;
        }
    }
    std::cout << "Lista apos remover o elemento 15: ";
    printList(myList);

    // 7. Remover um elemento em uma posição específica
    it = myList.begin();
    std::advance(it, 1);  // Avança para a 2ª posição
    myList.erase(it);
    std::cout << "Lista apos remover o elemento na 2ª posição: ";
    printList(myList);

    // 8. Inverter a lista
    myList.reverse();
    std::cout << "Lista apos inverter: ";
    printList(myList);

    // 9. Ordenar a lista (implementando uma ordenação manual)
    for (auto i = myList.begin(); i != myList.end(); ++i) {
        for (auto j = std::next(i); j != myList.end(); ++j) {
            if (*i > *j) {
                std::swap(*i, *j);
            }
        }
    }
    std::cout << "Lista apos ordenar: ";
    printList(myList);

    // 10. Tamanho da lista
    std::cout << "Tamanho da lista: " << myList.size() << std::endl;

    // 11. Acessar o primeiro e o último elemento
    std::cout << "Primeiro elemento: " << myList.front() << std::endl;
    std::cout << "Ultimo elemento: " << myList.back() << std::endl;

    // 12. Encontrar um elemento específico (20) manualmente
    bool found = false;
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        if (*it == 20) {
            found = true;
            break;
        }
    }
    if (found) {
        std::cout << "Elemento 20 encontrado!" << std::endl;
    } else {
        std::cout << "Elemento 20 não encontrado!" << std::endl;
    }

    // 13. Limpar a lista
    myList.clear();
    std::cout << "Lista apos limpar: ";
    printList(myList);

    return 0;
}
