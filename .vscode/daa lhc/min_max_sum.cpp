#include <iostream>
#include <algorithm>
using namespace std;

int findMin(int arr[], int n) {
    return *min_element(arr, arr + n);
}

int findMax(int arr[], int n) {
    return *max_element(arr, arr + n);
}

int main() {
    int arr[5];
    int sum = 0;

    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    int minNum = findMin(arr, n);
    int maxNum = findMax(arr, n);

    cout << "Min array sum: " << sum - maxNum << endl;
    cout << "Max array sum: " << sum - minNum << endl;

    return 0;
}
