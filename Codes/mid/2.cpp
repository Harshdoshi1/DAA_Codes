#include <iostream>
#include <cmath>

void findMultiplicativeTriplets(int mul) {
    int maxSum = -1;
    int iBest = 0, jBest = 0, kBest = 0;

    for (int i = 1; i <= sqrt(mul); ++i) {
        if (mul % i == 0) {
            for (int j = i + 1; j <= sqrt(mul); ++j) {
                if ((mul / i) % j == 0) {
                    int k = mul / (i * j);
                    if (i != j && j != k && i != k) {
                        int sum = i + j + k;
                        if (sum > maxSum) {
                            maxSum = sum;
                            iBest = i;
                            jBest = j;
                            kBest = k;
                        }
                    }
                }
            }
        }
    }

    if (maxSum > 0) {
        std::cout << "Triplet found: " << iBest << ", " << jBest << ", " << kBest << " with sum: " << maxSum << '\n';
    } else {
        std::cout << "No triplet found for " << mul << '\n';
    }
}

int main() {
    int mul;
    std::cout << "Enter mul: ";
    std::cin >> mul;

    findMultiplicativeTriplets(mul);
    return 0;
}
