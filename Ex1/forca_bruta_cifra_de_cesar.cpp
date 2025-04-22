#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++.

using namespace std;

// Função para tentar descriptografar uma mensagem cifrada usando força bruta.
string brute_force_decrypt(const string& encrypted_message) {
    string decrypted_message = ""; // String para armazenar a mensagem descriptografada.

    // Tenta todas as 25 possíveis rotações (shifts) da Cifra de César.
    for (int shift = 1; shift < 26; ++shift) { // O shift varia de 1 a 25 (não inclui 0, pois seria a mensagem original).
        string decrypted_message = ""; // String temporária para armazenar o resultado de cada tentativa.

        // Percorre cada caractere da mensagem cifrada.
        for (char c : encrypted_message) {
            if (isalpha(c)) { // Verifica se o caractere é uma letra.
                char base = islower(c) ? 'a' : 'A'; // Determina a base ('a' para letras minúsculas, 'A' para maiúsculas).
                // Calcula o caractere descriptografado aplicando o shift inverso.
                char decrypted_char = (c - base - shift + 26) % 26 + base; // +26 para evitar valores negativos.
                decrypted_message += decrypted_char; // Adiciona o caractere descriptografado à mensagem temporária.
            } else {
                decrypted_message += c; // Caracteres não alfabéticos permanecem inalterados.
            }
        }

        // Exibe o resultado da tentativa com o shift atual.
        cout << "Shift " << shift << ": " << decrypted_message << endl;
    }

    return decrypted_message; // Retorna a última mensagem descriptografada (não é usada no programa).
}

int main() {
    string encrypted_message; // String para armazenar a mensagem cifrada.
    string accumulator; // String auxiliar para acumular as linhas da entrada.

    // Lê a entrada linha por linha e concatena na string `encrypted_message`.
    while (getline(cin, accumulator)) {
        encrypted_message += accumulator + "\n"; // Adiciona cada linha lida à mensagem cifrada.
    }

    // Chama a função de força bruta para tentar descriptografar a mensagem.
    brute_force_decrypt(encrypted_message);

    return 0; // Finaliza o programa.
}