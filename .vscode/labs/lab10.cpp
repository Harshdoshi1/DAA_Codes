#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int D = 1; D < n - 1; D++) {
        for (int i = 1; i < n - D; i++) {
            int j = i + D;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int size = 5;
    int arr[] = {10, 5, 20, 10, 5};
    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, size) << endl;
    return 0;
}
