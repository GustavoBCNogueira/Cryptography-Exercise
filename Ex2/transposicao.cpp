#include <bits/stdc++.h>

using namespace std;

string transposition(string key, string message) {
    unordered_map<char, int> key_order;
    string encrypted_message;

    char base = 'a';
    for (int i = 0; i < key.size(); i++) {
        key_order[key[i]] = key[i] - base;
    }

    vector<string> columns(key.size());
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) {
            columns[i % key.size()] += message[i];
        } else {
            columns[i % key.size()] += '_';
        } 
    }

    char padding_char = '_';
    for (int i = 0; i < columns.size(); i++) {
        if (columns[i].size() < columns.size()/key.size()+1) {
            columns[i] += string(columns.size()/key.size()+1-columns[i].size(), padding_char);
        }
    }

    for (auto& p : key_order) {
        encrypted_message += columns[p.second];
    }

    return encrypted_message;
}
    
int main() {
    string message;
    string accumulator;
    while (getline(cin, accumulator)) {
        message += accumulator + "\n";
    }
    string key = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 g(rd());

    shuffle(key.begin(), key.end(), g);
    cout << "Generated key: " << key << endl;

    string encrypted_message = transposition(key, message);

    cout << encrypted_message << endl;
    
    return 0;
}