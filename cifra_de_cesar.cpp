#include <bits/stdc++.h>

using namespace std;

string encrypt(const string& message, int shift) {
    string encrypted_message = "";
    for (char c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char encrypted_char = (c - base + shift) % 26 + base;
            encrypted_message += encrypted_char;
        } else {
            encrypted_message += c; // Non-alphabetic characters remain unchanged
        }
    }
    return encrypted_message;
}

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

int main() {
    string message;
    getline(cin, message);

    int shift;
    cin >> shift;
    shift %= 26; // Normalize the shift to be within 0-25
    
    string encrypted_message = encrypt(message, shift);
    cout << "Encrypted message: " << encrypted_message << endl;
    string decrypted_message = decrypt(encrypted_message, shift);
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}