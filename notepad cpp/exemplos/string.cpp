#include <iostream>
#include <string>

using namespace std;

int main() {
    string linha;

    cout << "Digite uma linha de texto: ";
    getline(cin, linha); // Lê uma linha inteira de texto

    cout << "Você digitou: " << linha << endl;
    
    // Criação de strings
    string str1 = "Olá";
    string str2 = "Mundo";

    // Concatenando strings
    string mensagem = str1 + ", " + str2 + "!";
    cout << "Mensagem: " << mensagem << endl;

    // Comparando strings
    if (str1 == str2) {
        cout << "As strings são iguais." << endl;
    } else {
        cout << "As strings são diferentes." << endl;
    }

    // Tamanho da string
    cout << "Tamanho da string 'mensagem': " << mensagem.length() << endl;

    // Acessando caracteres
    char primeiroChar = mensagem[0];
    cout << "Primeiro caractere da mensagem: " << primeiroChar << endl;

    // Modificando um caractere
    mensagem[0] = 'o';
    cout << "Mensagem após a modificação: " << mensagem << endl;

    // Buscando por um caractere
    size_t pos = mensagem.find('M');
    if (pos != string::npos) {
        cout << "'M' encontrado na posição: " << pos << endl;
    } else {
        cout << "'M' não encontrado na mensagem." << endl;
    }

    // Substring
    string substring = mensagem.substr(4, 5); // Posição 4, 5 caracteres
    cout << "Substring: " << substring << endl;

    // Transformando para maiúsculas
    for (char &c : mensagem) {
        c = toupper(c);
    }
    cout << "Mensagem em maiúsculas: " << mensagem << endl;

    // Transformando para minúsculas
    for (char &c : mensagem) {
        c = tolower(c);
    }
    cout << "Mensagem em minúsculas: " << mensagem << endl;

    return 0;
}
