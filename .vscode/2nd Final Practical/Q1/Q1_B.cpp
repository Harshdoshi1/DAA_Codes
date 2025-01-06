#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string Sort(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

//

    string lcsString;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString = X[i - 1] + lcsString; 
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcsString;
}

int main() {
    string O = "bac";
    string S = "abacabad";

    string result = Sort(O, S);
    cout << "O : " << result << endl;
    cout << "S : "<< S << endl;

    cout << "OUTPUT : bbaaaacd "<< endl;

    return 0;
}
