#include <iostream>
using namespace std;

void primeFacctorization(int n) {
    
    while (n % 2 == 0) {
        cout << "2 ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2) {
        cout << n;
    }
    cout << endl; 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        cout << "No prime factorization for numbers less than or equal to 1." << endl;
    } else {
        cout << "Prime factors: ";
        primeFacctorization(n);
    }

    return 0;
}
