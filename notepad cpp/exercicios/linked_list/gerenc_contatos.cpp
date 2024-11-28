#include <iostream>
#include <list>

using namespace std;

struct Contato {
    string nome;
    string numero;
    Contato() {}
    Contato(string n, string num) : nome(n), numero(num) {}
};

void addContato(list<Contato>& contatos) {
    Contato contato;

    cout << "Digite o nome do contato: ";
    cin.ignore(); //clean buffer
    getline(cin, contato.nome);

    cout << "Digite o numero do contato: ";
    cin.ignore(); //clean buffer
    getline(cin, contato.numero);

    contatos.push_back(contato);
    cout << "Contato adicionado com sucesso!\n"; 
};  

void exibirContatos(list<Contato>& contatos) {
    if (contatos.empty()) { 
        cout << "A lista de contatos esta vazia.\n";
        return; 
    }
    
    cout << "Lista de contatos (" << contatos.size() << "):\n";
    for (auto contato : contatos) {
        cout << "Nome: " << contato.nome << " | Numero: " << contato.numero << endl; 
    }
};

void removerContato(list<Contato>& contatos) {
    string nome;
    cout << "Digite o nome do contato: ";
    cin.ignore(); //clean buffer
    getline(cin, nome);

    auto it = contatos.begin();
    while (it != contatos.end()) {
        if (it->nome == nome) { 
            it = contatos.erase(it); 
            cout << "Contato '" << nome << "' removido com sucesso!\n";
            return; 
        } else {
            ++it; 
        }
    }
    cout << "Contato '" << nome << "' nao encontrado.\n";
};

void buscarContato(list<Contato>& contatos) {
    string nome;
    cout << "Digite o nome do contato: ";
    cin.ignore(); 
    getline(cin, nome);

    auto it = contatos.begin();
    while (it != contatos.end()) {
        if (it->nome == nome) { 
            cout << "Nome: " << it->nome << " | Numeros: " << it->numero << endl;
            return; 
        } else {
            ++it; 
        }
    }
    cout << "Contato '" << nome << "' nao encontrado.\n";
};

int main() {
    std::list<Contato> contatos;
    int opcao;
    contatos.push_back(Contato("Joao", "6555"));
    contatos.push_back(Contato("Maria", "222"));

    do {
        std::cout << "\n\n--- Sistema de Registro de Contatos ---\n";
        std::cout << "1. Adicionar Contato\n";
        std::cout << "2. Remover Contato\n";
        std::cout << "3. Exibir Todos os Contatos\n";
        std::cout << "4. Buscar Contato pelo Nome\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                addContato(contatos);
                break;
            case 2:
                removerContato(contatos);
                break;
            case 3:
                exibirContatos(contatos);
                break;
            case 4:
                buscarContato(contatos);
                break;
            case 5:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 5);

 
    return 0;
}