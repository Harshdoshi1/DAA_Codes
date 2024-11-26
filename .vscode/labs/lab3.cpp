// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <chrono>

// using namespace std;

// long long unsigned int powerNaive(int x, int n) {
//     long long unsigned int result = 1;
//     for (int i = 0; i < n; i++) {
//         result = result * x;
//     }
//     return result;
// }

// int main() {
//     srand(time(nullptr));

//     int power = rand() % 20 + 1;
//     cout << power << endl;

//     int random_num = rand() % 50 + 1;
//     cout << random_num << endl;

//     auto start = chrono::high_resolution_clock::now();
//     cout << "with O(n):- " << powerNaive(random_num, power) << endl;
//     auto end = chrono::high_resolution_clock::now();

//     chrono::duration<double> naiveDuration = end - start;
//     cout << "Naive Duration: " << naiveDuration.count() << "s" << endl;

//     return 0;
// }

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <chrono>

// using namespace std;

// long long unsigned int powerNaive(int x, int n) {
//     long long unsigned int result = 1;
//     for (int i = 0; i < n; i++) {
//         result = result * x;
//     }
//     return result;
// }

// long long unsigned int powerOptimized(int x, int n) {
//     if (n == 0) {
//         return 1;
//     }
//     long long unsigned int halfPower = powerOptimized(x, n / 2);
//     if (n % 2 == 0) {
//         return halfPower * halfPower;
//     } else {
//         return x * halfPower * halfPower;
//     }
// }

// int main() {
//     srand(time(nullptr));

//     int power = rand() % 20 + 1;
//     cout << power << endl;

//     int random_num = rand() % 50 + 1;
//     cout << random_num << endl;

//     auto start = chrono::high_resolution_clock::now();
//     cout << "with O(log n):- " << powerOptimized(random_num, power) << endl;
//     auto end = chrono::high_resolution_clock::now();

//     chrono::duration<double> optimizedDuration = end - start;
//     cout << "Optimized Duration: " << optimizedDuration.count() << "s" << endl;

//     return 0;
// }


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

long long unsigned int powerFullyOptimized(int x, int n) {
    if (n == 0) {
        return 1;
    }
    long long unsigned int temp = powerFullyOptimized(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0) {
        return temp;
    } else {
        return temp * x;
    }
}

int main() {
    srand(time(nullptr));

    int power = rand() % 20 + 1;
    cout << power << endl;

    int random_num = rand() % 50 + 1;
    cout << random_num << endl;

    auto start = chrono::high_resolution_clock::now();
    cout << "with O(log(n)):- " << powerFullyOptimized(random_num, power) << endl;
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> fullyOptimizedDuration = end - start;
    cout << "Fully Optimized Duration: " << fullyOptimizedDuration.count() << "s" << endl;

    return 0;
}
