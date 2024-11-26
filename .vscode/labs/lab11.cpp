// #include <iostream>
// #include <string>
// using namespace std;

// void search(string& pat, string& txt) {
//     int M = pat.size();
//     int N = txt.size();

//     for (int i = 0; i <= N - M; i++) {
//         int j;
//         for (j = 0; j < M; j++) {
//             if (txt[i + j] != pat[j]) {
//                 break;
//             }
//         }
//         if (j == M) {
//             cout << "Pattern found at index " << i << endl;
//         }
//     }
// }

// int main() {
//     string txt1 = "AABAACAADAABAABA";
//     string pat1 = "AABA";
//     cout << "Example 1: " << endl;
//     search(pat1, txt1);
    
//     string txt2 = "agd";
//     string pat2 = "g";
//     cout << "\nExample 2: " << endl;
//     search(pat2, txt2);
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rabinKarp(const string& text, const string& pattern, int prime) {
    int n = text.length();
    int m = pattern.length();
    int d = 256;
    int pHash = 0;
    int tHash = 0;
    int h = 1;
    
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % prime;
    }
    
    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % prime;
        tHash = (d * tHash + text[i]) % prime;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % prime;
            if (tHash < 0) {
                tHash = tHash + prime;
            }
        }
    }
}

int main() {
    string text, pattern;
    int prime = 101;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    rabinKarp(text, pattern, prime);
    return 0;
}
