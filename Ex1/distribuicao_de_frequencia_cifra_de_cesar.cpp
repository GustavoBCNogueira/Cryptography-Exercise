#include <bits/stdc++.h>

using namespace std;    


class comparator { // simple comparison function
    public:
       bool operator()(const pair<int, double>& x,const pair<char, double>& y) { return y.second < x.second; } 
};

string decrypt(const string& encrypted_message, int shift) {
    string decrypted_message = "";
    for (char c : encrypted_message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char decrypted_char = (c - base - shift + 26) % 26 + base; // +26 to handle negative shifts
            decrypted_message += decrypted_char;
        } else {
            decrypted_message += c; // Non-alphabetic characters remain unchanged
        }
    }
    return decrypted_message;
}

vector<pair<char, double>> frequency_init() {
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

    return frequency;
}

void frequency_evaluation(string cipher) {
    vector<pair<char, double>> frequency = frequency_init();
    string decrypted_message;

    sort(frequency.begin(), frequency.end(), comparator());

    vector<pair<char, int>> cipher_frequency(26);
    for (int i = 0; i < cipher.size(); i++) {
        if (isalpha(cipher[i])) {
            cipher_frequency[cipher[i] - 'a'].first = cipher[i];
            cipher_frequency[cipher[i] - 'a'].second++;
        }
    }

    sort(cipher_frequency.begin(), cipher_frequency.end(), comparator());

    for (int i = 0; i < 3; i++) {
        int key = cipher_frequency[0].first - frequency[i].first;
        decrypted_message = decrypt(cipher, key);
        cout << decrypted_message << endl;
    }

    return;
}

int main() {
    string message;
    string accumulator;
    while (getline(cin, accumulator)) {
        message += accumulator + "\n";
    }

    frequency_evaluation(message);

    return 0;
}