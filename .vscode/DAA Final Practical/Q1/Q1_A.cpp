#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    string text;
    for (int i = 0; i < 25; i++) {
        text += "ATGC"[rand() % 4]; // itt will Randomly pick from 'A', 'T', 'G', 'C'
    }

    string pattern = "AGC";
    int patternCount = 0;

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    //

    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        if (text.substr(i, pattern.length()) == pattern) {
            cout << "Pattern found at position " << i << endl;
            patternCount++;
        }
    }

    cout << "Pattern occurred " << patternCount << " times." << endl;

    return 0;
}
