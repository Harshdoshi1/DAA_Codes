// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstdlib>
// #include <ctime>
// #include <chrono>

// using namespace std;

// void merge(vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     vector<int> L(n1), R(n2);

//     for (int i = 0; i < n1; ++i)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; ++j)
//         R[j] = arr[mid + 1 + j];

//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             ++i;
//         } else {
//             arr[k] = R[j];
//             ++j;
//         }
//         ++k;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         ++i;
//         ++k;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         ++j;
//         ++k;
//     }
// }

// void mergeSort(vector<int>& arr, int Lowerbound, int Upperbound) {
//     if (Lowerbound < Upperbound) {
//         int mid = (Lowerbound + Upperbound) / 2;
//         mergeSort(arr, Lowerbound, mid);
//         mergeSort(arr, mid + 1, Upperbound);
//         merge(arr, Lowerbound, mid, Upperbound);
//     }
// }

// int main() {
//     vector<int> arr(50000);
//     srand(time(0));
//     generate(arr.begin(), arr.end(), rand);

//     vector<int> arr3(50000);
//     generate(arr3.begin(), arr3.end(), rand);

//     auto start = chrono::high_resolution_clock::now();
//     mergeSort(arr3, 0, arr3.size() - 1);
//     auto end = chrono::high_resolution_clock::now();

//     chrono::duration<double> duration = end - start;
//     cout << "Time taken to sort the unsorted array using Merge Sort: " << duration.count() << " seconds" << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int Partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main() {
    vector<int> arr(50000);
    srand(time(0));
    generate(arr.begin(), arr.end(), rand);

    auto start = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << "Time taken to sort the unsorted array using Quick Sort: " << duration.count() << " seconds" << endl;

    return 0;
}
