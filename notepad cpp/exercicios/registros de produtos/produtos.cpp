#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string CAMINHO_ARQUIVO = "C:/Users/I749044/Documents/git/notepad cpp/exercicios/registros de produtos/produtos.txt";

struct Produto
{
    string nome;
    int codigo;
    float preco;
};

int cadastrarProduto() {
    ofstream arquivo(CAMINHO_ARQUIVO, ios::app);

    if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    Produto produto;
    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, produto.nome);
    cout << "Digite o codigo do produto: ";
    cin >> produto.codigo;
    cout << "Digite o preco do produto: ";
    cin >> produto.preco;

    arquivo << produto.nome << "," << produto.codigo << "," << produto.preco << "\n";
    arquivo.close();
    cout << "Produto cadastrado com sucesso!\n";

    return 0;
};

int exibirProdutos() {
    ifstream arquivo(CAMINHO_ARQUIVO, ios::app);
    if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }
    string linha;
    cout << "Nome\tCodigo\tPreco\n";
    cout << "--------------------------\n";

    while (getline(arquivo, linha)) {
        int pos1 = linha.find(",");
        int pos2 = linha.find(",", pos1 + 1);

        string nome = linha.substr(0, pos1);
        int codigo = stoi(linha.substr(pos1 + 1, pos2 - pos1 - 1));
        float preco = stof(linha.substr(pos2 + 1));
        
        cout << nome << "\t" << codigo << "\t" << preco << "\n";
    }

    arquivo.close();
    return 0;
};

int buscarProduto() {
    ifstream arquivo(CAMINHO_ARQUIVO, ios::app);
    if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }
    string linha, nome_procurar;
    cout << "Digite o nome do produto:\n";
    cin.ignore();
    getline(cin, nome_procurar);

    while (getline(arquivo, linha)) {
        int pos1 = linha.find(",");
        string nome = linha.substr(0, pos1);

        if (nome_procurar == nome){
            int pos2 = linha.find(",", pos1 + 1);
            int codigo = stoi(linha.substr(pos1 + 1, pos2 - pos1 - 1));
            float preco = stof(linha.substr(pos2 + 1));
            cout << "Produto encontrado: ";
            cout << nome << " | " << codigo << " | " << preco << "\n";

            return 1;
        }
    }

    arquivo.close();
    cout << "Produto " << nome_procurar << " nao encontrado!\n";
    return 1;
};

int main(){ 
    bool run = true;
    int op;

    while (run){
        cout << "\n--- Sistema de Registro de Produtos ---\n";
        cout << "1. Cadastrar Produto\n";
        cout << "2. Exibir Produtos\n";
        cout << "3. Buscar Produto\n";
        cout << "4. Sair do Programa\n";
        cout << "Escolha uma opcao: ";

        cin >> op;
        cout << "\n";

        switch (op){
            case 1:
                cadastrarProduto();
                break;
            case 2:
                exibirProdutos();
                break;
            case 3:
                buscarProduto();
                break;
            case 4:
                cout << "Saindo do programa!\n";
                run = false;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
    return 0;
}