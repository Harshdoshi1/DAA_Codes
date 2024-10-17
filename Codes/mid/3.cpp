#include <iostream>
#include <queue>
#include <cmath>

bool isSteppingNumber(int num) {
    int prevDigit = -1;
    
    while (num > 0) {
        int currDigit = num % 10;
        if (prevDigit != -1 && abs(prevDigit - currDigit) != 1) {
            return false;
        }
        prevDigit = currDigit;
        num /= 10;
    }
    return true;
}

void findSteppingNumbers(int m, int n) {
    for (int i = m; i <= n; ++i) {
        if (isSteppingNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << '\n';
}

int main() {
    int m, n;
    std::cout << "Enter range (m n): ";
    std::cin >> m >> n;

    findSteppingNumbers(m, n);
    return 0;
}
