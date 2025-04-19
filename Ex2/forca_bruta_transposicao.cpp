#include <bits/stdc++.h>

using namespace std;

int main() {
    string message;
    string accumulator;
    while (getline(cin, accumulator)) {
        message += accumulator + "\n";
    }
    sort(message.begin(), message.end());

    while (next_permutation(message.begin(), message.end())) {
        cout << message << endl;
    }
}