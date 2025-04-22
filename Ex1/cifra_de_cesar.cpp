#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++.

using namespace std;

// Função para criptografar uma mensagem usando a Cifra de César.
string encrypt(const string& message, int shift) {
    string encrypted_message = ""; // String para armazenar a mensagem criptografada.
    for (char c : message) { // Percorre cada caractere da mensagem.
        if (isalpha(c)) { // Verifica se o caractere é uma letra.
            char base = islower(c) ? 'a' : 'A'; // Determina a base ('a' para minúsculas, 'A' para maiúsculas).
            // Calcula o caractere criptografado aplicando o deslocamento (shift).
            char encrypted_char = (c - base + shift) % 26 + base;
            encrypted_message += encrypted_char; // Adiciona o caractere criptografado à mensagem.
        } else {
            encrypted_message += c; // Caracteres não alfabéticos permanecem inalterados.
        }
    }
    return encrypted_message; // Retorna a mensagem criptografada.
}

// Função para descriptografar uma mensagem cifrada usando a Cifra de César.
string decrypt(const string& encrypted_message, int shift) {
    string decrypted_message = ""; // String para armazenar a mensagem descriptografada.
    for (char c : encrypted_message) { // Percorre cada caractere da mensagem cifrada.
        if (isalpha(c)) { // Verifica se o caractere é uma letra.
            char base = islower(c) ? 'a' : 'A'; // Determina a base ('a' para minúsculas, 'A' para maiúsculas).
            // Calcula o caractere descriptografado aplicando o deslocamento inverso (shift negativo).
            char decrypted_char = (c - base - shift + 26) % 26 + base; // +26 para evitar valores negativos.
            decrypted_message += decrypted_char; // Adiciona o caractere descriptografado à mensagem.
        } else {
            decrypted_message += c; // Caracteres não alfabéticos permanecem inalterados.
        }
    }
    return decrypted_message; // Retorna a mensagem descriptografada.
}

int main() {
    string message; // String para armazenar a mensagem de entrada.
    string accumulator; // String auxiliar para acumular as linhas da entrada.

    // Lê a entrada linha por linha e concatena na string `message`.
    while (getline(cin, accumulator)) {
        message += accumulator + "\n"; // Adiciona cada linha lida à mensagem.
    }

    int shift = 3; // Define o deslocamento (shift) para a Cifra de César.

    // Criptografa a mensagem usando o deslocamento definido.
    string encrypted_message = encrypt(message, shift);
    cout << "Encrypted message: " << encrypted_message << endl; // Exibe a mensagem criptografada.

    // Descriptografa a mensagem criptografada usando o mesmo deslocamento.
    string decrypted_message = decrypt(encrypted_message, shift);
    cout << "Decrypted message: " << decrypted_message << endl; // Exibe a mensagem descriptografada.

    return 0; // Finaliza o programa.
}