#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Definir o caminho para o arquivo
const std::string CAMINHO_ARQUIVO = "produtos.txt";

class Produto {
public:
    std::string nome;
    int codigo;
    double preco;

    Produto() : codigo(0), preco(0.0) {}
    Produto(std::string n, int c, double p) : nome(n), codigo(c), preco(p) {}

    // Função para exibir as informações do produto
    void exibirProduto() {
        std::cout << "Código: " << codigo << " | Nome: " << nome << " | Preço: R$ " << preco << std::endl;
    }

    // Função para salvar o produto no arquivo
    void salvarProduto(std::ofstream &arquivo) {
        arquivo << codigo << " " << nome << " " << preco << std::endl;
    }

    // Função para carregar o produto do arquivo
    static Produto carregarProduto(std::ifstream &arquivo) {
        Produto p;
        arquivo >> p.codigo >> p.nome >> p.preco;
        return p;
    }
};

// Função para adicionar um produto
void adicionarProduto(std::vector<Produto>& produtos) {
    std::string nome;
    int codigo;
    double preco;

    std::cout << "Digite o nome do produto: ";
    std::cin.ignore();  // Para limpar o buffer do cin
    std::getline(std::cin, nome);

    std::cout << "Digite o código do produto (número único): ";
    std::cin >> codigo;

    std::cout << "Digite o preço do produto: ";
    std::cin >> preco;

    Produto p(nome, codigo, preco);
    produtos.push_back(p);
}

// Função para listar todos os produtos cadastrados
void listarProdutos(const std::vector<Produto>& produtos) {
    if (produtos.empty()) {
        std::cout << "Nenhum produto cadastrado." << std::endl;
        return;
    }
    for (const auto& produto : produtos) {
        produto.exibirProduto();
    }
}

// Função para buscar um produto pelo código
void buscarProduto(const std::vector<Produto>& produtos) {
    int codigo;
    std::cout << "Digite o código do produto: ";
    std::cin >> codigo;

    bool encontrado = false;
    for (const auto& produto : produtos) {
        if (produto.codigo == codigo) {
            produto.exibirProduto();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Produto não encontrado!" << std::endl;
    }
}

// Função para atualizar o preço de um produto
void atualizarPreco(std::vector<Produto>& produtos) {
    int codigo;
    std::cout << "Digite o código do produto para atualizar o preço: ";
    std::cin >> codigo;

    bool encontrado = false;
    for (auto& produto : produtos) {
        if (produto.codigo == codigo) {
            std::cout << "Digite o novo preço: ";
            std::cin >> produto.preco;
            std::cout << "Preço atualizado com sucesso!" << std::endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Produto não encontrado!" << std::endl;
    }
}

// Função para salvar os produtos no arquivo
void salvarProdutos(const std::vector<Produto>& produtos) {
    std::ofstream arquivo(CAMINHO_ARQUIVO);  // Usando a constante para o caminho do arquivo
    if (arquivo.is_open()) {
        for (const auto& produto : produtos) {
            produto.salvarProduto(arquivo);
        }
        std::cout << "Produtos salvos com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar!" << std::endl;
    }
}

// Função para carregar os produtos do arquivo
void carregarProdutos(std::vector<Produto>& produtos) {
    std::ifstream arquivo(CAMINHO_ARQUIVO);  // Usando a constante para o caminho do arquivo
    if (arquivo.is_open()) {
        Produto p;
        while (arquivo >> p.codigo >> p.nome >> p.preco) {
            produtos.push_back(p);
        }
        std::cout << "Produtos carregados com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para carregar!" << std::endl;
    }
}

int main() {
    std::vector<Produto> produtos;
    int opcao;

    // Carregar produtos do arquivo
    carregarProdutos(produtos);

    do {
        std::cout << "\n--- Sistema de Cadastro de Produtos ---\n";
        std::cout << "1. Adicionar Produto\n";
        std::cout << "2. Listar Produtos\n";
        std::cout << "3. Buscar Produto\n";
        std::cout << "4. Atualizar Preço\n";
        std::cout << "5. Salvar Produtos\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(produtos);
                break;
            case 2:
                listarProdutos(produtos);
                break;
            case 3:
                buscarProduto(produtos);
                break;
            case 4:
                atualizarPreco(produtos);
                break;
            case 5:
                salvarProdutos(produtos);
                break;
            case 6:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
