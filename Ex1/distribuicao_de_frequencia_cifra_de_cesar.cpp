#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++.

using namespace std;

// Classe para definir um comparador personalizado para ordenar pares.
class comparator {
    public:
       // Compara dois pares com base no segundo elemento (frequência).
       bool operator()(const pair<int, double>& x, const pair<char, double>& y) { 
           return y.second < x.second; 
       } 
};

// Função para descriptografar uma mensagem cifrada usando a Cifra de César.
string decrypt(const string& encrypted_message, int shift) {
    string decrypted_message = ""; // String para armazenar a mensagem descriptografada.
    for (char c : encrypted_message) {
        if (isalpha(c)) { // Verifica se o caractere é uma letra.
            char base = islower(c) ? 'a' : 'A'; // Determina a base ('a' para minúsculas, 'A' para maiúsculas).
            // Calcula o caractere descriptografado aplicando o shift inverso.
            char decrypted_char = (c - base - shift + 26) % 26 + base; // +26 para evitar valores negativos.
            decrypted_message += decrypted_char; // Adiciona o caractere descriptografado à mensagem.
        } else {
            decrypted_message += c; // Caracteres não alfabéticos permanecem inalterados.
        }
    }
    return decrypted_message; // Retorna a mensagem descriptografada.
}

// Função para inicializar as frequências de letras na língua portuguesa.
vector<pair<char, double>> frequency_init() {
    // Vetor contendo as letras e suas frequências aproximadas.
    vector<pair<char, double>> frequency = {
        {'a', 13.9}, // a
        {'b', 1.0},  // b
        {'c', 4.4},  // c
        {'d', 5.4},  // d
        {'e', 12.2}, // e
        {'f', 1.0},  // f
        {'g', 1.2},  // g
        {'h', 0.8},  // h
        {'i', 6.9},  // i
        {'j', 0.4},  // j
        {'k', 0.1},  // k
        {'l', 2.8},  // l
        {'m', 4.2},  // m
        {'n', 5.3},  // n
        {'o', 10.8}, // o
        {'p', 2.9},  // p
        {'q', 0.9},  // q
        {'r', 6.9},  // r
        {'s', 7.9},  // s
        {'t', 4.9},  // t
        {'u', 4.0},  // u
        {'v', 1.3},  // v
        {'w', 0.0},  // w
        {'x', 0.3},  // x
        {'y', 0.0},  // y
        {'z', 0.4}   // z
    };

    return frequency; // Retorna o vetor de frequências.
}

// Função para avaliar a frequência de caracteres em um texto cifrado.
void frequency_evaluation(string cipher) {
    // Inicializa as frequências de letras na língua portuguesa.
    vector<pair<char, double>> frequency = frequency_init();
    string decrypted_message; // String para armazenar a mensagem descriptografada.

    // Ordena as frequências de letras em ordem decrescente.
    sort(frequency.begin(), frequency.end(), comparator());

    // Vetor para armazenar a frequência de cada letra no texto cifrado.
    vector<pair<char, int>> cipher_frequency(26);
    for (int i = 0; i < cipher.size(); i++) {
        if (isalpha(cipher[i])) { // Verifica se o caractere é uma letra.
            // Atualiza a frequência da letra no texto cifrado.
            cipher_frequency[cipher[i] - 'a'].first = cipher[i];
            cipher_frequency[cipher[i] - 'a'].second++;
        }
    }

    // Ordena as frequências de letras do texto cifrado em ordem decrescente.
    sort(cipher_frequency.begin(), cipher_frequency.end(), comparator());

    // Tenta descriptografar o texto usando as 3 letras mais frequentes.
    for (int i = 0; i < 3; i++) {
        // Calcula a chave (shift) com base na diferença entre as letras mais frequentes.
        int key = cipher_frequency[0].first - frequency[i].first;
        decrypted_message = decrypt(cipher, key); // Descriptografa o texto com a chave calculada.
        cout << decrypted_message << endl; // Exibe a mensagem descriptografada.
    }

    return; // Finaliza a função.
}

int main() {
    string message; // String para armazenar a mensagem de entrada.
    string accumulator; // String auxiliar para acumular as linhas da entrada.

    // Lê a entrada linha por linha e concatena na string `message`.
    while (getline(cin, accumulator)) {
        message += accumulator + "\n"; // Adiciona cada linha lida à mensagem.
    }

    // Avalia a frequência de caracteres no texto cifrado.
    frequency_evaluation(message);

    return 0; // Finaliza o programa.
}