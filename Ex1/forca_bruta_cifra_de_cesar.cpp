#include <bits/stdc++.h>    

using namespace std;

string brute_force_decrypt(const string& encrypted_message) {
    string decrypted_message = "";
    for (int shift = 1; shift < 26; ++shift) {
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
        cout << "Shift " << shift << ": " << decrypted_message << endl;
    }
    return decrypted_message;
}

int main() {
    string encrypted_message;
    string accumulator;
    while (getline(cin, accumulator)) {
        encrypted_message += accumulator + "\n";
    }
    brute_force_decrypt(encrypted_message);

    return 0;
}