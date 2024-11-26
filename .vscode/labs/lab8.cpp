
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string lcs(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    // declaring the array for storing the dp values
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Build LCS length matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
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
    string s1;
    string s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the Second string: ";
    cin>>s2;
    string result = lcs(s1, s2);
    cout << "Length of LCS is " << result.length() << endl;
    cout << "LCS is: " << result << endl;
    return 0;
}