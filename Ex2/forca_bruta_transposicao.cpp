#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++.

using namespace std;

int main() {
    string message; // String para armazenar a mensagem de entrada.
    string accumulator; // String auxiliar para acumular as linhas da entrada.

    // Lê a entrada linha por linha e concatena na string `message`.
    while (getline(cin, accumulator)) {
        message += accumulator + "\n"; // Adiciona cada linha lida à mensagem.
    }

    // Ordena os caracteres da mensagem em ordem lexicográfica.
    sort(message.begin(), message.end());

    // Gera todas as permutações possíveis da mensagem e as imprime.
    while (next_permutation(message.begin(), message.end())) {
        cout << message << endl; // Exibe cada permutação gerada.
    }
}