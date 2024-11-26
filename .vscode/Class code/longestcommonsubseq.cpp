#include <iostream>
#include <string>
#include <algorithm> // For max function

using namespace std;

string lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Declare a 2D array for DP table
    int L[m + 1][n + 1];

    // Build LCS length matrix
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

    // Backtrack to find the LCS
    string lcsString;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString = X[i - 1] + lcsString; // Append current character to LCS
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
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    string result = lcs(X, Y);
    cout << "Length of LCS is " << result.length() << endl;
    cout << "LCS is: " << result << endl;

    return 0;
}
