#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++.

using namespace std;

// Função para criptografar uma mensagem usando o método de transposição.
string transposition_encrypt(string key, string message) {
    vector<int> key_order; // Vetor para armazenar a ordem dos índices da chave.
    string encrypted_message; // String que armazenará a mensagem criptografada.
    
    char base = 'a'; // Base para calcular os índices da chave (assumindo letras minúsculas).
    for (int i = 0; i < key.size(); i++) {
        key_order.push_back(key[i] - base); // Converte cada caractere da chave em um índice numérico.
    }

    vector<string> columns(key.size()); // Vetor de strings para armazenar as colunas da transposição.
    for (int i = 0; i < message.size(); i++) {
        columns[i % key.size()] += message[i]; // Distribui os caracteres da mensagem nas colunas.
    }

    char padding_char = ' '; // Caractere de preenchimento para completar as colunas.
    for (int i = 0; i < columns.size(); i++) {
        // Preenche as colunas que não têm o tamanho necessário.
        if (columns[i].size() < columns.size() / key.size() + 1) {
            columns[i] += string(columns.size() / key.size() + 1 - columns[i].size(), padding_char);
        }
    }

    // Concatena as colunas na ordem definida pela chave.
    for (int& i : key_order) {
        encrypted_message += columns[i];
    }

    return encrypted_message; // Retorna a mensagem criptografada.
}

// Função para descriptografar uma mensagem criptografada por transposição.
string transposition_decrypt(string key, string message) {
    vector<int> key_order; // Vetor para armazenar a ordem dos índices da chave.
    string decrypted_message; // String que armazenará a mensagem descriptografada.

    char base = 'a'; // Base para calcular os índices da chave.
    for (int i = 0; i < key.size(); i++) {
        key_order.push_back({key[i] - base}); // Converte cada caractere da chave em um índice numérico.
    }

    vector<string> columns(key.size()); // Vetor de strings para armazenar as colunas da transposição.
    for (int i = 0; i < message.size(); i++) {
        columns[i % key.size()] += message[i]; // Distribui os caracteres da mensagem criptografada nas colunas.
    }   

    // Reorganiza as colunas na ordem original da chave.
    for (int i = 0; i < columns.size(); i++) {
        auto it = find(key_order.begin(), key_order.end(), i); // Encontra o índice correspondente na chave.
        if (it != key_order.end()) {
            int index = distance(key_order.begin(), it); // Calcula a posição do índice.
            decrypted_message += columns[index]; // Adiciona os caracteres na ordem correta.
        }
    }

    return decrypted_message; // Retorna a mensagem descriptografada.
}

int main() {
    string message; // String para armazenar a mensagem de entrada.
    string accumulator; // String auxiliar para acumular as linhas da entrada.
    while (getline(cin, accumulator)) {
        message += accumulator + "\n"; // Lê a entrada linha por linha e concatena na mensagem.
    }

    string key = "abcdefghijklmnopqrstuvwxyz"; // Chave inicial (alfabeto em ordem).
    random_device rd; // Dispositivo de geração de números aleatórios.
    mt19937 g(rd()); // Gerador de números aleatórios (Mersenne Twister).

    shuffle(key.begin(), key.end(), g); // Embaralha a chave para criar uma ordem aleatória.
    string encrypted_message = transposition_encrypt(key, message); // Criptografa a mensagem.

    cout << "Encrypted message: " << encrypted_message  << endl; // Exibe a mensagem criptografada.

    string decrypted_message = transposition_decrypt(key, encrypted_message); // Descriptografa a mensagem.

    cout << "Decrypted message: " << decrypted_message << endl; // Exibe a mensagem descriptografada.
    
    return 0;
}