#include <bits/stdc++.h>

using namespace std;

string transposition(string key, string message) {
    map<char, int> key_order;

    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());

    for (int i = 0; i < key.size(); i++) {
        key_order[key[i]] = i;
    }

    vector<string> columns(key.size());
    for (int i = 0; i < message.size(); i++) {
        columns[i % key.size()] += message[i];
    }

    char padding_char = 'z', base = 'a';
    int shift = 0;
    for (int i = 0; i < columns.size(); i++) {
        if (columns[i].size() < key.size()) {
            for (int j = columns[i].size(); j < key.size(); j++) {
                columns[i] += (padding_char-base-shift+26)%26+base;
                shift++;
            }
        }
    }

    string encrypted_message;
    for (char& ch : sorted_key) {
        encrypted_message += columns[key_order[ch]];
    }

    return encrypted_message;
}

int main() {
    string message;
    getline(cin, message);
    string key;
    cin >> key;
    set<char> unique_chars(key.begin(), key.end());
    // Check if the key has unique characters
    if (unique_chars.size() != key.size()) {
        cout << "Invalid key. Key must contain unique characters." << endl;
        return 1;
    }

    // Verify if the key is valid
    for (char& c : key) {
        if (!isalpha(c)) {
            cout << "Invalid key. Key must contain only alphabetic characters." << endl;
            return 1;
        }
    }

    // Normalize the key to lowercase 
    for (char& c : key) {
        c = tolower(c);
    }

    string encrypted_message = transposition(key, message);

    cout << encrypted_message << endl;
    
    return 0;
}