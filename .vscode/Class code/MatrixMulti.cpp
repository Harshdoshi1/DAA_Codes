#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

int matrixChainOrder(int p[], int n) {
    // Declare a 2D array for storing the minimum number of multiplications
    int m[n][n];

    // Initialize diagonal elements to 0
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // Calculate the minimum number of multiplications
    for (int D = 1; D < n - 1; D++) { // D is the chain length
        for (int i = 1; i < n - D; i++) {
            int j = i + D; // End of the chain
            m[i][j] = INT_MAX; // Initialize to a large value
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q; // Update with the minimum value
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr[] = {5, 4, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, n) << endl;
    return 0;
}
